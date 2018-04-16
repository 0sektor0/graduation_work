%считываем временной ряд
fData = fopen('data/MFON_160101_180101_F.txt');
if fData==-1
    error('file does not exist');
end
while feof(fData) == 0
    line = fgetl(fData);
    data = str2num(line);
end

data_len = length(data);
X = [1 : data_len];
%plot(X, data);

%данные для обучения сети
nn_inp = data(1 : data_len-1); %вход нейросети
nn_out = data(2 : data_len);   %выхо нейросети

%Пометка
%далее предполагается, что уже есть обученная сеть
%delay должен совпадать с хадержкой сети

%применяем нс

% nn_xs = zeros(2, 1);
% nn_xs(1,:) = nn_inp(4);
% nn_xs(2,:) = nn_inp(5);
% 
% nn_xis = zeros(2, 3);
% nn_xis(1,:) = nn_inp(1:3);
% nn_xis(2,:) = nn_inp(2:4);
% 
% nn_xis = num2cell(nn_xis);
% nn_xs = num2cell(nn_xs);
% [c, nn_xis, Ai] = TestNNb(nn_xs, nn_xis, {});
% a = 1;


% nn_xs = zeros(1, 1);
% nn_xs(1,:) = nn_inp(4);
% 
% nn_xis = zeros(1, 3);
% nn_xis(1,:) = nn_inp(1:3);
% 
% nn_xis = num2cell(nn_xis);
% nn_xs = num2cell(nn_xs);
% [c, nn_xis, Ai] = SimulateNarNetwork(nn_xs, nn_xis, {});


dl = 3;                     %network delay
pc = 100;                   %predictions count
offset = 1;                 
result = zeros(1, pc);

nn_xis = zeros(1, dl);
nn_xis(1,:) = nn_inp(1:dl);
nn_xis = num2cell(nn_xis);

result(4) = data(4);
result(1, 1:3) = nn_inp(1:3);
 for i=5:pc
     %nn_xs = {data(i+dl)};
     nn_xs = num2cell(result(i-1));
     nn_xis = num2cell(result(i-dl-1: i-2));
     [c, nn_xis, Ai] = SimulateNarNetwork(nn_xs, nn_xis, {});
     result(i) = c{1};
 end

plot([1:pc], data(1 : pc), [1:pc], result);












