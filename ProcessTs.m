function [st,preds,nsr] = ProcessTs(Xj,pc,sr,nsrl)

%st - status
%st = 0 ok
%st = 1 not normal distribution
%st = 2 error in shewhart maps

%preds - predictions
%pc - predictions count

%special reason is matrix where columns is sr
%nsr - new special reason
%nsrl - nsr len

st = 0;
preds = [];
nsr = [];

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

%shewharts map criterian check
[Xucl, Xcl, Xlcl, Rucl, Rcl, Rlcl] = ShewhartIndP(mean(Xj),0.01);
[lA, lB, lC, uC, uB, uA] = CalcShBorders(Xucl,Xcl,Xlcl);

state = false;
for j=1:8
    [is_uc, num] = Check4SpecialResons(Xj, [floor(j)], Xlcl, lA, lB, lC, uC, uB, uA);
    state = state || is_uc;
    
    if is_uc
       bg = num-nsrl;
       if bg < 1
           bg = 1;
       end
       
       nsrv = ToSP(Xj(bg:num), Xlcl, lA, lB, lC, uC, uB, uA);
       nsrvl = length(nsrv);
       if nsrvl < nsrl
           nsrv = [zeros(1,nsrl-nsrvl+1)-1,nsrv];
       end
       nsr = [nsr, nsrv'];
    end
end

for j=1:size(sr,2)
    [is_uc] = Check4SpecialResons(Xj, [9,sr(:,j)'], Xlcl, lA, lB, lC, uC, uB, uA);
    state = state || is_uc;
end

%predictions
if ~state
    preds = MakeNpredictions(Xj,pc);
else
    st = 2;
    return;
end

end

