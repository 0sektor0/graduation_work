data = LoadData();
%data preparation
D = num2cell(data);
X = D(1:4000);
T = D(2:4001);
Xnew = X(3001:3100);
X = X(1:3000);
T = T(1:3000);

%narx creating
net = narxnet(1:2,1:2,10);
net.trainFcn='trainbr'; 

net.trainParam.max_fail = 10;
net.trainParam.goal = 1e-10;
net.trainParam.epochs = 1000;
net.trainParam.min_grad = 1e-10;

net.divideFcn = 'dividerand';  % Divide data randomly
net.divideMode = 'time';  % Divide up every sample

net.divideParam.trainRatio = 70/100;
net.divideParam.valRatio = 15/100;
net.divideParam.testRatio = 15/100;

net.performFcn = 'mse';  % Mean Squared Error

%narx training
[Xs,Xi,Ai,Ts] = preparets(net,X,{},T);
net = train(net,Xs,Ts,Xi,Ai);

%generating network function
genFunction(net,'Nrx','MatrixOnly','yes');

%test
[Y,Xf,Af] = net(Xs,Xi,Ai);
perf = perform(net,Ts,Y);
[netc,Xic,Aic] = closeloop(net,Xf,Af);
y2 = netc(Xnew,Xic,Aic)

TS = size(y2,2);
plot(1:TS,cell2mat(Xnew),'b',1:TS,cell2mat(y2),'r')




