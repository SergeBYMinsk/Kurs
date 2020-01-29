//
//  main.cpp
//  Sklad 1500
//
//  Created by Sergey Sterlikov on 20.08.2018.
//  Copyright © 2018 Sergey Sterlikov. All rights reserved.
//


#include <iostream>
#include <string.h>
using namespace std;



// Worker: Фамилия и инициалы name , Должность position, Год поступления на работу date, Зарплата salary.
// Создать массив объектов. Вывести:
// список работников, стаж работы которых на данном предприятии превышает заданное число лет;
// список работников, зарплата которых больше заданной;
// список работников, занимающих заданную должность.


//======= class worker =================
class Worker
{ private:
    char name[30];
    char position[30];
    int data;
    int salary;
    
public:
    Worker();
    char *getname();
    char *getposition();
    int getsalary();
    int getdata();
    
    void show();
};

Worker::Worker()
{
    cout<<" Введите имя:";
    cin >> name;
    cout<<" Введите должность:";
    cin >> position;
    cout<<" Введите год поступления на работу:";
    cin >> data;
    cout<<" Введите зарплату:";
    cin >> salary;
}

void Worker::show()
{
    cout << "Имя:" << name << endl;
    cout << "Должность:" << position << endl;
    cout << "Год поступления на работу:" << data << endl;
    cout << "Зарплата:" << salary <<endl;
}

char *Worker::getposition() {return position;}
int Worker::getsalary() {return salary;}
int Worker::getdata() {return data;}

void spisposition(Worker spis[],int n)//список работников, занимающих заданную должность
{
    char position[30];
    cout<<" #Введите должность:";
    cin>>position;
    for(int i=0;i<n;i++)
        if(strcmp(spis[i].getposition(),position)==0)
        {
            spis[i].show();
            cout << "=====================================" << endl;
        }
}
void spissalary(Worker spis[], int n)//список работников, зарплата которых больше заданной
{
    int k;
    cout << "Введите зарплату:";
    cin >> k;
//    int paid;
    for(int i=0;i<n;i++)
    {
        if (spis[i].getsalary()>=k) {spis[i].show();
    }
        cout << "=====================================" << endl;
    }
}
void spisdata(Worker spis[], int n)//список работников, стаж больше заданного
{
    int k;
    cout << "Введите стаж:";
    cin >> k;
//    int data;
    for(int i=0;i<n;i++)
    {
        if ((2019-spis[i].getdata())>k)
        {
            spis[i].show();
        }
        cout << "=====================================" << endl;
    }
}
//========= main ================
int main()
{
    Worker *spis;
    int n;
    cout<<" Введите количество работников:"; cin>>n;
    spis=new Worker [n];
    for(int i=0;i<n;i++)
    {
        cout<<"\n=============================="<<endl;
        spis[i].show();
    }
    cout<<"\n=============================="<<endl;
    spisdata(spis,n);
    spissalary(spis,n);
    spisposition(spis,n);
    cout<<"\n=============================="<<endl;
    delete [] spis;
    
}
