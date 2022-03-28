#include "counter.h"

//将运算符转换为对应的优先级 
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
//判断是否为运算符 
Status ifop(char ch)
{
	if(ch=='(' || ch==')' || ch=='+' || ch=='-' || ch=='*' || ch=='/'){
		return ok;
	} else{
		return error;
	}
}

//表达式合理输入判断
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
//把中缀表达式转换为后缀表达式 
Status transform(char *exp,char newexp[])
{
	int i = 0;
	//定义顺序栈 
	struct {             
		char data[MAXSIZE];
		int top;
	}op;
	//初始化栈
	op.top = -1;
	op.top++;
	op.data[op.top] = '=';//将栈底的运算符设置为'=',作为结束标志
	//从左到右扫描表达式，判段其组成  
	while(*exp!='\0'){//当还未到字符数组尾部时 
		if(ifop(*exp)){//运算符--> 比较优先级 
			switch(comparepri(op.data[op.top],*exp)){
				case 0:{//当'('和')'遇到时 将'（' 前的所有运算符取出 
					op.top--;
					exp++; 
					break;
				}
				case -1:{//待处理运算符优先级高，故做入栈处理 
					op.top++;
					op.data[op.top] = *exp;
					exp++;
					break;
				} 
				case 1:{//待处理运算符优先级低，故进行出栈处理，输出到后缀表达式中 
					newexp[i] = op.data[op.top];
					i++;
					op.top--;
					break;
				}
			}
		}else{
			while(*exp>='0' && *exp<='9'){//数字-->得到整个数字并用#分隔 
				newexp[i] = *exp;
				i++;
				exp++; 
			}
			newexp[i] = '#';  //分隔 
			i++;
		} 
	} 
	while(op.data[op.top] != '='){//当栈内还有要输出的运算符时 
		newexp[i] =  op.data[op.top];
		op.top--;
		i++;
	}
	newexp[i] = '\0';
}

//进行最终计算，进行后缀表达式的运算并返回结果 
double endcounter(char *newexp)
{
	double n1,n2,temp,i=0;
	//定义一个顺序栈（数栈） 
	struct{
		float data[MAXSIZE];
		int top;
	}s;
	//初始化栈
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
					printf("除法中分母不能为0，您输入的表达式不合法\n");
					printf("将为您自动退出计算器\n"); 
					exit(0);
				}else{
					s.data[++s.top] = n2/n1;	
				}
				break;
			}
			default:{//当遇到数字或者分隔数字的'#'时，将数字存入数栈 
				while(*newexp>='0'&&*newexp<='9'){
					temp = i*10 + (*newexp - '0');
					newexp++; 
				} //离开while时*newexp='#' 
				s.top++;
				s.data[s.top] = temp;
				break;
			}
		}
		newexp++;//离开switch时,已经跳过'#'了 
	}
	 return s.data[s.top];
}

//比较栈顶运算符和待处理运算符的优先级高低
int comparepri(char op1,char op2)
{
	if(leftpri(op1) == rightpri(op2)){//当'('和')'遇到时 
		return 0;
	}else if(leftpri(op1)<rightpri(op2)){//待处理运算符优先级高，故做入栈处理 
		return -1;
	}else{//待处理运算符优先级低，故进行运算处理 
		return 1;
	}
 } 

void HideCursor()//隐藏光标  
{
	CONSOLE_CURSOR_INFO cursor_info = {1,0}; //第二个值为0表示隐藏光标
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void gotoxy(int x,int y)  //光标定位函数:让光标直接跳转到（x,y）位置的函数
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);//定义显示器句柄变量
    COORD pos; 
    pos.X = x;  //横坐标 
    pos.Y = y;  //纵坐标 
    SetConsoleCursorPosition(handle,pos);
}

void playtime() //显示时间函数 
{
	time_t timep;
    time(&timep);
    struct tm *p = gmtime(&timep);
    printf("\t%d/%d/%d", (1900+p->tm_year), (1+p->tm_mon), p->tm_mday);
    printf(" %d:%d:%d\n", (8+p->tm_hour), p->tm_min, p->tm_sec); 
}
void menu(){
	HideCursor();
	Beep(2000,250); //进入菜单发声 
	printf("\n");
	printf("\t********************************************************\n\n");
	printf("\t*            	    四则运算计算器                     *\n\n");
	printf("\t*              (本计算器只进行整数运算)                *\n\n");
	printf("\t********************************************************\n");
	printf("\t--------------------------------------------------------\n");
	printf("\t********************************************************\n");
	printf("\t*请输入需要计算的合理表达式（括号要用英文输入法输入）：*\n");
	printf("\t*            	                                       *\n\n"); 
	printf("\t");
	
}
