function IsNormal = GiriCriterion(Xj, alpha)
    if size(Xj, 1) ~= 1
        error('size mismatch')
    end 
    
    %проверка на наличие известной апроксимации критических величин
    if ~(alpha == 0.05)
        error("invalid parametr alpha")
    end
    
    %расчет параметров, необходимых для дальнейших вычмслений
    Xcp = mean(Xj);
    n = length(Xj);
    dsa = Xj - Xcp; %the Difference of the Sample and its Average. DSA 
      
    %расчет статистики
    s =  sqrt(sum(dsa .* dsa)) / (n - 1);    
    d = sum(abs(dsa)) / (n * s);
    
    %расчет мат ожид и дисперсии в соответсвие с их апроксимациями
    exp = 0.797885 + 0.199471/n + 0.024934/n^2 - 0.031168/n^3 - 0.008182/n^4;
    disp = 0.045070/n - 0.124648/n^2 + 0.084859/n^3 + 0.006323/n^4;
    
    %определене квантиля норм распределения заданного уровня
    u = 0;
    if alpha == 0.05
        u = 1.645; %альфа квантиль стд нормального распределения уровня значимости 0.05 
    end
    
    %определение нормальности распределения
    d1 = exp + sqrt(disp)*(-u);
    d2 = exp + sqrt(disp)*u;
    
    if d>d1 && d<d2
        IsNormal = true;
    else
        IsNormal = false;
    end
end