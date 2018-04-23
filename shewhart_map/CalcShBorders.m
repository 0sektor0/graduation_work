function [lA,lB,lC,uC,uB,uA] = CalcShBorders(Xucl,Xcl,Xlcl)  
%X карта и линии
sigm = (Xucl - Xlcl)/6;
lA = Xlcl + sigm;
lB = Xlcl + 2*sigm;
lC = Xcl;
uC = Xlcl + 4*sigm;
uB = Xlcl + 5*sigm;
uA = Xucl;
end