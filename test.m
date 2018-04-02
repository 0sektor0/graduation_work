Xj = [4.9, 5.0, 6.5, 10.9, 11.0, 11.4, 12.7, 13.1, 14.0, 14.5];

[Xucl, Xcl, Xlcl, Rucl, Rcl, Rlcl] = CalcShewhart(Xj)

n = length(Xj);
YR = Xj(1:n-1) - Xj(2:n);
YRcl = Rcl*ones(1, n-1);
YRucl = Rucl*ones(1, n-1);
YRlcl = Rlcl*ones(1, n-1);

XR = 1 : 1 : n-1;
plot(XR, YR, XR, YRucl, XR, YRcl, XR, YRlcl);

% vector_source = rand(1, 50);
% vector_source = vector_source + abs(min(vector_source));
% n = length(vector_source);
% 
% vector_source = vector_source + max(vector_source);
% vector_source = boxcox(vector_source')';
% 
% t = ShapiroWeakCriterion(vector_source);
% t = t || HegazyGreenCriterion(vector_source, 0.05);
% t = t || GiriCriterion(vector_source, 0.05);
% t = t || EppsPallyCriterion(vector_source, 0.05);
% 
% res = GetSample(Xj, 1, 5);
% res = MakeMultipleNNPredicions(Xj, 2);
% %res = CalcShewhart(Xj, 1.0);
% 
% ShowPlot(vector_source);