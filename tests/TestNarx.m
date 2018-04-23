data = LoadData();
[X,T] = SplitData(data,10);

yp = Nio2(X);
%yp = net(X);

yp = yp(100:200);
TS = size(yp,2);
subplot(2,1,1);
plot(1:TS,T(100:200),'b',1:TS,yp,'r')

subplot(2,1,2);
plot(1:TS, T(100:200),'b')