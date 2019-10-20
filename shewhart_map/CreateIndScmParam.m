function [X, R] = CreateIndScmParam(Xj, sigma)
[Xucl, Xcl, Xlcl, Rucl, Rcl, Rlcl] = ShewhartIndP(mean(Xj), sigma);
[X, R] = CreateScm(Xucl, Xcl, Xlcl, Rucl, Rcl, Rlcl, Xj);
end

