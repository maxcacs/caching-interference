

function random_delay
try
    u_num=100;   %�û���
    r_num=5;     %��վ��
    f_num=200;    %���ļ���
    rba_num = 50;  %����RB����Ŀ
    rbb_num = 25;   %�س�RB����Ŀ
    ra=zeros(1,u_num);   %������Դ�ķ������飬ֻ��¼ÿ���û��ܹ��ֵö��ٸ�RB
    rb=zeros(1,u_num);    %�س���Դ�ķ������飬ֻ��¼ÿ���û��ܹ��ֵö��ٸ�RB
    access_table=zeros(u_num, r_num);   %�����û��Ľ���������ô���ģʽѡ������Ľ���ʹ���ģʽ������������
    rate_array=zeros(1,u_num);     %�����û��Ľ�����������
         
    a=load('����ģʽ����.txt');
    %disp(a);
    T=load('������.txt');
    y=T(1:a);      %���������еĴ���ģʽ������ֵ��������y��
    %disp(length(y));
    l=T(a+1:length(T));   %���������еĻ��������ֵ��������l��
    %disp(length(l));
    L=reshape(l, [r_num,f_num]);   %��վ������
    A=load('����ģʽ����.txt');
    R=load('����.txt');
    Req=load('�û�����.txt');        %�û�������Ϣ
    
    %�õ��û��Ľ������ͽ������ʡ�
    j=1;
    for i=1:length(y)
        if y(i)==1            %���û��Ĵ���ģʽѡ�����ȡ1ʱ������Ӧ�еĽ�����ӵ�access_table�У���Ӧ�е�������ӵ�rate_array��
            access_table(j,:) = A(i,:);
             rate_array(1,j)=R(1,i);
            j=j+1;
        end            
    end
    %disp(access_table);
   % disp(rate_array);
    
 	 vec_id=zeros(1,u_num );          %��¼���뵽��վi���û���id
    
     %������Դ�ķ���
	 for i=1 : r_num %#ok<ALIGN>
	    k=1;
        for j=1 : u_num
            if access_table(j,i)==1 && ra(1,j)==0        %����û�j���뵽��վi����Ŀǰ��û�з��䵽��Դ���ڻ�վi�ڷ�����ԴʱҪ���ǵ��û�j
              vec_id(1,k)=j;                                  %���û�j��id��¼��vec_id��
                k=k+1;
            end
        end
        vec_id =  vec_id(1, 1:k-1);
		div = length(vec_id);
		x1 = rba_num/div;   
		x2=floor(x1);    		
        for m=1 : div           
            ra(vec_id(m)) = x2;
        end
     end
    % disp('������Դ�ķ��䣺');
    % disp(ra);     
     %disp(rate_array);
     
     %�������ʱ��
     access_delay=zeros(1,u_num);
     for i=1 : u_num
         access_delay(1,i) = 1024*1024/(1800*ra(1,i)*rate_array(1,i));
     end
     a_result=sum(access_delay);
     %disp('ÿ���û��Ľ���ʱ�ӣ�');
     %disp(access_delay);
     %disp('����ʱ��');
    % disp(a_result);
     
     %�س���Դ�ķ���
     bac_delay=zeros(1,u_num);      %��¼ÿ���û��Ļس�ʱ��
     for i=1:r_num
         x1=sum(access_table(:,i));
         x2=rbb_num/x1;
         x3=round(x2);
         for j=1: u_num
             if rb(1,j)==0 && access_table(j,i)==1
                 rb(1,j)=x3;
             end
         end
     end     
     %disp('�س���Դ�ķ��䣺')
     %disp(rb);
     
     %����س�ʱ��
     for i=1 : u_num
             bac_delay(1,i) = 1/rb(1,i);
     end     
     %disp('ÿ���û��Ļس�ʱ�ӣ�')
     %disp(bac_delay);     
     b_result = sum(bac_delay);
     % disp('�س�ʱ��');
     % disp(b_result);   
    
    %������ʱ��
     total_deday = a_result + b_result;
     disp('��ʱ�ӣ�');
     disp(total_deday);
     %����ʱ��д�뵽�ĵ���
     fid = fopen('3--random_ʱ��.txt', 'a');
     fprintf(fid, '%d\t', total_deday);
     fclose(fid);
    
catch m
   disp(m.message);
end
end