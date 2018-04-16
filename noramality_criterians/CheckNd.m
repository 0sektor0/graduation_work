function distribution = CheckNd(Xj)

tsw = ShapiroWeakCriterion(Xj);
thg = HegazyGreenCriterion(Xj, 0.05);
tgc = GiriCriterion(Xj, 0.05);
tep = EppsPallyCriterion(Xj, 0.05);

distribution = thg || tgc || tep;

end

