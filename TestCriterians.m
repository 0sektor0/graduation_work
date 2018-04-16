%данные с особыми состояниями
CXj = [0, 0, 3, 1.7, 1.8, 2.2, 3.1, 3.8, 5.4, 4.0, 5.1, 4.8, 4.9, 4.7, 4.8, 4.6, 5.5, 4.5, 4.9, 4.4, 4.5, 3.9, 5.5, 5.1, 1.2, 1.4, 1.1, 1.9, 3.5 ,2.7, 2.1, 3.1, 3.2, 2.9, 3.1, 3.2, 2.5, 2.1, 2.6, 3.1, 2.9, 3.7, 3.8, 1.8, 4.1, 4.7, 4.2, 1.7, 1.2, 4.1, 4.2, -1];

%данные без особых состояний
WXj = [1.7, 4.0, 3.1, 3.2, 2.3, 3.0, 3.1, 3.2, 5.2, 1.2, 2.3, 3.3, 3.0, 1.1];

XjCell = {CXj, WXj};
cn = length(XjCell);

for i=1:cn

    Xj = XjCell{i}
    n = length(Xj);
    %контрольные границ карт шухарта
    cl = 3;                     %центральная линия
    ucl = 6;                    %верхняя граница
    lcl = 0;                    %нижняя граница

    %оси гранц для графика
    clY = cl * ones(1, n);      
    uclY = ucl * ones(1, n);
    lclY = lcl * ones(1, n);

    %рсчитываем границы в 1 сигма
    lA = 1;             %нижняя область А
    lB = 2;             %нижняя облатсть B
    lC = cl;            %
    uA = ucl;           %верхняя облать А
    uB = 5;             %
    uC = 4;             %

    %оси границ для графиков
    lAY = lA * ones(1, n);
    lBY = lB * ones(1, n);
    lCY = lC * ones(1, n);
    uAY = uA * ones(1, n);
    uBY = uB * ones(1, n);
    uCY = uC * ones(1, n); 

    XX = 1 : 1 : n;
    subplot(cn, 1, i)
    plot(XX, Xj, XX, lclY, XX, lAY, XX, lBY, XX, clY, XX, uCY, XX, uBY, XX, uAY);


    %проверяем каждый критерий
    for i=1:8
       [is_uc, num] = Check4SpecialResons(Xj, [i], lcl, lA, lB, lC, uC, uB, uA)
    end

    %Sp = ToSP(Xj, lcl, lA, lB, lC, uC, uB, uA);
    %n = length(Sp);
    %newSR = zeros(1, n+1);
    %newSR(1, 1) = 1707;
    %newSR(1, 2:n+1) = Sp;

    %[is_uc, num] = Check4SpecialResons(Xj, newSR(1, 1:n+1), lcl, lA, lB, lC, uC, uB, uA)
end






