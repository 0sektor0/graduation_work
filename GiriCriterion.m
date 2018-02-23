function IsNormal = GiriCriterion(sample, table_giri)
    xavg = mean(sample);
    n = length(sample);
    
    s = (sample - xavg);
    s =  sqrt(sum(s .* s) / (n - 1));
    
    d = sum(sample - xavg) / (n * s);
    
    %тут должно быть определение результата по таблице
    IsNormal = true;
end