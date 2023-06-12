
try
    
   % Since cplexbilp solves minimization problems and the problem
   % is a maximization problem, negate the objective
 
  [a]=load('Ŀ�꺯��.txt');
   f     = a;
   [b]=load('����ʽ����.txt');
   Aineq = b;
   [c]=load('����ʽ����ֵ.txt');
   bineq = c;
   [d]=load('��ʽ����.txt');
   Aeq   = d;
   [e]=load('��ʽ����ֵ.txt');
   beq   =  e;
   %�����������������������Ƿ�һ��
   [m,n]=size(f);
   [a,b]=size(Aineq);
   [x,y]=size(bineq); 
   [p,q]=size(Aeq);
   [z,w]=size(beq);
    fprintf('ranks = %d\n',m,n,a,b,x,y,p,q,z,w);
   % fprintf('ranks = %d\n',m,n,a,b,x,y);
   options = cplexoptimset;
   options.Diagnostics = 'on';   
   %Aeq,beq,
   [x, fval, ~, output] = cplexbilp (f, Aineq, bineq,Aeq,beq, ...
      [ ], options);
  
   %�������Ľ��������ļ���
   fid = fopen('������.txt','w');
   fprintf(fid,'%f\t',x);
   fclose(fid);
   
   %��Ŀ�꺯���Ľ��������ļ���
   fid = fopen('backhaul_result.txt', 'a');
   fprintf(fid, '%d\t', fval);
   fclose(fid);
   
   %�����ܵ�Ƶ��Ч��
  % mode_num=load('����ģʽ����.txt');
  % R1 = load('����.txt');
  % A = load('������.txt');
  % B = A(1:1:mode_num); 
  % C=B';
  % throughput=R1*C;
   
   %��Ƶ��Ч��д�뵽�ĵ���
  % fid = fopen('throughput.txt', 'a');
  % fprintf(fid, '%f\t', throughput);
  % fclose(fid);     
  
  %��ʾ�������
   fprintf ('\nSolution status = %s\n', output.cplexstatusstring);   
   disp (x);
   %��ʾĿ�꺯��ֵ
  % disp ('Values = ');
   fprintf ('Solution value = %d\n', fval); 
   %Ƶ��Ч���ܺ� 
  % fprintf ('Throughput = %f\n', throughput); 
  %����ֵ֮�ͣ���Ҫ��Ϊ���жϻ�վ�Ƿ񻺴���
   h = sum(x);
   disp('Sum = ');
   disp(h);
  
catch m
   disp(m.message);
end



