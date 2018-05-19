function [criterians] = AddCriterian(dest,criterian)
if(criterian.type == -1)
    for i = 1 : length(dest)
        if criterian.ts == dest(i).ts
            criterians = dest;
            return
        end
    end
    criterians = [dest, criterian];
else
    criterians = dest;
end
end

