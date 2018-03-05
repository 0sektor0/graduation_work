%ккш индивидуальных значений
function [ucl, lcl] = CalcShewhart(Xj, Xcp)
    n = length(Xj);
    
    %расчет среднего скользящего размаха
    i = 1;
    X1 = Xcp(i : n-1); 
    X2 = Xcp(i+1 : n);
    R = mean(abs(X1-X2));
    
    %
    ucl = R;
    lcl = -1;
end

