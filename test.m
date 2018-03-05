%example = GetSample(example, 1 ,5);
%example = [1, 2, 2, 3];
%example = [-1, 0, 1, 2, 3, 5, 6, 7, 10, 15];
%example = [0, 0, 0, 0, 0, 0];
Xj = [4.9, 5.0, 6.5, 10.9, 11.0, 11.4, 12.7, 13.1, 14.0, 14.5];

vector_source = rand(1, 50);
vector_source = vector_source + abs(min(vector_source));
n = length(vector_source);

%vector_source = [1,2,2,3];
vector_source = vector_source + max(vector_source);
vector_source = boxcox(vector_source')';

t = ShapiroWeakCriterion(vector_source);
t = t || HegazyGreenCriterion(vector_source, 0.05);
t = t || GiriCriterion(vector_source, 0.05);
t = t || EppsPallyCriterion(vector_source, 0.05)

ShowPlot(vector_source);