function [is_true, num] = Check4SpecialResons(Xj, sr, lcl, lA, lB, lC, uC, uB, uA)
    %uA (Ucl) 6 sigma
    %   верхняя область А 
    %uB  5 sigma
    %   верхняя область В
    %uC  4 sigma
    %   верхняя область С
    %lC  3 sigma
    %   нижняя область С
    %lB  2 sigma
    %   нижняя область В
    %lA  1 sigma
    %   нижняя область А
    %Lcl 0 sigma

    %sr представляет из себя вектор, где первое значение это тип критерия
    %а остальные значение это паттерн критерия, если используется 
    %нестандартный критерий (sr(1)<1 || sr(1)>8)
    %паттерн нестандарного критерия представляет собой вектор, где каждый
    %элемент указывает на одну из 6 зон, в которой находится точка

    %проверка на стандартные критерии
    
    %одна точка вне зон А
    if sr(1) == 1
        [is_true, num] = SRcriterian1(Xj, lcl, uA);
        
    %9 точек подряд в зоне С или по одну сторону от центральной линии
    elseif sr(1) == 2
        [is_true, num] = SRcriterian2(Xj, lC);     
        
    %6 возрастающих или убывающих точек подряд
    elseif sr(1) == 3
        [is_true, num] = SRcriterian3(Xj);
                
    %14 попеременно возрастающих или убывающих точек подряд
    elseif sr(1) == 4
        [is_true, num] = SRcriterian4(Xj);
        
    %2 из 3 последовательных точек в зоне А или вне ее
    elseif sr(1) == 5
        [is_true, num] = SRcriterian5(Xj, lcl, lA, uB, uA);        
        
    %4 из 5 последовательных точек в В или вне ее
    elseif sr(1) == 6
        [is_true, num] = SRcriterian6(Xj, lA, lB, uC, uB);         
       
    %15 последовательных точек в зоне С выше или ниже центральной линии
    elseif sr(1) == 7
        [is_true, num] = SRcriterian7(Xj, lB, uC);
                
    %8 последовательных точек по обеим сторонам центральной линии и ни
    %одной в зоне С
    elseif sr(1) == 8
        [is_true, num] = SRcriterian8(Xj, lB, uC);
        
    %проверка на особые критерии
    else
        n = length(sr);
        [is_true, num] = SPcriterian(Xj, sr(2:n), lcl, lA, lB, lC, uC, uB, uA);
    end
end

