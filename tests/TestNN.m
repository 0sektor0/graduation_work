fData = fopen('data/MFON_160101_180101_F.txt');
if fData==-1
    error('file does not exist');
end
while feof(fData) == 0
    line = fgetl(fData);
    data = str2num(line);
end

D = num2cell(data);
n = length(data);
data = data(2:n) - data(1:n-1);

TS = 50;
td = MakeNpredictions(data(1:11), TS);

subplot(2,1,1);
plot(1:TS,td);

subplot(2,1,2);
plot(1:TS,data(12:61));

[x,t] = SplitData(data(1:15),10);
y = Nio2(data(1:10)')
data(11)

