data = LoadData();
n = length(data);

sl = 100;
ofs = 472;
Xj = data(ofs:ofs-1+sl);
%Xj = data;

[X,R] = CreateIndScmParam(Xj, 0.01)

for i = 1:8
    [is_true, num] = CheckMap([i], X);
    if is_true
        disp("FAIL");
        break
    end
end