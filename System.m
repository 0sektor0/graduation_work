addpath('tests','shewhart_map','shewhart_map/special_reasons','noramality_criterians','neural_network','data');

data = LoadData();
n = length(data);
sl = 60;
ofs = 472;
%sl = 30;
%ofs = 452;
Xj = data(ofs:ofs-1+sl);


sr = [];
[st,preds,nsr] = ProcessTsSr(Xj,2000,sr,10);
[st,preds] = ProcessTs(Xj,20);

TS = length(preds)-1;
plot(ofs:ofs+TS,preds,1:n,data)