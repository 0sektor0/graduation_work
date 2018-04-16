wa = 0;
tc = 605;  %tests num
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