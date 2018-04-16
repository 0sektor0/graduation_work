function [is_true, num] = SRcriterian5(Xj, lcl, lA, uB, ucl)
    is_true = false;
    num = -1;
    n = length(Xj);
    
    for i=1:n-2
        up_counter = 0;
        down_counter = 0;
        
        for j=i:i+2
            if Xj(j) > lcl && Xj(j) <= lA
                down_counter = down_counter + 1;
            elseif Xj(j) < ucl && Xj(j) >=uB
                up_counter = up_counter + 1;
            end
        end
        
        if up_counter == 2 || down_counter == 2
            is_true = true;
            num = i;
            return;
        end
    end
end

