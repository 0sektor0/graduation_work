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
[X, R] = CreateIndScmParam(Xj, 0.01);
%[X, R] = CreateIndScmParam(Xj, 5);

%границы зон R карты
rx = 1:R.size;
rla = ones(1,R.size)*R.la;
rlb = ones(1,R.size)*R.lb;
rlc = ones(1,R.size)*R.lc;
rua = ones(1,R.size)*R.ua;
rub = ones(1,R.size)*R.ub;
ruc = ones(1,R.size)*R.uc;

%границы зон X карты
xx = 1:X.size;
xla = ones(1,X.size)*X.la;
xlb = ones(1,X.size)*X.lb;
xlc = ones(1,X.size)*X.lc;
xua = ones(1,X.size)*X.ua;
xub = ones(1,X.size)*X.ub;
xuc = ones(1,X.size)*X.uc;

%R карта
subplot(2,3,4);
plot(rx,rla, rx,rlb, rx,rlc, rx,rua, rx,rub, rx,ruc, rx,R.ts);

%X карта
subplot(2,3,6);
plot(xx,xla, xx,xlb, xx,xlc, xx,xua, xx,xub, xx,xuc, xx,X.ts);

state = false;
for i=1:8
    [error, position] = CheckMap(struct('type',i,'ts',[]), X);
    disp(i + " " + error + " " + position);
    state = state || error;
end

if state == true
    error("data can't be predicted")
end




















