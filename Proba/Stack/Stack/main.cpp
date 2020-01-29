//  main.cpp
//  Stack
//  Created by Sergey Sterlikov on 02.09.2018.
//  Copyright © 2018 Sergey Sterlikov. All rights reserved.
#include <iostream>
using namespace std;

struct Stack
{                // Декларация структурного типа
    int info;
    Stack * next;
} *t;

Stack* InStack(Stack *p, int in)
{
    Stack *t = new Stack;            // Захватываем память для элемента
    t -> info = in;            // Формируем информационную часть
    t -> next = p;            // Формируем адресную часть
    return t;
}
void View(Stack *p)
{
    Stack *t = p;
    while( t != NULL)
    {
        cout <<  t -> info << endl;                        // Вывод на экран информационной части
        t = t -> next;
    }
}
void Sort_p(Stack **p)
{
    Stack *p1=0;
    Stack *t2=p1;
    int ii = 5;
    t2= InStack(t2, ii);
    Stack *t = NULL, *t1, *r;
    if ((*p) -> next -> next == NULL) return;
    do
    {
        for (t1=*p; t1-> next->next  != t; t1=t1-> next)
        if (t1->next->info  >  t1-> next-> next-> info)
            {
                r = t1->next->next;
                t1 -> next -> next = r -> next;
                r-> next =t1-> next;
                t1-> next = r;
            }
        t= t1-> next;
    }
    while ((*p)-> next -> next != t);
}
void Sort_info(Stack *p)
{
    Stack *t = NULL, *t1;
    int r;
    do
        {
        for (t1=p; t1 -> next != t; t1 = t1-> next)
            if (t1-> info > t1-> next -> info)
                {
                    r = t1-> info;
                    t1-> info = t1-> next -> info;
                    t1-> next -> info = r;
                }
        t = t1;
        }
    while (p -> next != t);
}
void xcode(Stack *p)
{
    Stack *t = p;
    while( t != NULL)
    {
        if (t -> info % 2 == 0)
            {
                cout << t -> info << " ";
            }
        t = t -> next;
    }
}
void xcode1(Stack *p)
{
    Stack *t = p;
    while( t != NULL)
    {
        if (t -> info % 2 != 0)
        cout << t -> info << " ";
        t = t -> next;
    }
}
Stack* OutStack(Stack *p, int *out)
{
    Stack *t = p;            // Устанавливаем указатель t на вершину p
    *out = p -> info;
    p = p -> next;         // Переставляем вершину p на следующий
    delete t;             // Удаляем бывшую вершину t
    return p;             // Возвращаем новую вершину p
}
void Del_All(Stack **p)
{
    Stack *t;
    while( *p != NULL)
    {
        t = *p;
        *p = (*p) -> next;
        delete t;
    }
}
void Del_First(Stack **p) //  удаляем первый элемент стека
{
    Stack *t;
    t = *p;
    *p = (*p) -> next;
    delete t;
}
int main()
{
    setlocale(0,"");
    int i, in, n, kod;
    Stack *p=0;
    Stack *t=p;
    while(true)
    {
        cout << "\n\tСоздать - 1.\n\tДобавить - 2.\n\tПросмотреть - 3.\n\tУдалить - 4.\n\tСписок чётные и нечётные – 5.\n\tВыход – 0.  :  " ;
        cin >> kod;
        
        switch(kod) {
            case 1: case 2:
                if(kod == 1 && t != NULL){
//                           Если создаем новый стек, должны освободить память, занятую предыдущим
                    cout << "--- Память очищена ---" << endl;
                    break;
                }
                cout << "--- Введите кол-во --- ";         cin >> n;
                for(i = 1; i <= n; i++)  {
                    in = -20+rand()%(40);                                           // заполняем стемик случайными числами
                    t = InStack(t, in);
                }
                if (kod == 1) cout << "--- Создан Stack ---" << n << endl;
                else cout << "--- Добавлены новые элементы --- " << n << endl;
                break;
            case 3:         if(!t)
                {
                    cout << "--- Stack ПУСТ ---" << endl;
                    break;
                }
                cout << "--- Ваш Stack ---" << endl;
                View(t);
                break;
            case 4:
                Del_All(&t);
                cout<<"--- Память очищена ---"<<endl;
                break;
            case 5:
                cout<<"--- Чётные ---"<<endl;
                xcode(t);
                cout << endl;
                cout<<"--- Нечётные ---"<<endl;
                xcode1(t);
                break;
            case 10:
                for(i = 1; i <= 1; i++)
                {
                    in = rand();
                    t = InStack(t, in);                     //добавляем в стек любое значение, которое удалим после сортировки, чтобы учесть первый элемент
                }
                Sort_p(&t);
                cout<<"--- Сортировка окончена ---"<<endl;
                Del_First(&t);                                          // удаляем добавленный элемент стека для сортировки
                break;
            case 11:
                Sort_info(t);;
                cout<<"--- Сортировка окончена ---"<<endl;
                break;
          
            case 0:
                if(t != NULL)
                    Del_All(&t);
                return 0;
           
               
        }
    }
}
