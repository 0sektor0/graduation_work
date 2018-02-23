function IsNormal = ShapiroWeakCriterion(sample) %для alpha = 0.05
    %расчет параметров для вычисления статистики W
    n = length(sample); 
    m = n/2; 
    xavg = mean(sample);
        
    x = fliplr(sample); 
    k = 1:m; 
    zk = (n-2.*k+1) / (n-0.5); 
    
    a0 = 0.899 / ((n-2.4)^0.4162 - 0.02); 
    ak = a0.*(zk + 1483./(3-zk).^10.845 + 71.6*10^-10./(1.1-zk).^8.26); 
    
    %расчет статистики
    b=sum(ak.*(x(1:m)-sample(1:m))).^2;
    s2 = sum((sample-xavg).^2); 
    w = (1-0.6695 / n^0.6518) * s2/b;

    if(w < 1)
        IsNormal = true;
    else
        IsNormal = false;
    end
end

