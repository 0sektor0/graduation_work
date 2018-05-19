function [is_true, num] = CheckMap(sr, map)
    %map.uB  5 sigma
    %   верхняя область В
    %map.uc  4 sigma
    %   верхняя область С
    %lC  3 sigma
    %   нижняя область С
    %map.lb  2 sigma
    %   нижняя область В
    %map.la  1 sigma
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
        [is_true, num] = SRcriterian1(map);
        
    %9 точек подряд в зоне С или по одну сторону от центральной линии
    elseif sr(1) == 2
        [is_true, num] = SRcriterian2(map);     
        
    %6 возрастающих или убывающих точек подряд
    elseif sr(1) == 3
        [is_true, num] = SRcriterian3(map);
                
    %14 попеременно возрастающих или убывающих точек подряд
    elseif sr(1) == 4
        [is_true, num] = SRcriterian4(map);
        
    %2 из 3 последовательных точек в зоне А или вне ее
    elseif sr(1) == 5
        [is_true, num] = SRcriterian5(map);        
        
    %4 из 5 последовательных точек в В или вне ее
    elseif sr(1) == 6
        [is_true, num] = SRcriterian6(map);         
       
    %15 последовательных точек в зоне С выше или ниже центральной линии
    elseif sr(1) == 7
        [is_true, num] = SRcriterian7(map);
                
    %8 последовательных точек по обеим сторонам центральной линии и ни
    %одной в зоне С
    elseif sr(1) == 8
        [is_true, num] = SRcriterian8(map);
        
    %проверка на особые критерии
    else
        n = length(sr);
        [is_true, num] = SPcriterian(map.ts, sr(2:n), map.lcl, map.la, map.lb, lC, map.uc, map.uB, map.uA);
    %end
end