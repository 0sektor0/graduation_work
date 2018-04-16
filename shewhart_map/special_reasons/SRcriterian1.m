function [is_true, num] = SRcriterian1(Xj, lcl, uA)
    is_true = false;
    num = -1;
    n = length(Xj);
    
    for i=1:n
        if Xj(i) > uA || Xj(i) < lcl
            is_true = true;
            num = i;
            return;
        end
    end
end

