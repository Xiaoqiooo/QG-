#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#define MAXSIZE 100
typedef enum Status 
{
    error, 
	ok
} Status;

typedef int ElemType;

int leftpri(char op);
int rightpri(char op);
Status ifop(char ch); 
int comparepri(char op1,char op2); 
int istrue(char *exp);
Status transform(char *exp,char newexp[]);
double endcounter(char *newexp);
void menu();
void HideCursor();
void gotoxy(int x,int y);
void playtime(); 
#endif 
