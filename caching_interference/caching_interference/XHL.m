function XHL
    try
        [d1]=load('������.txt');
        S1 = d1;
        [d2]=load('����.txt');
        S2 = d2;   
        S3 = S2.';
        disp(size(S1));
        disp(size(S3));
        data=S1*S3;
        
        sum_n = sum(data);  
        disp(sum_n);
        
    catch m
    disp(m.message);
    end
end