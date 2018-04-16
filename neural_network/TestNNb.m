function [Y,Xf,Af] = TestNNb(X,Xi,~)
%MYNEURALNETWORKFUNCTION neural network simulation function.
%
% Generated by Neural Network Toolbox function genFunction, 16-Apr-2018 11:40:22.
%
% [Y,Xf,Af] = myNeuralNetworkFunction(X,Xi,~) takes these arguments:
%
%   X = 2xTS cell, 2 inputs over TS timesteps
%   Each X{1,ts} = 1xQ matrix, input #1 at timestep ts.
%   Each X{2,ts} = 1xQ matrix, input #2 at timestep ts.
%
%   Xi = 2x3 cell 2, initial 3 input delay states.
%   Each Xi{1,ts} = 1xQ matrix, initial states for input #1.
%   Each Xi{2,ts} = 1xQ matrix, initial states for input #2.
%
%   Ai = 2x0 cell 2, initial 3 layer delay states.
%   Each Ai{1,ts} = 30xQ matrix, initial states for layer #1.
%   Each Ai{2,ts} = 1xQ matrix, initial states for layer #2.
%
% and returns:
%   Y = 1xTS cell of 2 outputs over TS timesteps.
%   Each Y{1,ts} = 1xQ matrix, output #1 at timestep ts.
%
%   Xf = 2x3 cell 2, final 3 input delay states.
%   Each Xf{1,ts} = 1xQ matrix, final states for input #1.
%   Each Xf{2,ts} = 1xQ matrix, final states for input #2.
%
%   Af = 2x0 cell 2, final 0 layer delay states.
%   Each Af{1ts} = 30xQ matrix, final states for layer #1.
%   Each Af{2ts} = 1xQ matrix, final states for layer #2.
%
% where Q is number of samples (or series) and TS is the number of timesteps.

%#ok<*RPMT0>

% ===== NEURAL NETWORK CONSTANTS =====

% Input 1
x1_step1.xoffset = 510.9;
x1_step1.gain = 0.00522056904202558;
x1_step1.ymin = -1;

% Input 2
x2_step1.xoffset = 510.9;
x2_step1.gain = 0.00522056904202558;
x2_step1.ymin = -1;

% Layer 1
b1 = [-0.028183725206371364191;-0.024942101274911469833;-0.02860598811765610594;-0.028591718852410331897;0.028438617413659380423;0.028531220215106071342;0.026384324626821050591;-0.026497461796392816208;0.025653017781626138993;-0.46306053187442225427;-0.17762523401684771063;-0.028391213052233472969;-0.021774663227209029026;0.027248673517434283953;-0.028432111310043643032;0.024950249576618729191;0.027726053899003101633;-0.42185057958105065534;0.028546905334993630948;-0.028534329629083286101;-0.18594721360435673141;0.022523253209609822578;-0.028191495660869807238;-0.023904065770031367177;0.020269534486138364449;0.018578111193754767022;0.028434015805825028217;-0.019397999184210087259;0.028487693183913857797;0.14885115385832842216];
IW1_1 = [0.034511475326100569949 0.051434612492746778489 -0.064662736734720449583;0.031390043933836056511 0.043733154194028657502 -0.052185303033570738795;0.035297978475266278409 0.05556020619592441645 -0.070604693819597871829;0.035327868052966490686 0.055873642807795276255 -0.071023375050028772493;-0.035404069044068377237 -0.057270579779604612047 0.072820743311961963484;-0.034981089006384587237 -0.053403439304017301381 0.067598755210315802922;-0.032712105105114124004 -0.046502028219354854532 0.056778610316006512815;0.032817778352669725594 0.046743368289438293195 -0.057175608938513138024;-0.032038019817258976685 -0.045042569052104595995 0.054362598807762646524;0.20153768599019730723 0.029107655627429403211 -0.11999213215538070965;-0.32054177948171092005 0.0094884590775890318565 -0.26893135582664196015;0.03540798050249576584 0.057544931346337632738 -0.073160139031144641453;0.028497818176655313055 0.038534113874502264052 -0.043615450171414979486;-0.033534722301548865186 -0.048498515985149627527 0.06003496101857611067;0.034824170758668469838 0.052656654803967438416 -0.066506913149141144714;-0.031397323140076968673 -0.043746938677329948175 0.05220855994205089029;-0.034010692369792067113 -0.049806081355184488035 0.062130174140412199046;0.37842488328002554798 -0.72192250126437906843 0.13016982897344109293;-0.035368827437979560857 -0.05643247561723473138 0.071755075904589474267;0.034949528762646411839 0.053140321511761498541 -0.067243752953795407623;-0.37587819890086476837 -0.57233438133184777463 -0.031687076498988261952;-0.029187892190224645067 -0.039707071774635532835 0.045524671732597277174;0.034518719637157281588 0.05145294437595435838 -0.064693464891793422966;0.030447750209474776922 0.041946351240481953571 -0.049215315106360978115;-0.027087279326398396723 -0.036222036290651377088 0.039920698050266122114;-0.025454922683614680107 -0.033657151995920557563 0.0359521971713608543;-0.034842984363819995419 -0.052794633596394295594 0.066695323760608452024;0.026253191782165005014 0.034898508404273220762 -0.037854190309614968446;-0.035396418169671324538 -0.056957965798305573712 0.072430135815395743637;0.19799312590000892054 -0.83401739694678234116 0.3762656038739107256];
IW1_2 = [-0.0083256443855433369394 0.034511470890244713705 0.051434612449558388125;-0.0041304412796371219388 0.031390041362604842456 0.04373315415044001786;-0.01102779028857862019 0.035297977160485070891 0.055560206025727157386;-0.011245072038438871931 0.035327869938385457471 0.055873645656356718536;0.012232985270987902296 -0.035404068555780876526 -0.057270583687545485729;0.0095768403118466766122 -0.034981086133638900071 -0.053403437085644198112;0.0055096813288739244011 -0.032712102107394822048 -0.046502030634175774149;-0.0056367759878911969165 0.032817777603520462137 0.046743371460069904622;0.0047647873909556354155 -0.0320380163228248388 -0.045042570192363469428;0.12285198637346482486 0.20153768540996408465 0.029107654544769167443;-0.55850442387721543902 -0.32054178298962848759 0.0094884613083493114793;-0.012430571917527841533 0.035407978358345693071 0.057544927737398922363;-0.0019266507063337445522 0.028497819771485636414 0.03853411423340169506;0.0065942873920255256487 -0.033534721824913120425 -0.048498518274039302545;-0.0090936034429602661394 0.034824167943567789496 0.052656654590400663041;0.0041368872640849064029 -0.031397320435337043587 -0.043746936714487164033;0.0073448391780106510665 -0.034010689551259770669 -0.049806083726527568267;0.39040963918429294477 0.37842488281705383146 -0.72192249950892606325;0.011636572982480363966 -0.035368825230371395141 -0.056432474312859588761;-0.0094027052553033833859 0.034949528703234346294 0.053140320906416925462;0.37264693250759839405 -0.37587819902704816544 -0.57233438071023889915;0.0023800499454928211555 -0.029187895365015745219 -0.039707073884278250298;-0.0083367104412434642896 0.034518724326143300496 0.051452946641706145958;-0.0033165030062985204583 0.030447747688883967931 0.041946354970640163662;0.0011075713031056834672 -0.027087277389619697499 -0.036222039955673364375;0.00031559645204688751728 -0.025454921397345734585 -0.033657150400260280043;0.0091835531587789523411 -0.034842980869751204176 -0.052794633633802656725;-0.00068350226704455877783 0.026253194970397401853 0.034898507881955267984;0.012009079159514997326 -0.035396419114181627841 -0.056957966845146021373;1.4927098440696320303 0.19799312261670146129 -0.83401739722315482162];

% Layer 2
b2 = -0.22351546480648837312;
LW2_1 = [0.11704750006485974134 0.099122717821309130892 0.12537363123249256613 0.12595797585132445517 -0.12846643020477921393 -0.12117162545763802972 -0.10581189741407066862 0.10638453961618217491 -0.1023086330376331704 0.4775223212202701073 0.78895042482810973095 0.1289403407280325653 0.086267590361932294796 -0.11048576342520984028 0.11964081827124750657 -0.099156888336581108789 -0.11346721545374162388 -0.90547605787642515551 -0.126979065304302835 0.1206740904435425199 -0.56365566828942115229 -0.089180275852770177214 0.11709081475981980569 0.09472838102185467124 -0.080537127283167503355 -0.074223500607423609221 -0.1199052006706763096 0.077271771262687485859 -0.12792111789417240364 1.1862311975234600681];

% Output 1
y1_step1.ymin = -1;
y1_step1.gain = 0.00522056904202558;
y1_step1.xoffset = 510.9;

% ===== SIMULATION ========

% Format Input Arguments
isCellX = iscell(X);
if ~isCellX
    X = {X};
end
if (nargin < 2), error('Initial input states Xi argument needed.'); end

% Dimensions
TS = size(X,2); % timesteps
if ~isempty(X)
    Q = size(X{1},2); % samples/series
elseif ~isempty(Xi)
    Q = size(Xi{1},2);
else
    Q = 0;
end

% Input 1 Delay States
Xd1 = cell(1,4);
for ts=1:3
    Xd1{ts} = mapminmax_apply(Xi{1,ts},x1_step1);
end

% Input 2 Delay States
Xd2 = cell(1,4);
for ts=1:3
    Xd2{ts} = mapminmax_apply(Xi{2,ts},x2_step1);
end

% Allocate Outputs
Y = cell(1,TS);

% Time loop
for ts=1:TS
    
    % Rotating delay state position
    xdts = mod(ts+2,4)+1;
    
    % Input 1
    Xd1{xdts} = mapminmax_apply(X{1,ts},x1_step1);
    
    % Input 2
    Xd2{xdts} = mapminmax_apply(X{2,ts},x2_step1);
    
    % Layer 1
    tapdelay1 = cat(1,Xd1{mod(xdts-[1 2 3]-1,4)+1});
    tapdelay2 = cat(1,Xd2{mod(xdts-[1 2 3]-1,4)+1});
    a1 = tansig_apply(repmat(b1,1,Q) + IW1_1*tapdelay1 + IW1_2*tapdelay2);
    
    % Layer 2
    a2 = repmat(b2,1,Q) + LW2_1*a1;
    
    % Output 1
    Y{1,ts} = mapminmax_reverse(a2,y1_step1);
end

% Final Delay States
finalxts = TS+(1: 3);
xits = finalxts(finalxts<=3);
xts = finalxts(finalxts>3)-3;
Xf = [Xi(:,xits) X(:,xts)];
Af = cell(2,0);

% Format Output Arguments
if ~isCellX
    Y = cell2mat(Y);
end
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
