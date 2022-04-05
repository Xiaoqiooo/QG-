#include "sort.h"

void insertSort(int *a,int n)//��������(�Ӵ�С)
{
	int i,j,temp; 
	//Ĭ�ϵ�һ��Ԫ��Ϊ�����������Ԫ�أ��ʴӵڶ���Ԫ�ؿ�ʼ���в������ز��� 
	for(i=1 ; i<n ; i++){
		temp = *(a+i);
		for(j=i-1 ; j>=0 ; j--){//��Ŀ��Ԫ�ص�ǰһ��Ԫ�ؿ�ʼ�Ƚ��жϣ��Ƿ�Ҫ���в������ 
			while(*(a+j) < temp && j>=0){//Ŀ��Ԫ��С��ǰ���Ԫ��ʱ�����в��� 
				*(a+j+1) = *(a+j);
				j--;
			} 
			*(a+j+1) = temp;
		} 
	}
}

void MergeArray(int *a,int begin,int mid,int end,int *temp)//�鲢���򣨺ϲ����飩
{
	int i,j,k;
	i = begin;
	j = mid+1;
	k = begin;
	while((i<=mid) && (j<=end)){//����ǰ���������ְ���С����ϲ��Ĳ��� 
		if(*(a+i) <= *(a+j)){
			*(temp+k) = *(a+i);
			i++;
			k++;
		}else{
			*(temp+k) = *(a+j);
			j++;
			k++;
		}
	}
	//��ʱǰ��������������һ�����ֵ�Ԫ���Ѿ���temp������ã�������һ����ʣ���Ԫ�ط���temp�� 
	while(i <= mid){
		*(temp+k) = *(a+i);
		k++;
		i++;
	}
	while(j <= end){
		*(temp+k) = *(a+j);
		k++;
		j++;
	}
}

void MergeSort(int *a,int begin,int end,int size,int *temp)//�鲢����
{
	int mid = (begin+end)/2;
	if(begin == end){
		*(temp+begin) = *(a+begin); 
	}else{
		int *t = (int*)malloc(sizeof(int)*size);
		if(t!=NULL){
			MergeSort(a,begin,mid,size,t);
		 	MergeSort(a,mid+1,end,size,t);
			MergeArray(t,begin,mid,end,temp);	
		}
	}
}

void QuickSort_Recursion(int *a, int begin, int end)//�������򣨵ݹ�棩
{
	if(begin>end){
		return;
	} 
	int i,j,base,temp;
	i = begin;
	j = end;
	base = *(a+begin);//��׼�� 
	while(i != j){//���ڱ�j��i��δ������ʱ�� 
		while(*(a+j) <= base && j > i){//�ҵ��ڱ�j�Ȼ�׼��С��λ�� 
			j--;
		}
		while(*(a+i) >= base && j > i){//�ҵ��ڱ�i�Ȼ�׼�����λ�� 
			i++;			
		} 
		if(j > i){//�ڱ�j��i���Һ�λ�ú� 
			temp = *(a+i);
			*(a+i) = *(a+j);
			*(a+j) = temp;
		} 
	}
	//���ڱ�i��j����ʱ�������������ڵ�λ�úͻ�׼������������Ϊ�µĻ�׼�� 
	*(a+begin) = *(a+i);
	*(a+i) = base;
	//���Ͼ���һ��̽�⣬�����������ݷ�Ϊ�����֣����������ֱַ�������������
	QuickSort_Recursion(a,begin,i-1);
	QuickSort_Recursion(a,i+1,end);
}

void QuickSort(int *a,int size)//�������򣨷ǵݹ�棩no
{
	
}

int Partition(int *a, int begin, int end)//�������������ţ�no
{
	
}

void CountSort(int *a, int size)//��������
{
	int max,min,i,j,sum=0;
	max = *a;
	min = *a;
	for(i=0 ; i<size ; i++){//�ҵ������ֵ 
		if(*(a+i)>max){
			max = *(a+i);
		}
	}
	for(i=0 ; i<size ; i++){//�ҵ���С��ֵ 
		if(*(a+i)<min){
			min = *(a+i);
		}
	}
	int num = max-min;//������num����ֵ 
	//�������飬����ͳ�ƶ�ӦԪ�صĸ��� 
	int count[num+1];
	for(i=0 ; i<num+1 ; i++){
		count[i] = 0;
	}
	for(i=0 ; i<size ; i++){
		count[*(a+i)-min]++;
	}
	//���������ֵ���мӹ��������Ԫ�ص���ǰ��Ԫ��֮��(��Ӧ����ȷ��������)
	for(i=0 ; i<num+1 ; i++){
		sum += count[i];
		count[i] = sum;
	}
	//����������飬��count�������ҵ���ȷλ�ã���������temp���� 
	int temp[size];
	for(i=size-1 ; i>=0 ; i--){
		temp[count[*(a+i)-min]-1] = *(a+i);
		count[*(a+i)-min]--;
	} 
	//��temp����Ľ�����Ƶ�a����
	for(i=0,j=size-1 ; i<size ; i++,j--){
		*(a+i) = temp[j];
	} 
}
/*
int GetDigit(int m, int i) //ȡ����m�ĵ�iλ��
{
	while(i > 1){
		m /= 10;
		i--;
	}
	return m % 10;
}

void RadixCountSort(int *a, int size)//�������� 
{
	int i, j, k, l, digit,num=0,max=0;
	int temp[10][size];	//temp���飬�洢��ʱ��� 

	memset(temp, 0, sizeof(temp));//��ʼ��temp����

	for(i=0 ; i<size ; i++){//�ҵ������ֵ 
		if(*(a+i)>max){
			max = *(a+i);
		}
	}
	//������м�λ������֪��Ҫ���м���ѭ��
	while(max){
		num++;
		max/=10;
	}

	for(i = 1; i <= num; i++)
	{
		//������Ӧλ�������ݣ�������temp����
		for(j = 0; j < size; j++){			
			digit = GetDigit(*(a+j), i);
			k = 0;
			while(temp[digit][k])
				k++;
			temp[digit][k] = *(a+j);
		}
		//��temp��������������ռ���ԭ������
		if(i!=num){
			l = 0; 
			for(j = 0; j < 10; j++)	{	
				k = 0;
				while(temp[j][k] > 0){
					*(a+l) = temp[j][k];
					l++;
					k++;
				}
			}	
		}else{
			l = size-1; 
			for(j = 0; j < 10; j++)	{	
				k = 0;
				while(temp[j][k] > 0){
					*(a+l) = temp[j][k];
					l--;
					k++;
				}
			}	
		}
		
		//ÿ�η��䣬�ռ����ʼ��temp���飬������һλ���ķ�����ռ�
		memset(temp, 0, sizeof(temp));
	}
}
*/
typedef struct Que  //����
{
 	int*  data;
 	int head;
 	int tail;
}Que;

int GetMaxDigit(int* a,int size)//�õ����ݵ�������ֵ�λ�� 
{
	int i;
 	int max = a[0];
	for(i=0 ; i<size ; ++i){
  		if(max<a[i]){
   			max=a[i];
  		}
 	}
	int num = 0;
 	while(max>0){
  		num++;
  		max/=10;
 	}
 	return num;
}

int GetNumOfData(int data,int width)//�õ����ݵ�λ�� 
{
 	int num = data%10;//��10ȡ��  
 	while(width){ //��ʼwidth==0,��ʾȡ��λ��ֵ������ѭ����ֱ�ӷ���num
  		data /= 10;
  		width--;
  		num = data%10;
 	}
 	return num;
}

void RadixCountSort(int*  a,int size)
{
	int i,j,num;
 	//��ȡ������ֵ�λ��
 	int max = GetMaxDigit(a,size);
 	Que que[10];
 	for(i=0;i<10;++i)  //��ʼ��ʮ������
 	{
  		que[i].data =(int*)malloc(sizeof(int)*size);
  		que[i].head =que[i].tail =0;
 	}
 	//i=0;��λ  i=1;ʮλ  i=2;��λ   i=3;ǧλ
 	for(i=0 ; i<max ; ++i){
  		for(j=0 ; j<size ; ++j){//������ 
   			num = GetNumOfData(a[j],i);
   			que[num].data [que[num].tail++]=a[j];
  		}
  		int count=0;
  		for(i=0 ; i<10 ; ++i){//���ݳ����н���a��
   			while(que[i].head!=que[i].tail){//������
    				a[count++]=que[i].data[que[i].head++];
   			}
   		que[i].head =que[i].tail=0;//���г�ʼ����Ϊ��һ�η�������׼��
  		}
 	}
 	for(i=0;i<10;++i){
  		free(que[i].data);
	 }
}

void ColorSort(int *a,int size)//��ɫ����
{
	int p0=0,p1,p2=size-1;
	int i,temp;
	for(p1=1 ; p1!=p2 ;){
		if(*(a+p1) == 0){
			temp = *(a+p1);
			*(a+p1) = *(a+p0);
			*(a+p0) = temp;
			p0++;
		}else if(*(a+p1) == 2){
			temp = *(a+p1);
			*(a+p1) = *(a+p2);
			*(a+p2) = temp;
			p2--;
		}else{
			p1++;
		}
	}
}

int FoundGoal(int *a,int begin,int end,int k)//��һ�������������ҵ���KС����
{
	int i,j,m,mid,temp;
	i = begin;
	j = end;
	m = (i+j)/2;
	mid = *(a+m);
	do{
		while(*(a+j) > mid){
			j--;
		}
		while(*(a+i) < mid){
			i++;
		}
		if(i <= j){
			temp = *(a+i);
			*(a+i) = *(a+j);
			*(a+j) = temp;
			i++;
			j--;
		}
	}while(i <= j);
	//������һ�ο��� 
	if(k <= j){//��Ѱ������ 
		return FoundGoal(a,begin,j,k);
	}else if(i <= k){//��Ѱ������ 
		return FoundGoal(a,i,end,k);
	}else{
		j++;
		return *(a+j);
	}
}

int* RandomArray(int *a,int size) //����������ĺ��� 
{
	int count;
	for(count = 0 ; count < size ; count++){
		srand((unsigned)(time(0)+count));
		*a = rand()%1000000+1;
		a++;
	}
	return a;
}

int* RandomArrays(int *a,int size) //����������ĺ��� 
{
	int count;
	for(count = 0 ; count < size ; count++){
		srand((unsigned)(time(0)+count));
		*a = rand()%3;
		a++;
	}
}

void show(int *a,int n){//��ӡ���� 
	int i = 0;
	for(i=0 ; i<n ; i++){
		printf("%d\t",*(a+i));
	} 
	printf("\n");
}

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

//�˵� 
void menu(){
	printf("\n");
	printf("\t******************************************************\n\n");
	printf("\t*            	     �����ܲ˵�                     *\n\n");
	printf("\t*            	                                      *\n\n");
	printf("\t******************************************************\n");
	printf("\t------------------------------------------------------\n");
	printf("\t******************************************************\n");
	printf("\t*          1.�������ڲ�ͬ�Ĵ��������µ���ʱ        *\n");
	printf("\t*          2.�������ڴ���С�������µ�������ʱ      *\n");
	printf("\t*          3.����Ӧ����                              *\n");
	printf("\t*          0.�˳�ϵͳ                                *\n");
	printf("\t******************************************************\n");
	printf("\t------------------------------------------------------\n");
	printf("\t����������Ҫִ�еĹ���(0-3)��");
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

