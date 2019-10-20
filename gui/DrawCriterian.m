function DrawCriterian(criterian)
    x = 1 : criterian.size;
    la = ones(1,criterian.size) * 0.5;
    lb = ones(1,criterian.size) * 1.5;
    lc = ones(1,criterian.size) * 2.5;
    cl = ones(1,criterian.size) * 3.5;
    ua = ones(1,criterian.size) * 4.5;
    ub = ones(1,criterian.size) * 5.5;
    uc = ones(1,criterian.size) * 6.5;

    plot(x,criterian.ts, x,la, x,lb, x,lc, x,cl, x,uc, x,ub, x,ua);
end

