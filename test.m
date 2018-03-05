%example = GetSample(example, 1 ,5);
%example = [1, 2, 2, 3];
%example = [-1, 0, 1, 2, 3, 5, 6, 7, 10, 15];
%example = [0, 0, 0, 0, 0, 0];
Xj = [4.9, 5.0, 6.5, 10.9, 11.0, 11.4, 12.7, 13.1, 14.0, 14.5];

vector_source = rand(1, 100);
vector_source = vector_source + abs(min(vector_source));
n = length(vector_source);

%vector_source = [1,2,2,3];
vector_source = vector_source + max(vector_source);
vector_source = boxcox(vector_source')';

t = CheckNormality(vector_source)
normal_vector = boxcox(vector_source')';
t = CheckNormality(normal_vector);

m = 1 + 3.322*log10(n);
m=round(m);
histfit(normal_vector, m);