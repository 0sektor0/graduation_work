% n >= 8
function IsNormal = EppsPallyCriterion(Xj, alpha)
   if size(Xj, 1) ~= 1
        error('size mismatch')
    end 
    
    n = length(Xj);
    
    %проверка на возможность применения критерия
    if(n < 8)
        IsNormal = false;
        return
    end

    %определяем какой вектор квантилей использовать согласно госту 5479-2002
    switch alpha
        case 0.1
            quantile = [0.271, 0.275, 0.279, 0.284, 0.287, 0.289, 0.290, 0.291, 0.290];
        case 0.05
            quantile = [0.347, 0.350, 0.357, 0.366, 0.368, 0.371, 0.374, 0.376, 0.379];
        case 0.025
            quantile = [0.426, 0.428, 0.437, 0.447, 0.450, 0.459, 0.460, 0.464, 0.467];
        case 0.01
            quantile = [0.526, 0.537, 0.545, 0.560, 0.564, 0.569, 0.574, 0.583, 0.590];
        otherwise
            error("wrong alpha");
    end
    
    
    %определяем значение квантиля в зависимости от длины вектора    
    lens = [8, 9, 10, 15, 20, 30, 50, 100, 200];
    ll = length(lens);
    qval = -1;
    
    for i = 1:ll-1
        if n == lens(i)
            qval = quantile(i);
            break
        end
        
        if n > lens(i) && n < lens(i+1)
            qval = (quantile(i) + quantile(i+1))/2;
            break
        end        
    end
    
    if qval < 0
        qval = quantile(ll);
    end
    
    %расчет параметра А
    Xcp=mean(Xj); 
    m2=sum((Xj-Xcp).^2)/n; 
    A=sqrt(2)*sum(exp(-((Xj-Xcp).^2)/(4*m2)));   
    
    %расчет параметра В
    X1=Xj(1:n-1); 
    M1=diag(X1); 
    E=ones(n-1,n-1); 
    M1=M1*E; 
    M1=triu(M1); 
    
    X2=Xj(2:n); 
    M2=diag(X2); 
    M2=E*M2; 
    M2=triu(M2);
    
    D=M1-M2; 
    Bm=exp(-D.^2 / (2*m2)); 
    Bm=triu(Bm); 
    Sj=sum(Bm);
    Sk=sum(Sj);
    B=2/n*Sk;
    
    %расчет статистики критерия
    Tep=1+n/sqrt(3)+B-A;
    
    %определения нормальности распределения
    if Tep > qval
        IsNormal = false;
    else
        IsNormal = true;
    end
end

