function ShowPlot(Xj)
    n = length(Xj);
    X = 0 : n-1;
    
    m = 1 + 3.322*log10(n);
    m=round(m);
    
    subplot(2,1,1);
    plot(X, Xj);
    
    subplot(2,1,2);
    plot(X, Xj);
end

