function [is_true, num] = SRcriterian4(map)
    Xj = map.ts;

    n = length(Xj);
    is_true = false;
    num = -1;

    for i = 1:n-13
        last_state = 0;
        if Xj(i) < Xj(i+1)
            last_state = 1;
        elseif Xj(i) > Xj(i+1)
            last_state = -1;
        end
            
        for j = i+1:i+13
            is_true = true;
            num = i;
            
            cur_state = 0;
            if Xj(j) < Xj(j+1)
                cur_state = 1;
            elseif Xj(j) > Xj(j+1)
                cur_state = -1;
            end
            
            if cur_state ~= -last_state || cur_state == 0
                is_true = false;
                num = -1;
                i = j;
                break;
            else
                last_state = cur_state;
            end
        end
        
        if is_true
            return;
        end
    end
end

