#include "queue.h"

//初始化队列 
void InitLQueue(LQueue *Q)
{
	//建立头结点 
	Node *n = (Node*)malloc(sizeof(Node));
	//将front和rear都指向头结点 
	Q->front = Q->rear = n;
	Q->length = 0; 
	if(!Q->front || !Q->rear){
		printf("初始化失败\n");
	}
	printf("初始化成功\n"); 
}

//判断队列是否为空
Status IsEmptyLQueue(const LQueue *Q)
{
	//front和rear同时指向头结点
	if(Q->front == Q->rear){
		return ok;
	} else{
		return error;
	}
}

//查看队头元素
Status GetHeadLQueue(LQueue *Q, void *e)
{
	if(!Q->length){
		return error;
	}
	void *a =  Q->front->next->data;
	e = a;
	return ok;
}

//清空队列
void ClearLQueue(LQueue *Q)
{
	while(!IsEmptyLQueue){
		DeLQueue(Q);
	}
	if(!Q->length){
	Q->front = Q->rear = NULL;		
	}
}
//检测队列长度
Status LengthLQueue(LQueue *Q,int *length)
{
	if(*length==Q->length){
		return ok;
	} else{
		return error;
	}
}

//入队操作
Status EnLQueue(LQueue *Q, void *data,char ch)
{
	//建立新结点 
	Node *n = (Node*)malloc(sizeof(Node));
	if(!n){
		return error;
	}
	n->data = data;
	n->type = ch;
	n->next = NULL;
	Q->rear->next = n;//将新结点与原链队列相连 
	Q->rear = n;      //更新尾指针的位置 
	Q->length++;
	return ok; 
}

//出队操作
Status DeLQueue(LQueue *Q)
{
	if(Q->length == 0){  //当队列为空时 
		return error;
	}
	Node *p = Q->front->next;//将欲删除的队头结点暂存给p
	Q->front->next = p->next;
	if(Q->rear == p){  //如果队列中有一个有数据的结点，删除后front和rear都指向头结点 
		Q->rear = Q->front; 
	}
	free(p);
	Q->length--;
	return ok;
}

//销毁队列 
void DestoryLQueue(LQueue *Q)
{
	while(!IsEmptyLQueue){
		DeLQueue(Q);
	}
	Q->front = Q->rear = NULL;
	free(Q->front);
 } 

//遍历函数操作
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

//打印函数 
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

//检验是否有乱输入其他字符
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
                printf("请输入合乎要求的整数：");
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
    for(m=0;m<len;m++)  // 将字符重新转换为数字
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
                printf("请输入合乎要求的浮点数：");
                misflag=1;
                break;
            }
        }
        if(dotflag==1){
        	j = 0;
		}else{
			if(!misflag){
			printf("请输入合乎要求的浮点数：");				
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
			printf("请输入合乎要求的字符：");
		}
	}
	return word[0];
}
//菜单 
void menu(){
	HideCursor();
	Beep(2000,250); //进入菜单发声 
	printf("\n");
	printf("\t******************************************************\n\n");
	printf("\t*            	     栈链功能菜单                     *\n\n");
	printf("\t*            	                                      *\n\n");
	printf("\t******************************************************\n");
	printf("\t------------------------------------------------------\n");
	printf("\t******************************************************\n");
	printf("\t*                  1.初始化队列                      *\n");
	printf("\t*                  2.销毁队列                        *\n");
	printf("\t*                  3.判断队列是否为空                *\n");
	printf("\t*                  4.查看队头元素                    *\n");
	printf("\t*                  5.清空队列                        *\n");
	printf("\t*                  6.检测队列长度                    *\n");
	printf("\t*                  7.入队                            *\n");
	printf("\t*                  8.出队                            *\n");
	printf("\t*                  9.遍历队列                        *\n");
	printf("\t*                  0.退出系统                        *\n");
	printf("\t******************************************************\n");
	printf("\t------------------------------------------------------\n");
	printf("\t请输入您所要执行的功能(0-9)：");
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

