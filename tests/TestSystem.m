%параметры теста
sl = 60;        %sample length 50 60
offset = 140;   %50 140


%########################%
%считываем временной ряд %
%########################%
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

subplot(2,3,1);
plot([offset:offset+sl], Xj);  %график временного ряда


%######################%
%проверка распределения%
%######################%
subplot(2,3,2);
dist = CheckNd(Xj);
histogram(Xj);              %распределение

subplot(2,3,3);
if dist == false
    Xj = boxcox(0.05, Xj')';
    dist = CheckNd(Xj);
    histogram(Xj);          %распеределение после преобразования Бокса-Кокса
    
    if dist == false
        error('not normal ditribution');
    end
end


%###################%
%расчет карт шухарта%
%###################%
[Xucl, Xcl, Xlcl, Rucl, Rcl, Rlcl] = ShewhartInd(Xj);

n = length(Xj);
YR = abs(Xj(1:n-1) - Xj(2:n));  %R карта
YRcl = Rcl*ones(1, n-1);        %прямая средней линии R карты
YRucl = Rucl*ones(1, n-1);      %прямая врехней линии R карты
YRlcl = Rlcl*ones(1, n-1);      %пряиая нижней линии R карты

YXcl = Xcl*ones(1, n);          %прямая средней линии X карты
YXucl = Xucl*ones(1, n);
YXlcl = Xlcl*ones(1, n);

XR = 1 : 1 : n-1;               %X ось R карты
XX = 1 : 1 : n;                 %X ось X карты
    
%R карта
subplot(2,3,4);
plot(XR, YR, XR, YRucl, XR, YRcl, XR, YRlcl);


%X карта и линии
sigm = (Xucl - Xlcl)/6;
lA = Xlcl + sigm;
lB = Xlcl + 2*sigm;
lC = Xcl;
uC = Xlcl + 4*sigm;
uB = Xlcl + 5*sigm;
uA = Xucl;

lAY = lA * ones(1, n);
lBY = lB * ones(1, n);
lCY = lC * ones(1, n);
uAY = uA * ones(1, n);
uBY = uB * ones(1, n);
uCY = uC * ones(1, n);

%X карта
subplot(2,3,6);
%plot(XX, Xj, XX, YXucl, XX, YXcl, XX, YXlcl);
plot(XX, Xj, XX, YXucl, XX, YXcl, XX, YXlcl, XX, lAY, XX, lBY, XX, uCY, XX, uBY);

state = false;
for i=1:8
    i
    [is_uc, num] = Check4SpecialResons(Xj, [floor(i)], Xlcl, lA, lB, lC, uC, uB, uA)
    state = state || is_uc;
end

if state == true
    error("data can't be predicted")
end




















