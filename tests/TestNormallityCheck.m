%тест для проверки функция определения нормального распределения
%задается число тестов tc определяющее максимальную длину вектора
%задается стартовое значение длины вектора
%для каждой возможной длины заданного вектора генерируются два вектора,
%первый распределенный по нормальному закону и второй распределенный по
%равномерному.
%если функция сработала неверно, то есть неправильно предсказала одно из
%распределений, то счетчик ошибок wa увеличивается на 1
%на выходе теста мы получаем процент проваленных тестов, ожидаемый
%результат: <1%

wa = 0;     %wrong answers counter
tc = 505;   %tests num
ts = 5;     %tests start value

for i=ts:tc
    i
    Xjn = randn(1, i);

    tsw = ShapiroWeakCriterion(Xjn);
    thg = HegazyGreenCriterion(Xjn, 0.05);
    tgc = GiriCriterion(Xjn, 0.05);
    tep = EppsPallyCriterion(Xjn, 0.05);
    distn = tsw || thg || tgc || tep;


    Xj = rand(1, i);
    tsw = ShapiroWeakCriterion(Xj);
    thg = HegazyGreenCriterion(Xj, 0.05);
    tgc = GiriCriterion(Xj, 0.05);
    tep = EppsPallyCriterion(Xj, 0.05);
    dist = tsw || thg || tgc || tep;


    if (distn == false) && (dist == true) 
          wa = wa + 1;
    end

end

wa/tc*100