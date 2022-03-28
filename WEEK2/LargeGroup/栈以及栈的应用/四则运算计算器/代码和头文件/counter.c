#include "counter.h"

//�������ת��Ϊ��Ӧ�����ȼ� 
int leftpri(char op)
{
	if(op == '='){
		return 0;
	}
	if(op == '('){
		return 1;
	}
	if(op == '*'){
		return 5;
	}
	if(op == '/'){
		return 5;
	}
	if(op == '+'){
		return 3;
	}
	if(op == '-'){
		return 3;
	}
	if(op == ')'){
		return 6;
	}
}
int rightpri(char op)
{
	if(op == '='){
		return 0;
	}
	if(op == '('){
		return 6;
	}
	if(op == '*'){
		return 4;
	}
	if(op == '/'){
		return 4;
	}
	if(op == '+'){
		return 2;
	}
	if(op == '-'){
		return 2;
	}
	if(op == ')'){
		return 1;
	}
}
//�ж��Ƿ�Ϊ����� 
Status ifop(char ch)
{
	if(ch=='(' || ch==')' || ch=='+' || ch=='-' || ch=='*' || ch=='/'){
		return ok;
	} else{
		return error;
	}
}

//���ʽ���������ж�
int istrue(char *exp)
{
	int flag =0,t=0,opflag=0,count=0;
	char ch;
	while(*exp != '\0'){
		ch = *exp;
		if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
			flag = 1;
			if(!opflag){
				return error;
			}
			opflag = 0;
		}
		if(ch>='0' && ch<='9'){
			opflag = 1;
		}
		if(ch=='('){
			t--;
		}
		if(ch==')'&& t==-1){
			t++;
		}
		if(ch == '.'){
			return -1;
		} 
		if(ch == ')' && count == 0){
			return 0;
		}
		exp++;
		count++;
	}
	if(flag==1 && t==0){
		return 1;
	}
	return 0;
} 
//����׺���ʽת��Ϊ��׺���ʽ 
Status transform(char *exp,char newexp[])
{
	int i = 0;
	//����˳��ջ 
	struct {             
		char data[MAXSIZE];
		int top;
	}op;
	//��ʼ��ջ
	op.top = -1;
	op.top++;
	op.data[op.top] = '=';//��ջ�׵����������Ϊ'=',��Ϊ������־
	//������ɨ����ʽ���ж������  
	while(*exp!='\0'){//����δ���ַ�����β��ʱ 
		if(ifop(*exp)){//�����--> �Ƚ����ȼ� 
			switch(comparepri(op.data[op.top],*exp)){
				case 0:{//��'('��')'����ʱ ��'��' ǰ�����������ȡ�� 
					op.top--;
					exp++; 
					break;
				}
				case -1:{//��������������ȼ��ߣ�������ջ���� 
					op.top++;
					op.data[op.top] = *exp;
					exp++;
					break;
				} 
				case 1:{//��������������ȼ��ͣ��ʽ��г�ջ�����������׺���ʽ�� 
					newexp[i] = op.data[op.top];
					i++;
					op.top--;
					break;
				}
			}
		}else{
			while(*exp>='0' && *exp<='9'){//����-->�õ��������ֲ���#�ָ� 
				newexp[i] = *exp;
				i++;
				exp++; 
			}
			newexp[i] = '#';  //�ָ� 
			i++;
		} 
	} 
	while(op.data[op.top] != '='){//��ջ�ڻ���Ҫ����������ʱ 
		newexp[i] =  op.data[op.top];
		op.top--;
		i++;
	}
	newexp[i] = '\0';
}

//�������ռ��㣬���к�׺���ʽ�����㲢���ؽ�� 
double endcounter(char *newexp)
{
	double n1,n2,temp,i=0;
	//����һ��˳��ջ����ջ�� 
	struct{
		float data[MAXSIZE];
		int top;
	}s;
	//��ʼ��ջ
	s.top = -1;
	while(*newexp != '\0'){
		switch(*newexp){
			case '+':{
				n1 = s.data[s.top--];
				n2 = s.data[s.top--];
				s.data[++s.top] = n2+n1;
				break;
			}
			case '-':{
				n1 = s.data[s.top--];
				n2 = s.data[s.top--];
				s.data[++s.top] = n2-n1;
				break;
			}
			case '*':{
				n1 = s.data[s.top--];
				n2 = s.data[s.top--];
				s.data[++s.top] = n2*n1;
				break;
			}
			case '/':{
				n1 = s.data[s.top--];
				n2 = s.data[s.top--];
				if(n1 == 0){
					printf("�����з�ĸ����Ϊ0��������ı��ʽ���Ϸ�\n");
					printf("��Ϊ���Զ��˳�������\n"); 
					exit(0);
				}else{
					s.data[++s.top] = n2/n1;	
				}
				break;
			}
			default:{//���������ֻ��߷ָ����ֵ�'#'ʱ�������ִ�����ջ 
				while(*newexp>='0'&&*newexp<='9'){
					temp = i*10 + (*newexp - '0');
					newexp++; 
				} //�뿪whileʱ*newexp='#' 
				s.top++;
				s.data[s.top] = temp;
				break;
			}
		}
		newexp++;//�뿪switchʱ,�Ѿ�����'#'�� 
	}
	 return s.data[s.top];
}

//�Ƚ�ջ��������ʹ���������������ȼ��ߵ�
int comparepri(char op1,char op2)
{
	if(leftpri(op1) == rightpri(op2)){//��'('��')'����ʱ 
		return 0;
	}else if(leftpri(op1)<rightpri(op2)){//��������������ȼ��ߣ�������ջ���� 
		return -1;
	}else{//��������������ȼ��ͣ��ʽ������㴦�� 
		return 1;
	}
 } 

void HideCursor()//���ع��  
{
	CONSOLE_CURSOR_INFO cursor_info = {1,0}; //�ڶ���ֵΪ0��ʾ���ع��
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void gotoxy(int x,int y)  //��궨λ����:�ù��ֱ����ת����x,y��λ�õĺ���
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);//������ʾ���������
    COORD pos; 
    pos.X = x;  //������ 
    pos.Y = y;  //������ 
    SetConsoleCursorPosition(handle,pos);
}

void playtime() //��ʾʱ�亯�� 
{
	time_t timep;
    time(&timep);
    struct tm *p = gmtime(&timep);
    printf("\t%d/%d/%d", (1900+p->tm_year), (1+p->tm_mon), p->tm_mday);
    printf(" %d:%d:%d\n", (8+p->tm_hour), p->tm_min, p->tm_sec); 
}
void menu(){
	HideCursor();
	Beep(2000,250); //����˵����� 
	printf("\n");
	printf("\t********************************************************\n\n");
	printf("\t*            	    �������������                     *\n\n");
	printf("\t*              (��������ֻ������������)                *\n\n");
	printf("\t********************************************************\n");
	printf("\t--------------------------------------------------------\n");
	printf("\t********************************************************\n");
	printf("\t*��������Ҫ����ĺ�����ʽ������Ҫ��Ӣ�����뷨���룩��*\n");
	printf("\t*            	                                       *\n\n"); 
	printf("\t");
	
}
