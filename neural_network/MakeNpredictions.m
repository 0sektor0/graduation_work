function prediction = MakeNpredictions(input, pcount)
  
size = 10;
n = length(input);
if n < size+1
    error("size mismatch");
end

input = input(n-size+1:n);
prediction = zeros(1,pcount);

for i=1:pcount
    prediction(i)=Nio(input');
    input(1:size-1)=input(2:size);
    input(size)=prediction(1,i);
end

end

