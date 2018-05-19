function [is_true, num] = SRcriterian8(map)
    Xj = map.ts; 
    lC = map.lb;
    uC = map.uc;

    is_true = false;
    num = -1;
    n = length(Xj);
    
    for i=1:n-7
        counter = 0;
        
        for j=i:i+7
            if Xj(j) < lC || Xj(j) > uC
                counter = counter + 1;
            else
                break;
            end
        end
        
        if counter == 8
            is_true = true;
            num = i;
            return;
        end
    end
end

