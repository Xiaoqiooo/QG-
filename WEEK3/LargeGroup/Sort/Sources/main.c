#include "sort.h"
int main() {
	double time; 
	int ifsave = 1;  //�Ƿ񱣴����ݵı�� 
	int n,k,choice,m,i; 
	clock_t start,diff;
	/*FILE *fp=fopen("SortTime.txt","a+"); 
	FILE *fpm=fopen("st.txt","a+"); 
	if(!fp){
		perror("fopen");
		return 0;
	}
	if(!fpm){
		perror("fopen");
		return 0;
	}*/
	do{
		fflush(stdin);
		menu();   //�˵�
		choice = judge_int();
		switch(choice){
			case 1:{//�������ڲ�ͬ�Ĵ��������µ���ʱ 
				system("cls");
				/*char ch[100] = {};
				fclose(fp);
				FILE *fp=fopen("SortTime.txt","a+"); 
				if(!fp){
					perror("fopen");
					return 0;
				}
				printf("�����㷨      ��ʱ��ms��\n");
				while(1){
					if(fgets(ch,10,fp) == NULL){
						if(feof(fp)){
							break;
						}
						fputs(ch,stdout);
					}
				}*/
				printf("��ѡ�����������\n");
				printf("10000��50000��200000\n");
				printf("�����Ȳ��Ա�Ĺ��ܣ�������200000����\n"); 
				m = judge_int();
				if(m == 10000){
					//������Ϊ10000ʱ
					int arr[simple];
					int *a = arr;
					printf("��10000����������\n"); 
					RandomArray(a,simple);
					start = clock();
					insertSort(a,simple);
					diff = clock() - start;
					printf("\t�����������ʱ��%d ms\n",diff);
					
					RandomArray(a,simple);
					start = clock();
					MergeSort(a,0,simple,simple,a);
					diff = clock() - start;
					printf("\t�鲢�������ʱ��%d ms\n",diff);	
					
					RandomArray(a,simple);
					start = clock();
					QuickSort_Recursion(a,0,simple);
					diff = clock() - start;
					printf("\t�����������ʱ��%d ms\n",diff);	 
				
					RandomArray(a,simple);
					start = clock();
					CountSort(a,simple);
					diff = clock() - start;
					printf("\t�����������ʱ��%d ms\n",diff);	 
				
					RandomArray(a,simple);
					start = clock();
					RadixCountSort(a,simple);
					diff = clock() - start;
					printf("\t�����������ʱ��%d ms\n",diff);
					free(a); 
				}else if(m == 50000){
					//������Ϊ50000ʱ
					int brr[medium];
					int *b = brr;
					printf("\n��50000����������\n"); 
					RandomArray(b,medium);
					start = clock();
					insertSort(b,medium);
					diff = clock() - start;
					printf("\t�����������ʱ��%d ms\n",diff);
					
					RandomArray(b,medium);
					start = clock();
					MergeSort(b,0,medium,medium,b);
					diff = clock() - start;
					printf("\t�鲢�������ʱ��%d ms\n",diff);	
					
					RandomArray(b,medium);
					start = clock();
					QuickSort_Recursion(b,0,medium);
					diff = clock() - start;
					printf("\t�����������ʱ��%d ms\n",diff);	 
				
					RandomArray(b,medium);
					start = clock();
					CountSort(b,medium);
					diff = clock() - start;
					printf("\t�����������ʱ��%d ms\n",diff);	 
				
					RandomArray(b,medium);
					start = clock();
					RadixCountSort(b,medium);
					diff = clock() - start;
					printf("\t�����������ʱ��%d ms\n",diff);
					free(b);
				}else if(m == 200000){
					//������Ϊ200000ʱ
					int crr[senior];
					int *c = crr;
					printf("\n��200000����������\n"); 
					RandomArray(c,senior);
					start = clock();
					insertSort(c,senior);
					diff = clock() - start;
					printf("\t�����������ʱ��%d ms\n",diff);
					
					RandomArray(c,senior);
					start = clock();
					MergeSort(c,0,senior,senior,c);
					diff = clock() - start;
					printf("\t�鲢�������ʱ��%d ms\n",diff);	
					
					RandomArray(c,senior);
					start = clock();
					QuickSort_Recursion(c,0,senior);
					diff = clock() - start;
					printf("\t�����������ʱ��%d ms\n",diff);	 
				
					RandomArray(c,senior);
					start = clock();
					CountSort(c,senior);
					diff = clock() - start;
					printf("\t�����������ʱ��%d ms\n",diff);	 
				
					RandomArray(c,senior);
					start = clock();
					RadixCountSort(c,senior);
					diff = clock() - start;
					printf("\t�����������ʱ��%d ms\n",diff);
					//printf("\t�����������ʱ��19856 ms\n");
					free(c);
				}else{
					printf("������10000����50000����200000��ע�⣡���������Ϊ��Ч���룡��");
				}
				system("pause");
				system("cls"); 
				break;
			}
			case 2:{//�������ڴ���С�������µ�������ʱ
				system("cls");
				int trr[text];
				int *t = trr;
				printf("��100��������,����100k�ε������\n"); 
					RandomArray(t,text);
					start = clock();
					for(i=0 ; i<times ; i++){
						insertSort(t,text);	
					}
					diff = clock() - start;
					printf("\t�����������ʱ��%d ms\n",diff);
					
					RandomArray(t,text);
					start = clock();
					for(i=0 ; i<times ; i++){
						MergeSort(t,0,text,text,t);	
					}
					diff = clock() - start;
					printf("\t�鲢�������ʱ��%d ms\n",diff);	
					
					RandomArray(t,text);
					start = clock();
					for(i=0 ; i<times ; i++){
						QuickSort_Recursion(t,0,text);
					}
					diff = clock() - start;
					printf("\t�����������ʱ��%d ms\n",diff);	 
				
					RandomArray(t,text);
					start = clock();
					for(i=0 ; i<times ; i++){
						CountSort(t,text);
					}
					diff = clock() - start;
					printf("\t�����������ʱ��%d ms\n",diff);	 
				
					RandomArray(t,text);
					start = clock();
					for(i=0 ; i<times ; i++){
						RadixCountSort(t,text);
					}
					printf("\t�����������ʱ��%d ms\n",diff);
					free(t); 
				/*char ch[100] = {};
				fclose(fpm);
				FILE *fpm=fopen("st.txt","a+"); 
				if(!fpm){
					perror("fopen");
					return 0;
				}
				printf("�����㷨      ��ʱ��ms��\n");
				while(1){
					if(fgets(ch,10,fpm) == NULL){
						if(feof(fpm)){
							break;
						}
						fputs(ch,stdout);
					}
				}*/
				system("pause");
				system("cls"); 
				break;
			}
			case 3:{//����Ӧ����
				system("cls");
				printf("1.������ɫ���������СΪ10��\n"); 
			    int array[20];
			    int *d = array;
			    RandomArrays(d,10);
			    printf("����ǰ��\n");
			    show(d,10);
			    printf("\n�����\n");
			    ColorSort(d,10);
			    show(d,10);
			    printf("\n\n\n\n\n\n\n");
			    printf("2.���η�����-���������kС�����֣������СΪ100��\n"); 
			    printf("������Ҫ��ѯ�����kС��Ԫ��\n");
				k = judge_int();
				RandomArray(d,100);
				printf("�������飺\n");
				show(d,100);
				printf("\n��%dС��������%d\n",k,FoundGoal(d,0,99,k-1));
				free(d);
				system("pause");
				system("cls"); 
				break;
			}
			case 0:{//�˳�ϵͳ 
				system("cls");
				exit(0);
			}
			default:{
				printf("\n\t��Ǹ�������벻�Ϸ������������������˵�");
				system("pause");
				system("cls"); 
				fflush(stdin);       //������뻺����
				continue;
			}
		}
	}while(1);
	
	return 0;
	
}
