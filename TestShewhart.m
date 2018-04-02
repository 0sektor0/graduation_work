%Xj = [4.9, 5.0, 6.5, 10.9, 11.0, 11.4, 12.7, 13.1, 14.0, 14.5];
Xj = rand(1, 500);

%[Xucl, Xcl, Xlcl, Rucl, Rcl, Rlcl] = ShewhartInd(Xj);
[Xucl, Xcl, Xlcl, Rucl, Rcl, Rlcl] = ShewhartIndP(0.6, 0.3);

n = length(Xj);
YR = abs(Xj(1:n-1) - Xj(2:n));
YRcl = Rcl*ones(1, n-1);
YRucl = Rucl*ones(1, n-1);
YRlcl = Rlcl*ones(1, n-1);

YXcl = Xcl*ones(1, n);
YXucl = Xucl*ones(1, n);
YXlcl = Xlcl*ones(1, n);

XR = 1 : 1 : n-1;
XX = 1 : 1 : n;

subplot(3,1,1);
%R карта
plot(XR, YR, XR, YRucl, XR, YRcl, XR, YRlcl);

subplot(3,1,2);
%X карта
plot(XX, Xj, XX, YXucl, XX, YXcl, XX, YXlcl);

subplot(3, 1, 3)
Xn = boxcox(Xj);
histogram(Xn);

t1 = EppsPallyCriterion(Xj, 0.05);
t2 = EppsPallyCriterion(Xn, 0.05);
% t = t || HegazyGreenCriterion(vector_source, 0.05);
% t = t || GiriCriterion(vector_source, 0.05);
% t = t || EppsPallyCriterion(vector_source, 0.05);
