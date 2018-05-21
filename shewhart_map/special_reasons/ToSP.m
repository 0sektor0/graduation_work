function newCriterian = ToSP(map, position, size)
    start = position - size + 1;
    if start < 1
        newCriterian = struct('type',0,'ts',map.ts,'size',length(map.ts));
        return
    end

    Xj = map.ts(start:position);
    lcl = map.lcl;
    lA = map.la; 
    lB = map.lb;
    lC = map.lc;
    uC = map.uc;
    uB = map.ub;
    uA = map.ua;

    n = length(Xj);
    ts = zeros(1, n);
    
    for i=1:n
        if Xj(i) < lcl
            ts(1, i) = 0;
        elseif Xj(i) >= lcl && Xj(i) < lA
            ts(1, i) = 1;
        elseif Xj(i) >= lA && Xj(i) < lB
            ts(1,i) = 2;
        elseif Xj(i) >= lB && Xj(i) < lC
            ts(1,i) = 3;
        elseif Xj(i) >= lC && Xj(i) < uC
            ts(1,i) = 4;
        elseif Xj(i) >= uC && Xj(i) < uB
            ts(1,i) = 5;
        elseif Xj(i) >= uB && Xj(i) <= uA
            ts(1,i) = 6;
        elseif Xj(i) >= uA
            ts(1,i) = 7;
        end
    end

    newCriterian = struct('type',-1,'ts',ts,'size',length(ts));
end

