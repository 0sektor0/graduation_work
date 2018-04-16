function [is_true, num] = Check4SpecialResons(Xj, sr, lcl, lA, lB, lC, uC, uB, uA)

    %проверка на стандартные критерии
    %проверка на первый стандарнтный критерий
    if sr(1) == 1
        [is_true, num] = SRcriterian1(Xj, lcl, uA);
        
    elseif sr(1) == 2
        [is_true, num] = SRcriterian2(Xj, lC);     
        
    elseif sr(1) == 3
        [is_true, num] = SRcriterian3(Xj);
                
    elseif sr(1) == 4
        [is_true, num] = SRcriterian4(Xj);
        
    elseif sr(1) == 5
        [is_true, num] = SRcriterian5(Xj, lcl, lA, uB, uA);        
        
    elseif sr(1) == 6
        [is_true, num] = SRcriterian6(Xj, lA, lB, uC, uB);         
       
    elseif sr(1) == 7
        [is_true, num] = SRcriterian7(Xj, lB, uC);
                
    elseif sr(1) == 8
        [is_true, num] = SRcriterian8(Xj, lB, uC);
        
    %проверка на особые критерии
    else
        n = length(sr);
        [is_true, num] = SPcriterian(Xj, sr(2:n), lcl, lA, lB, lC, uC, uB, uA);
    end
end

