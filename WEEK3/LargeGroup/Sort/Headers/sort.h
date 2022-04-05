#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#define simple 10000
#define medium 50000 
#define senior 200000 
#define text 100
#define times 100000 

/**

 *  @name        : void insertSort(int *a,int n);
 *  @description : ���������㷨
 *  @param       : ����ָ�� a, ���鳤�� n
    */
    void insertSort(int *a,int n);


/**

 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : �鲢���򣨺ϲ����飩
 *  @param       : ����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
    */
    void MergeArray(int *a,int begin,int mid,int end,int *temp);


/**

 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : �鲢����
 *  @param       : ����ָ��a���������begin�������յ�end����������ָ��temp
    */
    void MergeSort(int *a,int begin,int end,int size,int *temp);


/**

 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : �������򣨵ݹ�棩
 *  @param       : ����ָ��a���������begin�������յ�end
    */
    void QuickSort_Recursion(int *a, int begin, int end);


/**

 *  @name        : void QuickSort(int *a,int size)
 *  @description : �������򣨷ǵݹ�棩
 *  @param       : ����ָ��a�����鳤��size
    */
    void QuickSort(int *a,int size);


/**

 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : �������������ţ�
 *  @param       : ����ָ��a���������begin�������յ�end
    */
    int Partition(int *a, int begin, int end);


/**

 *  @name        : void CountSort(int *a, int size)
 *  @description : ��������
 *  @param       : ����ָ��a�����鳤��size
    */
    void CountSort(int *a, int size);


/**

 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : ������������
 *  @param       : ����ָ��a�����鳤��size
    */
    void RadixCountSort(int *a,int size);


/**

 *  @name        : void ColorSort(int *a,int size)
 *  @description : ��ɫ����
 *  @param       : ����ָ��a��ֻ��0��1��2Ԫ�أ������鳤��size
    */
    void ColorSort(int *a,int size);


/**

 *  @name        : ����
 *  @description : ��һ�������������ҵ���KС����
 *  @param       : ����ָ��a�����鳤��size
    */
    int FoundGoal(int *a,int begin,int end,int k);
    
/**

 *  @name        : int *a RandomArray(int *a,int size) 
 *  @description : ����������ĺ��� 
 *  @param       : ����ָ��a�����鳤��size
 *  @return      : ����ָ��a 
    */
    int* RandomArray(int *a,int size);

int GetDigit(int m, int i); //ȡ����m�ĵ�iλ��
int GetMaxDigit(int* a,int size);
int GetNumOfData(int data,int width);
int* RandomArrays(int *a,int size);
void show(int *a,int n);
int judge_int();
void menu();
void HideCursor();
void gotoxy(int x,int y);
void playtime(); 


#endif // QUEUE_H_INCLUDED
