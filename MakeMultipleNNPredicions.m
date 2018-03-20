function prediction = MakeMultipleNNPredicions(input, predictions_count)

delay = 5;    
if length(input) < delay+1
    error("size mismatch");
end

predictions_count = predictions_count + delay + 1;
prediction = zeros(1, predictions_count);
prediction(1: delay+1) = input(1: delay+1);

for i =1 : predictions_count-delay+1
inp_delay = prediction(i : i+delay-1);
out_delay = prediction(i+1 : i+delay);

prediction(1, i+delay+1) = SimulateNarxNetwork(0, 0, inp_delay, out_delay);
end

end

