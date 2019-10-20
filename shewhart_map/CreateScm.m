function [X, R] = CreateScm(Xucl, Xcl, Xlcl, Rucl, Rcl, Rlcl, Xj)

X = struct('ucl', Xucl, ...
           'lcl', Xlcl, ... 
           'cl', Xcl, ...
           'la', 0, ...
           'lb', 0, ...
           'lc', 0, ...
           'ua', 0, ...
           'ub', 0, ...
           'uc', 0, ...
           'ts', [], ...
           'size', 0);
       
R = struct('ucl', Rucl, ...
           'lcl', Rlcl, ... 
           'cl', Rcl, ...
           'la', 0, ...
           'lb', 0, ...
           'lc', 0, ...
           'ua', 0, ...
           'ub', 0, ...
           'uc', 0, ...
           'ts', [], ...
           'size', 0);

[X.la, X.lb, X.lc, X.uc, X.ub, X.ua] = CalcShBorders(X.ucl,X.cl,X.lcl);
[R.la, R.lb, R.lc, R.uc, R.ub, R.ua] = CalcShBorders(R.ucl,R.cl,R.lcl);

X.ts = Xj;
X.size = length(X.ts);

n = length(Xj);
R.ts = abs(Xj(1:n-1) - Xj(2:n));  
R.size = length(R.ts);     
end
