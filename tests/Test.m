addpath('./noramality_criterians', './shewhart_map', './shewhart_map/special_reasons', './neural_network', './data', './tests')



data = LoadData();
%data preparation
D = num2cell(data);
X = D(1:4000);
T = D(2:4001);
X = X(1:1000);
T = T(1:1000);
dl = 2;

%Creating network
net = narxnet(1:dl,1:dl,50);

net.trainParam.goal = 1e-10;
net.trainParam.epochs = 1000000;
net.trainParam.min_grad = 1e-10;
net.trainParam.max_fail = 1000000;

net.divideParam.trainRatio = 70/100;
net.divideParam.valRatio = 15/100;
net.divideParam.testRatio = 15/100;

net.performFcn = 'mse';  % Mean Squared Error

%Train a network, and simulate it on the first observations
[Xs,Xi,Ai,Ts] = preparets(net,X,{},T);
net = train(net,Xs,Ts,Xi,Ai);

%test network
x1 = X(1:50);
t1 = T(1:50);
x2 = X(51:151);

neto = openloop(net);
[x,xi,ai,t] = preparets(net,x1,{},t1);
[y1,xf,af] = net(x,xi,ai);

[netc,xi,ai] = closeloop(net,xf,af);
[y2,xf,af] = netc(x2,xi,ai);

TS = size(y2,2);
plot(1:TS,cell2mat(X(51:151)),'b',1:TS,cell2mat(y2),'r')
















