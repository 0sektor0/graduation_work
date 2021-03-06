function IsNormal = HegazyGreenCriterion(Xj, alpha)
    if size(Xj, 1) ~= 1
        error('size mismatch')
    end 
    
    %проверка на наличие известной апроксимации критических величин
    if ~(alpha == 0.01 || alpha == 0.05)
        error("invalid parametr alpha")
    end
    
    %расчет параметров для вычисления статистик T1 и T2 
    Xcp = mean(Xj);
    n = length(Xj);
    
    s = (Xj - Xcp);
    s =  sqrt(sum(s .* s) / (n - 1));
    
    z = (Xj - Xcp) / s;
    
    %вектор мат ожидания порядковой статистики 
    nu = zeros(1, n);
    %надо заменить на более изящную конструкцию
    for i = 1 : n
        buf = n + 1;
        nu(i) = 4.91 * ((i/buf)^0.14 - ((buf - i)/(buf))^0.14);
    end
    
    %расчет статистик 
    buf = z - nu;
    t1 = sum(abs(buf)) / n;
    t2 = sum(buf .* buf) / n;

    %расчет критических значений в соответствие с известными апроксимациями
    t1_crit = 0;
    t2_crit = 0;
    
    if alpha == 0.01
        t1_crit = 0.7195 - 0.1751 * log(n) + 0.0108 * log(n)^2;
        t2_crit = 0.0178 + 2.8736/n - 8.2894/n^2;
    end
    
    if alpha == 0.05
        t1_crit = 0.6027 - 0.1481 * log(n) + 0.0090 * log(n)^2;
        t2_crit = 0.0126 + 1.9227/n - 5.00677/n^2;
    end
    
    %определение нормальности выборки
    if t1 < t1_crit && t2 < t2_crit
        IsNormal = true;
    else
        IsNormal = false;
    end
end