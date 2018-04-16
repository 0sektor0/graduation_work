function [is_true, num] = SRcriterian6(Xj, lA, lB, uC, uB)
    is_true = false;
    num = -1;
    n = length(Xj);
    
    for i=1:n-4
        up_counter = 0;
        down_counter = 0;
        
        for j=i:i+4
            if Xj(j) > lA && Xj(j) <= lB
                down_counter = down_counter + 1;
            elseif Xj(j) < uB && Xj(j) >=uC
                up_counter = up_counter + 1;
            end
        end
        
        if up_counter == 4 || down_counter == 4
            is_true = true;
            num = i;
            return;
        end
    end
end

