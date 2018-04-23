fData = fopen('data/MFON_160101_180101_F.txt');
if fData==-1
    error('file does not exist');
end
while feof(fData) == 0
    line = fgetl(fData);
    data = str2num(line);
end

D = num2cell(data);
n = length(data);
data = data(2:n) - data(1:n-1);

[X,T] = SplitData(data(1:1000),10);
X = tonndata(X,true,true);
T = tonndata(T,true,true);

inputs  = [1:10]' % input vector (6-dimensional pattern)
outputs = [1]' % corresponding target output vector

% create network
net = network( ...
    1,          ... % numInputs,    number of inputs,
    2,          ... % numLayers,    number of layers
    [1; 0],     ... % biasConnect,  numLayers-by-1 Boolean vector,
    [1; 0],     ... % inputConnect, numLayers-by-numInputs Boolean matrix,
    [0 0; 1 0], ... % layerConnect, numLayers-by-numLayers Boolean matrix
    [0 1]       ... % outputConnect, 1-by-numLayers Boolean vector
);

% number of hidden layer neurons
net.layers{1}.size = 5;
% hidden layer transfer function
net.layers{1}.transferFcn = 'logsig';

net = configure(net,inputs,outputs);
view(net);

% network training
net.trainFcn = 'traingdm';
net.performFcn = 'mse';

net.divideFcn = 'dividerand';  % Divide data randomly
net.divideMode = 'time';  % Divide up every sample

net.trainParam.goal = 1e-10;
net.trainParam.epochs = 100000;
net.trainParam.min_grad = 1e-10;
net.trainParam.max_fail = 1000;

net.divideParam.trainRatio = 70/100;
net.divideParam.valRatio = 15/100;
net.divideParam.testRatio = 15/100;

net = train(net,X,T);

















