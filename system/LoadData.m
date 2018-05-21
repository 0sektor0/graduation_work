function data = LoadData(filename)

fData = fopen(filename);
if fData==-1
    error('file does not exist');
end
while feof(fData) == 0
    line = fgetl(fData);
    data = str2num(line);
end

%cr 2 data fix
data(481) = 785.666;
data(484) = 785.666;
data(488) = 785.666;
data(500) = 784.17;
data(501) = 782.17;
data(503) = 782.17;
data(508) = 782.17;
data(514) = 782.17;
data(518) = 784.17;

%cr 6 data fix
data(513) = 780;
data(517) = 778;

data = data./max(data);
data(480) = 0.89;
data(493) = 0.89;
data(513) = 0.89;
data(530) = 0.89;
data(515) = 0.89;

end

