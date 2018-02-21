function IsTrue = HegazyGreenCriterion(sample)
    xavg = mean(sample);
    sample_length = length(sample);
    
    s = (sample - xavg);
    %s = s .* s
    %s = sum(s)
    %s = s / (length(sample) - 1)
    %s = sqrt(s)
    s =  sqrt(sum(s .* s) / (sample_length - 1));
    
    z = (sample - xavg) / s;
    
    nu(1 : sample_length) = 0;
    %надо заменить на более изящную конструкцию
    for i = 1 : sample_length
        buf = sample_length + 1;
        nu(i) = 4.91 * ((i/buf)^0.14 - ((buf - i)/(buf))^0.14);
    end
    
    buf = z - nu;
    t1 = sum(abs(buf)) / sample_length;
    t2 = sum(z .* z) / sample_length;

    IsTrue = true;
end

