data = LoadData();
[X,T] = SplitData(data,10);
n = length(data);

y2 = Nio(X);
TS = length(y2);

sl = 60;
ofs = 472;
Xj = data(ofs:ofs-1+sl);

plot(1:499,y2(2:500),'r',1:499,T(1:499),'b');