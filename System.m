addpath('tests','shewhart_map','shewhart_map/special_reasons','noramality_criterians','neural_network','data','gui','system');

data = LoadData('data/MFON_160101_180101_F.txt');
n = length(data);
sl = 60;
ofs = 472;
%sl = 60;
%ofs = 472;
Xj = data(ofs:ofs-1+sl);

%[st,preds,nsr] = ProcessTsSr(Xj,2000,sr,10,0.01);
[st,preds] = ProcessTs(Xj,2000,0.01);

TS = length(preds)-1;
plot(ofs:ofs+TS,preds,1:n,data)

disp(st)