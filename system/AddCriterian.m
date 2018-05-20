function [criterians] = AddCriterian(dest,new_criterians)
    n = length(new_criterians);
    
    for i = 1:n
        if(new_criterians(i).type == -1)
            for j = 1 : length(dest)
                if length(new_criterians(i).ts) == length(dest(j).ts)
                    if new_criterians(i).ts == dest(j).ts
                        criterians = dest;
                        return
                    end
                end
            end
            criterians = [dest, new_criterians(i)];
        else
            criterians = dest;
        end
    end
    
end

