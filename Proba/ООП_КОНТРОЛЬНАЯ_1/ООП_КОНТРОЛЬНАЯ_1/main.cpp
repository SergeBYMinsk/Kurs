//
//  main.cpp
//  ООП_КОНТРОЛЬНАЯ_1
//
//  Created by Sergey Sterlikov on 11/3/18.
//  Copyright © 2018 Sergey Sterlikov. All rights reserved.
//

#include <iostream>
#include <string.h>
using namespace std;



// Worker: Имя name , Должность position, Год поступления на работу date, Зарплата salary.
// Создать массив объектов. Вывести:
// список работников, стаж работы которых на данном предприятии превышает заданное число лет;void spisdata
// список работников, зарплата которых больше заданной;void spissalary
// список работников, занимающих заданную должность.void spisposition


class Worker
{
private:
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
    cout << " Введите имя:";
    cin >> name;
    cout << " Введите должность:";
    cin >> position;
    cout << " Введите год поступления на работу:";
    cin >> data;
    cout << " Введите зарплату:";
    cin >> salary;
}

void Worker::show()
{
    cout << "Имя:" << name << endl;
    cout << "Должность:" << position << endl;
    cout << "Год поступления на работу:" << data << endl;
    cout << "Зарплата:" << salary << endl;
}

char *Worker::getposition()
{
    return position;
}
int Worker::getsalary()
{
    return salary;
}
int Worker::getdata()
{
    return data;
}

void spisposition(Worker spis[],int n)                      //список работников, занимающих заданную должность
{
    char position[30];
    cout << "Введите должность:";
    cin >> position;
    for(int i=0;i<n;i++)
        if(strcmp(spis[i].getposition(),position)==0)
        {
            spis[i].show();
            cout << "=====================================" << endl;
        }
}

void spissalary(Worker spis[], int n)                       //список работников, зарплата которых больше заданной
{
    int k;
    cout << "Введите зарплату:";
    cin >> k;
    //    int paid;
    for(int i=0;i<n;i++)
    {
        if (spis[i].getsalary()>=k)
        {
            spis[i].show();
        }
        cout << "=====================================" << endl;
    }
}

void spisdata(Worker spis[], int n)                         //список работников, стаж больше заданного
{
    int k;
    cout << "Введите стаж (стаж больше заданного):";
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

int main()
{
    Worker *spis;
    int n;
    cout << " Введите количество работников:"; cin>>n;
    spis=new Worker [n];
    for(int i=0;i<n;i++)
    {
        cout << "\n=============================="<<endl;
        spis[i].show();
    }
    cout << "\n=============================="<<endl;
    spisdata(spis,n);
    spissalary(spis,n);
    spisposition(spis,n);
    cout << "\n=============================="<<endl;
    spisposition(spis,n);
    cout << "\n=============================="<<endl;
    delete [] spis;
    
}
