data = LoadData();
n = length(data);
sl = 60;
ofs = 472;
%sl = 30;
%ofs = 452;
Xj = data(ofs:ofs-1+sl);

sr = [];
[st,preds,nsr] = ProcessTs(Xj,20,sr,10);
[st,preds,nsr] = ProcessTs(Xj,20,nsr,10);
a=1;