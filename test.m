load('data/data.mat', 'vector_source')

%example = GetSample(example, 1 ,5);
%example = [1, 2, 2, 3];
%example = [-1, 0, 1, 2, 3, 5, 6, 7, 10, 15];
%example = [0, 0, 0, 0, 0, 0];

vector_source = rand(1, 1000);
n = length(vector_source);

subplot(2, 1, 1);
hist(vector_source);
subplot(2, 1, 2);
hist(boxcox(vector_source'));
t = CheckNormality(boxcox(vector_source')')

for i = 1 : n
    sample = GetSample(vector_source, 1, i);
    t = CheckNormality(sample)
    
    if ~t
        sample = boxcox(sample')';
        t = CheckNormality(sample)
    end
end

example = [4.9, 5.0, 6.5, 10.9, 11.0, 11.4, 12.7, 13.0, 14.0, 14.5];
t = CheckNormality(example);
example = boxcox(example')';