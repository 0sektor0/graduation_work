function [X, R] = CreateIndScm(Xj)
[Xucl, Xcl, Xlcl, Rucl, Rcl, Rlcl] = ShewhartInd(Xj);
[X, R] = CreateScm(Xucl, Xcl, Xlcl, Rucl, Rcl, Rlcl, Xj);
end



