%параметры теста
sl = 60;        %sample length 50 60
offset = 472;   %50 140


%########################%
%считываем временной ряд %
%########################%
data = LoadData();
data_len = length(data);
Xj = data(offset: offset+sl-1);

subplot(2,3,1);
plot([offset:offset+sl-1], Xj);  %график временного ряда


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
%[Xucl, Xcl, Xlcl, Rucl, Rcl, Rlcl] = ShewhartInd(Xj);
[Xucl, Xcl, Xlcl, Rucl, Rcl, Rlcl] = ShewhartIndP(mean(Xj),5);

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
[lA, lB, lC, uC, uB, uA] = CalcShBorders(Xucl,Xcl,Xlcl);
lAY = lA * ones(1, n);
lBY = lB * ones(1, n);
lCY = lC * ones(1, n);
uAY = uA * ones(1, n);
uBY = uB * ones(1, n);
uCY = uC * ones(1, n);

%X карта
subplot(2,3,6);
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




















