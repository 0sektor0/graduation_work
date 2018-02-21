load data vector_source;
vector_sample = GetSample(vector_source, 1, 3);
mean(vector_sample);

t = HegazyGreenCriterion([1, 2, 3])