#include "counter.h"


int main() {
	HideCursor();    //���ع��
	system("color F1");//�ı䴰����ɫ 
	system("mode con cols=110 lines=30");//�ı䴰�ڴ�С 
	system("cls");
	gotoxy(0,0);    //ʹ������ 
	playtime(); 
	printf("\n");
	char exp[MAXSIZE];
	char i[100];
	int m; 
	do{
		fflush(stdin);
		menu();   //�˵�
		gets(exp);
		m = istrue(exp);
		if(m == 1){
			char newexp[MAXSIZE];
			if(transform(exp,newexp)){
				printf("\t��������%lf\n",endcounter(newexp));
				printf("\t*            	                                        *\n\n");
				printf("\t********************************************************\n");
				printf("\t�������Ƿ�Ҫ����ʹ�ñ�������������-�������룬��-0��\n\t "); 
				gets(i);
			}	
		}else if(m == 0){
			printf("\t������ı��ʽ���Ϸ�\n");
			printf("\t����������\n"); 
			system("pause");
			system("cls"); 
		}else{
			printf("\t���������ݲ�֧�ַ�����������\n");
			printf("\t����������\n"); 
			system("pause");
			system("cls");
		}	
		system("cls"); 
	}while(strcmp(i,"0")!=0);
	printf("��Ϊ���˳�������\n"); 
	return 0;
}

