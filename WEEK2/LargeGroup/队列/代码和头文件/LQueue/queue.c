#include "queue.h"

//��ʼ������ 
void InitLQueue(LQueue *Q)
{
	//����ͷ��� 
	Node *n = (Node*)malloc(sizeof(Node));
	//��front��rear��ָ��ͷ��� 
	Q->front = Q->rear = n;
	Q->length = 0; 
	if(!Q->front || !Q->rear){
		printf("��ʼ��ʧ��\n");
	}
	printf("��ʼ���ɹ�\n"); 
}

//�ж϶����Ƿ�Ϊ��
Status IsEmptyLQueue(const LQueue *Q)
{
	//front��rearͬʱָ��ͷ���
	if(Q->front == Q->rear){
		return ok;
	} else{
		return error;
	}
}

//�鿴��ͷԪ��
Status GetHeadLQueue(LQueue *Q, void *e)
{
	if(!Q->length){
		return error;
	}
	void *a =  Q->front->next->data;
	e = a;
	return ok;
}

//��ն���
void ClearLQueue(LQueue *Q)
{
	while(!IsEmptyLQueue){
		DeLQueue(Q);
	}
	if(!Q->length){
	Q->front = Q->rear = NULL;		
	}
}
//�����г���
Status LengthLQueue(LQueue *Q,int *length)
{
	if(*length==Q->length){
		return ok;
	} else{
		return error;
	}
}

//��Ӳ���
Status EnLQueue(LQueue *Q, void *data,char ch)
{
	//�����½�� 
	Node *n = (Node*)malloc(sizeof(Node));
	if(!n){
		return error;
	}
	n->data = data;
	n->type = ch;
	n->next = NULL;
	Q->rear->next = n;//���½����ԭ���������� 
	Q->rear = n;      //����βָ���λ�� 
	Q->length++;
	return ok; 
}

//���Ӳ���
Status DeLQueue(LQueue *Q)
{
	if(Q->length == 0){  //������Ϊ��ʱ 
		return error;
	}
	Node *p = Q->front->next;//����ɾ���Ķ�ͷ����ݴ��p
	Q->front->next = p->next;
	if(Q->rear == p){  //�����������һ�������ݵĽ�㣬ɾ����front��rear��ָ��ͷ��� 
		Q->rear = Q->front; 
	}
	free(p);
	Q->length--;
	return ok;
}

//���ٶ��� 
void DestoryLQueue(LQueue *Q)
{
	while(!IsEmptyLQueue){
		DeLQueue(Q);
	}
	Q->front = Q->rear = NULL;
	free(Q->front);
 } 

//������������
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q,char type))
{
	if(!Q->length){
		return error;
	} 
	Node *n = Q->front->next;
	while(n){
		foo(n->data,n->type);
		n = n->next; 		
	}
	return ok;
}

//��ӡ���� 
void LPrint(void *q,char ch)
{
	if(ch == 's'|| ch == 'c'){
		printf("%s\t",(char*)q);
	}
	if(ch == 'i'){
		printf("%d\t",*(int*)q);
	}
	/*if(ch == 'c'){
		printf("%c\t",*((char*)q));
	}*/
	if(ch == 'd'){
		printf("%f\t",*(double*)q);
	}
}

//�����Ƿ��������������ַ�
int judge_int()
{
	int len, num = 0, arg = 1;
    char word[1000];  
    int m, j= 1, k;
    while(j)
    {
        gets(word);
        len = strlen(word);
        for(m = 0;m<len;m++)
        {
            if(word[m]<'0' || word[m]>'9')  
            {
                printf("������Ϻ�Ҫ���������");
                break;
            }
            else 
            {
                if(m == len-1)
                    j = 0;
            }
        }
    }
    j = len-1;
    for(m=0;m<len;m++)  // ���ַ�����ת��Ϊ����
    {
        for(k=0;k<j;k++)
            arg *= 10;
        num += (word[m]-'0')*arg;
        arg = 1;
        j--;
    }
    return num;
} 

double judge_double()
{
	int len,dotflag=0,misflag=0;
    char word[1000];  
    int m, j= 1;
    while(j)
    {
        gets(word);
        len = strlen(word);
        for(m = 0;m<len;m++)
        {
        	if(word[m] == '.'){
        		dotflag++;
			}
            if(!((word[m]>='0'&&word[m]<='9') || word[m]=='.')){
                printf("������Ϻ�Ҫ��ĸ�������");
                misflag=1;
                break;
            }
        }
        if(dotflag==1){
        	j = 0;
		}else{
			if(!misflag){
			printf("������Ϻ�Ҫ��ĸ�������");				
			}
		}
    }
    return atof(word);
} 

char judge_char()
{
	int j=1;
	char word[1000];
	while(j){
		gets(word);
		if(strlen(word)==1){
			j=0;
		}else{
			printf("������Ϻ�Ҫ����ַ���");
		}
	}
	return word[0];
}
//�˵� 
void menu(){
	HideCursor();
	Beep(2000,250); //����˵����� 
	printf("\n");
	printf("\t******************************************************\n\n");
	printf("\t*            	     ջ�����ܲ˵�                     *\n\n");
	printf("\t*            	                                      *\n\n");
	printf("\t******************************************************\n");
	printf("\t------------------------------------------------------\n");
	printf("\t******************************************************\n");
	printf("\t*                  1.��ʼ������                      *\n");
	printf("\t*                  2.���ٶ���                        *\n");
	printf("\t*                  3.�ж϶����Ƿ�Ϊ��                *\n");
	printf("\t*                  4.�鿴��ͷԪ��                    *\n");
	printf("\t*                  5.��ն���                        *\n");
	printf("\t*                  6.�����г���                    *\n");
	printf("\t*                  7.���                            *\n");
	printf("\t*                  8.����                            *\n");
	printf("\t*                  9.��������                        *\n");
	printf("\t*                  0.�˳�ϵͳ                        *\n");
	printf("\t******************************************************\n");
	printf("\t------------------------------------------------------\n");
	printf("\t����������Ҫִ�еĹ���(0-9)��");
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

