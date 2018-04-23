[X,T] = SplitData(data,10);

%yp = Nio(X);
yp = net(X);

TS = size(yp,2);
plot(1:TS,T,'b',1:TS,yp,'r')