function [is_true, num] = SRcriterian2(Xj,cl)
    is_true = false;
    num = -1;
    n = length(Xj);
    
    for i=1:n-8
        up_counter = 0;
        down_counter = 0;
        
        for j=i:i+8
            if Xj(j) > cl
                up_counter = up_counter + 1;
            elseif Xj(j) < cl
                down_counter = down_counter + 1;
            else
                down_counter = down_counter + 1;
                up_counter = up_counter + 1;
            end
        end
        
        if up_counter == 9 || down_counter == 9
            is_true = true;
            num = i;
            return;
        end
    end
end

