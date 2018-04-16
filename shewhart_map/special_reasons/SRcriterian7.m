function [is_true, num] = SRcriterian7(Xj, lC, uC)
    is_true = false;
    num = -1;
    n = length(Xj);
    
    for i=1:n-14
        counter = 0;
        
        for j=i:i+14
            if Xj(j) >= lC && Xj(j) <= uC
                counter = counter + 1;
            else
                break;
            end
        end
        
        if counter == 15 || counter == 15
            is_true = true;
            num = i;
            return;
        end
    end
end

