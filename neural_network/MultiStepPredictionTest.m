D = LoadData('data/mfon-all.txt');

T = D(300:800);
net = narnet(1:10,10);
[Xs,Xi,Ai,Ts] = preparets(net,{},{},num2cell(T));
net.trainParam.max_fail = 10;
net = train(net,Xs,Ts,Xi,Ai);
%view(net)

[Y,Xf,Af] = net(Xs,Xi,Ai);
perf = perform(net,Ts,Y)

%prediction
[netc,Xic,Aic] = closeloop(net,Xf,Af);
y2 = netc(cell(0,50),Xic,Aic)

plot(1:551,D(300:850), 502:551,cell2mat(y2))

trainedNarnet = net;
save trainedNarnet;