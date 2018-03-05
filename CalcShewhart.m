%ккш индивидуальных значений
function [ucl, lcl] = CalcShewhart(Xj, Xcp)
    n = length(Xj);
    
    %расчет среднего скользящего размаха
    X1 = Xcp(1 : n-1); 
    X2 = Xcp(2 : n);
    R = mean(abs(X1-X2));
    
    %
end

