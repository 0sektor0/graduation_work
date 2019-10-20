D = LoadData('data/MFON_160101_180101_F.txt');

T = D(300:800);
net = narnet(1:5,20);
[Xs,Xi,Ai,Ts] = preparets(net,{},{},num2cell(T));
net.trainParam.max_fail = 60000;
net.trainParam.epoch = 60000;
net = train(net,Xs,Ts,Xi,Ai);
%view(net)

[Y,Xf,Af] = net(Xs,Xi,Ai);
perf = perform(net,Ts,Y)

%prediction
[netc,Xic,Aic] = closeloop(net,Xf,Af);
y2 = netc(cell(0,50),Xic,Aic)

plot(1:551,D(300:850), 502:551,cell2mat(y2))

save net
