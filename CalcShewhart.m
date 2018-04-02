%ккш индивидуальных значений
function [Xucl, Xcl, Xlcl, Rucl, Rcl, Rlcl] = CalcShewhart(Xj)
    %cl для X карты
    Xcl = mean(Xj);
    
    %cl для R карты
    n = length(Xj);
    R1 = Xj(1:n-1);
    R2 = Xj(2:n);
    Rcl = mean(abs(R1-R2));
    
    %расчет ucl и lcl для X карты
    E2 = 3 * 0.8865;
    Xucl = Xcl + E2 * Rcl;
    Xlcl = Xcl - E2 * Rcl;
    
    %расчет ecl и lcl для R карты
    D3 = 0;
    D4 = 3.267;
    Rucl = Rcl * D4;
    Rlcl = Rcl * D3;    
end

