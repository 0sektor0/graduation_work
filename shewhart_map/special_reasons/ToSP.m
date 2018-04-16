function Sp = ToSP(Xj, lcl, lA, lB, lC, uC, uB, uA)
    n = length(Xj);
    Sp = zeros(1, n);
    
    for i=1:n
        if Xj(i) < lcl
            Sp(1, i) = 0;
        elseif Xj(i) >= lcl && Xj(i) < lA
            Sp(1, i) = 1;
        elseif Xj(i) >= lA && Xj(i) < lB
            Sp(1,i) = 2;
        elseif Xj(i) >= lB && Xj(i) < lC
            Sp(1,i) = 3;
        elseif Xj(i) >= lC && Xj(i) < uC
            Sp(1,i) = 4;
        elseif Xj(i) >= uC && Xj(i) < uB
            Sp(1,i) = 5;
        elseif Xj(i) >= uB && Xj(i) <= uA
            Sp(1,i) = 6;
        elseif Xj(i) >= uA
            Sp(1,i) = 7;
        end
    end
end

