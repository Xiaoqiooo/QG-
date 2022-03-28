#include "counter.h"


int main() {
	HideCursor();    //隐藏光标
	system("color F1");//改变窗口颜色 
	system("mode con cols=110 lines=30");//改变窗口大小 
	system("cls");
	gotoxy(0,0);    //使不闪屏 
	playtime(); 
	printf("\n");
	char exp[MAXSIZE];
	char i[100];
	int m; 
	do{
		fflush(stdin);
		menu();   //菜单
		gets(exp);
		m = istrue(exp);
		if(m == 1){
			char newexp[MAXSIZE];
			if(transform(exp,newexp)){
				printf("\t计算结果：%lf\n",endcounter(newexp));
				printf("\t*            	                                        *\n\n");
				printf("\t********************************************************\n");
				printf("\t请问您是否要接着使用本计算器？（是-任意输入，否-0）\n\t "); 
				gets(i);
			}	
		}else if(m == 0){
			printf("\t您输入的表达式不合法\n");
			printf("\t请重新输入\n"); 
			system("pause");
			system("cls"); 
		}else{
			printf("\t本计算器暂不支持非整数的运算\n");
			printf("\t请重新输入\n"); 
			system("pause");
			system("cls");
		}	
		system("cls"); 
	}while(strcmp(i,"0")!=0);
	printf("将为您退出计算器\n"); 
	return 0;
}

