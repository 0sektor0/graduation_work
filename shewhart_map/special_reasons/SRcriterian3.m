function [is_true, num] = SRcriterian3(Xj)
    n = length(Xj);

    for i = 1:n-6
        up_counter = 0;
        down_counter = 0;
            
        for j = i:i+4
            %cчитаем подъемы
            if Xj(j) < Xj(j+1)
                up_counter = up_counter + 1;
            else
                down_counter = down_counter + 1;
            end
        end
               
        if up_counter == 5 || down_counter == 5
            is_true = true;
            num = i;
            return
        else 
            is_true = false;
            num = -1;
        end
    end
end

