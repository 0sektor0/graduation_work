%считываем временной ряд
fData = fopen('data/MFON_160101_180101_F.txt');
if fData==-1
    error('file does not exist');
end
while feof(fData) == 0
    line = fgetl(fData);
    data = str2num(line);
end

data_len = length(data);
Xj = data(1, 1:1000);

subplot(2,1,1);
dist = CheckNd(Xj);
histogram(Xj);

subplot(2,1,2);
if dist == false
    Xj = boxcox(0.05, Xj);
    dist = CheckNd(Xj');
    histogram(Xj);
end

dist