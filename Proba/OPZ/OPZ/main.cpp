//  main.cpp
//  OPZ
//  Created by Sergey Sterlikov on 18.09.2018.
//  Copyright © 2018 Sergey Sterlikov. All rights reserved.
#include <iostream>
#include <string.h>


using namespace std;

struct Stack
{
    char info;
    Stack *next;
} *begin;
int Prior (char);
Stack* InStack(Stack*, char);
Stack* OutStack(Stack*, char*);
void Del_All(Stack **);
double Rezult(char*, double*);

//---------------------------------------------------

int main()
{
    char InStr[81] = "", OutStr[81]="", ss, a;      // входная выходная строки
    Stack *begin = NULL;
    long len, k, i;
    double masDat[50];                      // Массив для вычисления
    cout << "\n Input String : ";
    cin >> InStr;
    len = strlen(InStr);                    // кол-во введённых символов
    for (i = k = 0; k < len; k++)           //
    {
        ss = InStr[k];      // присвоили ss последовательно учитывая цикл символа из строки по очередно
        if ( ss == '(' )                    //   Если «(», записываем ее в стек
            begin = InStack(begin, ss);
        if ( ss == ')' )// Если «)», извлекаем из стека в строку Out все операции до открывающей скобки
        {
            while (begin -> info != '(' )
            {
                begin = OutStack(begin,&a);
                OutStr[i++] = a;
            }
            begin = OutStack(begin,&a);
        }
        if (ss >=  'a' && ss <= 'z' )                   //   Если символ – буква, заносим ее в Out
            OutStr[i++] = ss;
        // извлекаем из стека в Out опе-рации с большим или равным приоритетом

        if (ss == '-' || ss == '+' || ss == '*' || ss == '/')
        {
            while ( begin != NULL && Prior (begin -> info) >= Prior (ss) )
            {
                begin = OutStack(begin, &a);
                OutStr[i++] = a;
            }
            begin = InStack(begin, ss); // Текущий символ – в стек
        }
    }
    //  Если стек не пуст, переписываем все операции в выходную строку
    while ( begin != NULL)
    {
        begin = OutStack(begin, &a);
        OutStr[i++] = a;
    }
    OutStr[i] = '\0';
    cout << "\n Poliz = " << OutStr << endl;
    cout << "\n String = " << InStr << endl;
    len = strlen(OutStr);
    for(k = i = 0; i < len; i++)
        if(OutStr[i] >= 'a' && OutStr[i] <= 'z')
        {
            cout << " Input " << OutStr[i] << " : ";
            cin >> masDat[(int)OutStr[i] - 97];
        }
    cout << "\n Result = " << Rezult(OutStr, masDat) << endl;
    cout << "\n Press any key..." << endl;
    return 0;
}
//------------------ расстановка приоритетов ---------------------------
int Prior ( char a )
{
    switch ( a )
    {
        case '*':     case '/':     return 3;
        case '-':     case '+':     return 2;
        case '(':             return 1;
    }
    return 0;
}
//-------------------- расчёт результата ---------------------------------
double Rezult( char *Str, double *mas)              
{
    Stack *begin = NULL;
    char ch, ch1, ch2, chr = 'z'+1;
    double op1, op2, rez = 0;
    long i, len;
    len = strlen(Str);
    for (i = 0; i < len; i++)
    {
        ch = Str[i];
        if (ch >= 'a' && ch <= 'z')
            begin = InStack(begin, ch);
        else
        {
            begin = OutStack(begin,&ch1);
            begin = OutStack(begin,&ch2);
            op2 = mas[int (ch1) - 97];
            op1 = mas[int (ch2) - 97];
            //-- Функция реализации приоритета операций --
            switch (ch)
            {
                case '+' :     rez=op1+op2;      break;
                case '-' :     rez=op1-op2;      break;
                case '*' :     rez=op1*op2;      break;
                case '/' :
                    if(op2 != 0)
                        rez=op1/op2;
                    else
                    {
                        cout << "\n Denominator = 0!" << endl;
                        return 0;
                    }
                    break;
            }
            mas[int (chr) - 97] = rez;
            begin = InStack(begin,chr);
            chr++;
        }
    }
    return rez;
}
//--------------------------- ‘удаление стека --------------------------------
void Del_All(Stack **p)
{
    Stack *t;
    while(*p != NULL)
    {
        t = *p;
        *p = (*p) -> next;
        delete t;
    }
}
//---- поместить запись в стек -----
Stack* InStack(Stack *p, char in)
{
    Stack *t = new Stack;
    t -> info = in;
    t -> next = p;
    return t;
}
//---- извлечь запись из стека -----
Stack* OutStack(Stack* p, char *out)
{
    Stack *t = p;
    *out = p -> info;
    p = p -> next;
    delete t;
    return p;
}
