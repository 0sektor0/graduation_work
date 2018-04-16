function [y1,xf1,xf2] = SimulateNarxNetworkSin(x1,x2,xi1,xi2)
%MYNEURALNETWORKFUNCTION neural network simulation function.
%
% Generated by Neural Network Toolbox function genFunction, 18-Mar-2018 23:34:59.
%
% [y1,xf1,xf2] = myNeuralNetworkFunction(x1,x2,xi1,xi2) takes these arguments:
%   x1 = 1xTS matrix, input #1
%   x2 = 1xTS matrix, input #2
%   xi1 = 1x5 matrix, initial 5 delay states for input #1.
%   xi2 = 1x5 matrix, initial 5 delay states for input #2.
% and returns:
%   y1 = 1xTS matrix, output #1
%   xf1 = 1x5 matrix, final 5 delay states for input #1.
%   xf2 = 1x5 matrix, final 5 delay states for input #2.
% where TS is the number of timesteps.

% ===== NEURAL NETWORK CONSTANTS =====

% Input 1
x1_step1.xoffset = -0.999999682931835;
x1_step1.gain = 1.00000031706827;
x1_step1.ymin = -1;

% Input 2
x2_step1.xoffset = -0.999999682931835;
x2_step1.gain = 1.00000031706827;
x2_step1.ymin = -1;

% Layer 1
b1 = [-1.3922910334749807326;-1.2243227026298271198;-1.161643411359166711;0.67333631182990638653;0.16568973433063080569;-0.21123017491985102145;0.26311886693415992289;-0.87640070521585855534;1.4094979073865545605;1.7429300475993962927];
IW1_1 = [0.061118274114390067075 0.8298497049046560381 0.37370421384758467642 -0.158751734216084045 -0.78490825315753975921;0.45245729087246855382 -0.1788464029878837902 0.80476647981130877696 -0.40976660375266277248 0.73545036441467237509;0.064998207764566690026 0.10205876785931218553 0.60539502572113679246 0.54300672037422426097 0.49148973155308195437;-0.77623308042818206509 0.61855950507032730901 -0.052556936312140610512 0.59196247108706867568 0.56947784560221326178;-0.18375679513183668101 0.7987344121367537797 0.46134689481393692523 0.78759242653206218421 -0.44865558935127902718;0.3557541390720725949 0.44635436329409816647 -0.16275726759675654409 0.23238495186979110652 0.56026273558967631949;-0.031054031701868399507 -0.70233273371579374444 0.83740650216391565586 0.046342999217160077419 0.15312539286570189812;-0.37954870166977433543 0.17579939418324624922 0.82084738939122636747 -0.53515672416150283919 -0.50444865429346774643;0.74836593250336136407 -0.92172594699906729154 0.63475361457385315322 0.71826071648196210262 -0.22617740060867175256;0.80988420411757133799 -0.14680215324128653709 -0.19175535558190129337 -0.058057948077309746993 -0.4570878200807355074];
IW1_2 = [0.48007240060049333197 -0.50577944426525867083 0.74243581436767869253 0.34981797347828991196 -0.54753566571526457452;-0.32655555053651469377 -0.026470156442869152702 -0.26280911762015801703 0.83503738209305189422 -0.8236142368438069683;0.80575443384963607585 0.38235123028352996366 -0.70142826323808360467 0.40021028762755889163 -0.023251768225536494777;0.58544393706798292243 0.66029601732771403544 -0.26797218750834256307 -0.19389039268654384429 -0.72563051376941334336;-0.31021171446756912182 0.36176753800464767075 -0.31053007116776842889 0.61073537709902703252 -0.73806147067274319173;-0.057709205351858104682 -1.2496335893106431669 0.13455419846262481332 -0.88581854010554228473 0.41872332846062687572;0.35178193520485390167 0.28351044798211488818 0.02510775264902168763 -1.0292477683266567645 0.57982720873662252359;0.3333973535015349321 -0.26664420612800932009 -0.26429502651768754795 -0.72055484570004180167 0.87255553506833860578;0.096473957991624059716 -0.22380988865279541344 -0.28684262815962385806 -0.72864634459582378057 0.07793405488788429647;0.24100105249987524569 -0.79424037432398786329 0.097792315813590019458 -0.33734056504732179427 1.1722430098942051568];

% Layer 2
b2 = -0.51213534382060155181;
LW2_1 = [0.22791232026521598963 0.3562975104828735029 0.0016997302229618191372 -0.10321879935706215758 0.011173329077173058815 -1.3330986659522587878 1.0280049070402814682 -0.63293366154353070119 -0.29979747055028638236 0.37390326576799848279];

% Output 1
y1_step1.ymin = -1;
y1_step1.gain = 1.00000031706827;
y1_step1.xoffset = -0.999999682931835;

% ===== SIMULATION ========

% Dimensions
TS = size(x1,2); % timesteps

% Input 1 Delay States
xd1 = mapminmax_apply(xi1,x1_step1);
xd1 = [xd1 zeros(1,1)];

% Input 2 Delay States
xd2 = mapminmax_apply(xi2,x2_step1);
xd2 = [xd2 zeros(1,1)];

% Allocate Outputs
y1 = zeros(1,TS);

% Time loop
for ts=1:TS
    
    % Rotating delay state position
    xdts = mod(ts+4,6)+1;
    
    % Input 1
    xd1(:,xdts) = mapminmax_apply(x1(:,ts),x1_step1);
    
    % Input 2
    xd2(:,xdts) = mapminmax_apply(x2(:,ts),x2_step1);
    
    % Layer 1
    tapdelay1 = reshape(xd1(:,mod(xdts-[1 2 3 4 5]-1,6)+1),5,1);
    tapdelay2 = reshape(xd2(:,mod(xdts-[1 2 3 4 5]-1,6)+1),5,1);
    a1 = tansig_apply(b1 + IW1_1*tapdelay1 + IW1_2*tapdelay2);
    
    % Layer 2
    a2 = b2 + LW2_1*a1;
    
    % Output 1
    y1(:,ts) = mapminmax_reverse(a2,y1_step1);
end

% Final delay states
finalxts = TS+(1: 5);
xits = finalxts(finalxts<=5);
xts = finalxts(finalxts>5)-5;
xf1 = [xi1(:,xits) x1(:,xts)];
xf2 = [xi2(:,xits) x2(:,xts)];
end

% ===== MODULE FUNCTIONS ========

% Map Minimum and Maximum Input Processing Function
function y = mapminmax_apply(x,settings)
y = bsxfun(@minus,x,settings.xoffset);
y = bsxfun(@times,y,settings.gain);
y = bsxfun(@plus,y,settings.ymin);
end

% Sigmoid Symmetric Transfer Function
function a = tansig_apply(n,~)
a = 2 ./ (1 + exp(-2*n)) - 1;
end

% Map Minimum and Maximum Output Reverse-Processing Function
function x = mapminmax_reverse(y,settings)
x = bsxfun(@minus,y,settings.ymin);
x = bsxfun(@rdivide,x,settings.gain);
x = bsxfun(@plus,x,settings.xoffset);
end
