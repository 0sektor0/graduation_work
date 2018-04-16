function [is_true, num] = SPcriterian(Xj, Sp, lcl, lA, lB, lC, uC, uB, uA)
    is_true = false;
    num = -1;

    X = ToSP(Xj, lcl, lA, lB, lC, uC, uB, uA);
    nx = length(X);
    ns = length(Sp);
    
    for i=1:nx-ns+1
        if X(i:i+ns-1) == Sp
            is_true = true;
            num = i;
            return;
        end
    end
end

