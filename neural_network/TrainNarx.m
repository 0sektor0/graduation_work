data = LoadData();
%data = data(2:4002)-data(1:4001); 
D = num2cell(data);

X = D(1:3000);
T = D(2:3001);
X = X(1:2000);
T = T(1:2000);

%narx creating
net = narxnet(1:5,1:5,20);
net.trainFcn='trainbr'; 

net.trainParam.max_fail = 10;
net.trainParam.goal = 1e-10;
net.trainParam.epochs = 1000;
net.trainParam.min_grad = 1e-10;
net.trainParam.max_fail = 1000;

net.divideParam.trainRatio = 70/100;
net.divideParam.valRatio = 15/100;
net.divideParam.testRatio = 15/100;
net.performFcn = 'mse';  % Mean Squared Error

%narx training
[Xs,Xi,Ai,Ts] = preparets(net,X,{},T);
net = train(net,Xs,Ts,Xi,Ai);

%generating network function
%genFunction(net,'Nrx','MatrixOnly','yes');

%test
[Xs,Xi,Ai,Ts] = preparets(net,X(1:500),{},T(1:500));
[Y,Xf,Af] = net(Xs,Xi,Ai);
[netc,Xic,Aic] = closeloop(net,Xf,Af);

Xnew = X(501:701);
y2 = netc(Xnew,Xic,Aic);

TS = size(y2,2);
plot(1:TS,cell2mat(T(501:701)),'b',1:TS,cell2mat(y2),'r')




