function Throughput


    try
        %user_num = 5;
       % sub_num = 25;
       % mode_num=load('����ģʽ����.txt');
       % numb = sub_num*mode_num; 
       % R1 = load('����.txt');
       % R2 = R1';
       % A = load('������.txt');
       % B = A(1:1:numb);                       
       % C = reshape(B,sub_num,mode_num);        %�ŵ�ʹ�����
       % E = sum(C);                           %E�������ÿ���û������ж��ٸ��ŵ�
       % output = E*R2;          
        
       mode_num=load('����ģʽ����.txt');
       R1 = load('����.txt');
       A = load('������.txt');
       B = A(1:1:mode_num); 
       C=B';
       throughput=R1*C;
        %disp(numb);
        %disp(B);
        %disp(C);
        
       %disp(E);
      % disp(R2);
       %disp(user_num);   
        
        disp(throughput);              
 
        
    catch m
    disp(m.message);
    end
end