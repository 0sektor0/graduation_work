sl = 60;       %sample length 50
offset = 140;   %50  

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
Xj = data(offset: offset+sl);

subplot(3,1,1);
plot([offset:offset+sl], Xj);

subplot(3,1,2);
dist = CheckNd(Xj);
histogram(Xj);

subplot(3,1,3);
if dist == false
    Xj = boxcox(0.05, Xj')';
    dist = CheckNd(Xj);
    histogram(Xj);
end

dist