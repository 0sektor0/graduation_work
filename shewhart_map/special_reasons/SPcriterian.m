function [status, position] = SPcriterian(map, Sp)
    status = false;
    position = -1;

    X = ToSP(map, map.size, map.size);    

    for i = 1 : X.size-Sp.size+1
        if X.ts(i:i+Sp.size-1) == Sp.ts
            status = true;
            position = i;
            return;
        end
    end
end

