function [Xucl, Xcl, Xlcl, Rucl, Rcl, Rlcl] = ShewhartIndP(m, s0)
% s0- внутригрупповое стандартноеотклонение (sigma)
% m- истинное среднее процесса (mu)
d2 = 1.128;
D2 = 3.686;
D1 = 0;

Rucl = D2*s0;
Rcl = d2*s0;
Rlcl = D1*s0;

Xucl = m + 3*s0;
Xcl = m;
Xlcl = m - 3*s0;
end

