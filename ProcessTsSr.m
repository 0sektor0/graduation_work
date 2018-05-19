function [st,predictions,newSystemCriterians] = ProcessTsSr(Xj,predictionsCount,systemCriterians,criterianSize)
st = 0;
predictions = [];
newSystemCriterians = [];

%normal distribution check
dist = CheckNd(Xj);
if ~dist
    Xj = boxcox(0.05, Xj')';
    dist = CheckNd(Xj);
    
    if ~dist
        st = 1;
        return;
    end
end

%создаем карты шухкарта
[X, R] = CreateIndScmParam(Xj, 0.01);
state = false;

%проверяем карту на 8 основных критериев
for j=1:8
    [is_uc, position] = CheckMap(struct('type',j,'ts',[]), X)
    state = state || is_uc;
    
    if is_uc
       newSystemCriterians = [newSystemCriterians, [ToSP(X, position, criterianSize)]];
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
    st = 2;
    return;
end

end