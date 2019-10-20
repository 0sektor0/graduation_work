function data = LoadData(filename)

fileId = fopen(filename);
if fileId ==-1
    error('file does not exist');
end
while feof(fileId) == 0
    line = fgetl(fileId);
    data = str2num(line);
end
fclose(fileId);

end