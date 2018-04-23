function [inp,out] = SplitData(data,size)
    n = length(data);
    s = n-size;
    
    if n <= size
        error("size mismatch");
    end
    
    inp = zeros(size, s);
    out = zeros(1, s);
    
    for i=1:s
       inp(:,i)=data(1,i:i+size-1);
       out(i)=data(1,i+size);
    end
end

