function [st,predictions,newSystemCriterians] = ProcessTsSr(Xj,predictionsCount,systemCriterians,criterianSize,sigma)
st = struct('type',0,'text','ok');
predictions = [];
newSystemCriterians = [];

%normal distribution check
dist = CheckNd(Xj);
if ~dist
    Xj = boxcox(0.05, Xj')';
    dist = CheckNd(Xj);
    
    if ~dist
        st = struct('type',1,'text','not normal distribution');
        return;
    end
end

%создаем карты шухкарта
[X, R] = CreateIndScmParam(Xj, sigma);
state = false;

%проверяем карту на 8 основных критериев
for j=1:8
    [is_uc, position] = CheckMap(struct('type',j,'ts',[]), X)
    state = state || is_uc;
    
    if is_uc
        newCriterian = [ToSP(X, position, criterianSize)];
        if(newCriterian.type ~= 0)
            newSystemCriterians = [newSystemCriterians, newCriterian];
        end
    end
end

%проверяем карту на системные криетрии
for j= 1 : length(systemCriterians)
    [is_uc] = CheckMap(systemCriterians(j),X);
    state = state || is_uc;
end

%predictions
if ~state
    predictions = MakeNpredictions(Xj, predictionsCount);
else
    st = struct('type',2,'text','process unstable');
    return;
end

end