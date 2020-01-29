//  File
//
//  Created by Sergey Sterlikov on 10/19/18.
//  Copyright © 2018 Sergey Sterlikov. All rights reserved.
//Программа предоставляет сведения о товарах, имеющихся на складе: наименование товара; количество единиц
//товара; цена единицы товара; дата поступления товара на склад; ФИО зарегистрировавшего товар.
//Индивидуальное задание: вывести в алфавитном порядке список товаров, хранящихся более x месяцев, стоимость
//которых превышает y рублей (x, y вводятся с клавиатуры).
//  main.cpp
//  kursovoi
//

#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <memory.h>
#include <iomanip>

using namespace std;

struct Products    //Создаем структуру!
{
    short ID;      // уникальное поле
    char NameT[30];  //наименование товара;
    char FIO[30];    //ФИО зарегистрировавшего товар
    int dateT[3];   //дата поступления товара на склад
    short quantity; //количество единиц товара
    short price;    //цена единицы товара
    
};

const char *FName="DateSklad.txt";; //Путь к файлу.

int CheckPass ()
{
    string log1, pass1;
    int int1 = -1;
    cout <<"Введите логин" << endl;
    cin >> log1;
    cout <<"Введите пароль" << endl;
    cin >> pass1;
    ifstream access("access.txt");
    if (!access.is_open()) cout<<"not open file!";
    string str1, sAdmin, sUser;
    sAdmin = log1  + "/" +  pass1 + "/0/";
    sUser = log1  + "/" + pass1 + "/1/";
    while (!access.eof())
    {
        if (access.eof())
            break;
        access >> str1;
        
        if (sAdmin == str1)
        {
            int1 = 0;
            break;
        }
        if (sUser == str1)
        {
            int1 = 1;
            break;
        }
    }
    
    access.close();
    return int1;
}

void ViewList()
{
    ifstream access("access.txt");
    if (!access.is_open())
    {
        cout<<"Файл не открыт!";
    }
    else
    {
        string str1;
        long ii = 1;
        cout << "\n---------Список имеющихся логинов/паролей---------\n" << endl;
        while (!access.eof())
        {
            if (access.eof())
                break;
            str1 = "";
            access >> str1;
            if (str1 != "")
                cout << ii << ". " << str1 << endl;
            ii++;
        }
    }
}

int AddLogPass()
{
    ofstream accessf;     //создаем поток
    accessf.open("access.txt", ios::app);  // открываем файл для записи
    string log, pass, sUser;
    cout << "Введите новый Логин!" << endl;
    cin >> log;
    cout << "Введите новый Пароль!" << endl;
    cin >> pass;
    sUser = log  + "/" + pass + "/1/";
    accessf << sUser << '\n'; ; // сама запись
    accessf.close();   // закрываем файл
    return 0;
}

int DelLogPass ()
{
    setlocale(LC_ALL,"Russian_Russia.1251");
    std::ifstream file_in;
    file_in.open("access.txt");
    if(!file_in)
    {
        std::cerr << "Ошибка, невозможно открыть файл : access.txt" << std::endl;
        return (EXIT_FAILURE);
    }
    ViewList();
    cout <<"\n\tВведите номер строки для удаления :"<< endl;
    int i_number_line_delete = 0; //для хранения номера строки который нужно удалить
    cin >> i_number_line_delete;
    int i_number_line_now = 0; //счётчик строк
    string line; //для хранения строки
    string line_file_text; //для хранения текста файла
    while(getline(file_in,line))
    {
        i_number_line_now++;
        if(!(i_number_line_now == i_number_line_delete))
        {
            line_file_text.insert(line_file_text.size(),line); /*дабавить строку*/
            /*добавить перенос на слудующую строку*/
            line_file_text.insert(line_file_text.size(),"\r\n");
        }
    }
    file_in.close();
    ofstream file_out;
    file_out.open ("access.txt",std::ios::trunc | std::ios::binary); //открыть и обрезать
    file_out.write(line_file_text.c_str(), line_file_text.size());   //записать
    file_out.clear();
    return 0;
}

int AdminMenu1 ()
{
    while(true)
    {
        cout<<"\n-------Меню администратора работа с логин/пароль-------\n";
        int kod;
        cout << "\n\tПросмотр всех логин/паролей - 1.\n\tДобавить новый логин/пароль - 2.\n\tудалить логин/пароль - 3.\n\tВыход – 0.  :  " ;
        cin >> kod;
        switch(kod)
        {
            case 1:
            {
                ViewList();
                break;
            }
            case 2:
            {
                AddLogPass();
                break;
            }
            case 3:
            {
                DelLogPass ();
                break;
            }
            case 0:
                return 0;        // Выход – EXIT
        }
    }
}

int CreateFile()
{
    
    Products prodmem;    //Записываемый в файл объект структуры
    cout << "Добавить порядковый номер:" << endl;   /*ЗАПОЛНЯЕМ СТРУКТУРУ*/
    cin >> prodmem.ID;
    cout << "Введите наименование товара:" << endl;
    cin >> prodmem.NameT;
    cout << "Введите дату (через пробел 'DD MM YYYY'): "<< endl;
    cin >> prodmem.dateT[0] >> prodmem.dateT[1] >> prodmem.dateT[2];
    cout << "Веедите ФИО:" << endl;
    cin >> prodmem.FIO;
    cout << "Введите количество:" << endl;
    cin >> prodmem.quantity;
    cout << "Введите цену:" << endl;
    cin >> prodmem.price;
    ifstream f1(FName);         /*Записываем структуру в файл*/
    if (f1.is_open())
    {
        f1.close();
        cout<<"\n\tФайл уже существует!\n";
    }
    else
    {
        ofstream f1(FName, ios::out);
        f1<<prodmem.ID<<" "<< prodmem.NameT<<" "<< prodmem.FIO << " " <<prodmem.dateT[0] << " " <<prodmem.dateT[1] << " " << prodmem.dateT[2] << " " << prodmem.quantity << " " <<prodmem.price<< endl;
        f1.close();
    }
    return 0;
}

int OpenFile()
{
    ifstream f1(FName);
    if (!f1.is_open())
    {
        cout<<"\n\tФайл не существует \n";
    }
    else
        cout<<"\n\tnФайл открыт \n";
    return 0;
}

int DeleteFile()
{
    if (remove(FName))
    {
        cout<<"Ошибка удаления файла! \n";
    }
    return 0;
}

int AdminMenu2 ()
{
    while(true)
    {
        cout<<"\n-------Меню адмистратора файл данных-------\n";
        int kod;
        cout << "\n\tСоздать файл - 1.\n\tОткрыть файл - 2.\n\tУдалить файл - 3.\n\tВыход – 0.  :  " ;
        cin >> kod;
        switch(kod)
        {
            case 1:
                CreateFile();
                break;
            case 2:
                OpenFile();
                break;
            case 3:
                DeleteFile();
                break;
            case 0:
                return 0;        // Выход – EXIT
        }
    }
}

int ViewDateStr()
{
    ifstream f2(FName, ios::in);
    if (!f2.is_open())
    {
        cout<<"Файл не существует \n";
        return 0;
    }
    cout << "-------------Перечень товара----------------"  << '\n';
    cout << setw(6) <<"№ п/п "
    << setw(30) << "Наименование товара "
    << setw(12) << "          Дата "
    << setw(30) << left << "       ФИО   "
    << setw(20) << right << "         Количество "
    << setw(10) << right << "     Цена " << '\n';
    
    int number, i=0;
    Products arr_new_of_prod[200];
    while (!f2.eof())
    {
        f2 >> arr_new_of_prod[i].ID >> arr_new_of_prod[i].NameT >>arr_new_of_prod[i].FIO >>arr_new_of_prod[i].dateT[0] >> arr_new_of_prod[i].dateT[1] >>arr_new_of_prod[i].dateT[2] >> arr_new_of_prod[i].quantity >> arr_new_of_prod[i].price;
        i++;
    }
    number = i;
    f2.close(); //Закрыли открытый файл
    for (int i=0; i<number-1; i++)
    {
        if (arr_new_of_prod[i].quantity > 0)
            cout<< setw(6) << left << arr_new_of_prod[i].ID
            << setw(30) << left << arr_new_of_prod[i].NameT
            << left << arr_new_of_prod[i].dateT[0] <<"." << setw(2) << arr_new_of_prod[i].dateT[1] << "." << setw(6) <<arr_new_of_prod[i].dateT[2]
            << setw(30) << left << arr_new_of_prod[i].FIO
            << setw(10) << right << arr_new_of_prod[i].quantity
            << setw(10) << right << arr_new_of_prod[i].price << '\n';
    }
    return 0;
}

int AddDateStr()
{
    Products prodmem;    //Записываемый в файл объект структуры
    cout << "Добавить порядковый номер:" << endl;            /*ЗАПОЛНЯЕМ СТРУКТУРУ*/
    cin >> prodmem.ID;
    cout << "Введите наименование товара:" << endl;
    cin >> prodmem.NameT;
    cout << "Введите дату (через пробел 'DD MM YYYY'): " << endl;
    cin >> prodmem.dateT[0] >> prodmem.dateT[1] >> prodmem.dateT[2];
    cout << "Веедите ФИО:" << endl;
    cin >> prodmem.FIO;
    cout << "Введите количество:" << endl;
    cin >> prodmem.quantity;
    cout << "Введите цену:" << endl;
    cin >> prodmem.price;
    
    ofstream f1(FName, ios::app);            /*Записываем структуру в файл*/
    f1<<prodmem.ID<<" "<< prodmem.NameT<<" "<< prodmem.FIO << " " <<prodmem.dateT[0] << " " <<prodmem.dateT[1] << " " << prodmem.dateT[2] << " " << prodmem.quantity << " " <<prodmem.price<< endl;
    f1.close();
    return 0;
}

void DeleteDateStr()
{
    setlocale(LC_ALL,"Russian_Russia.1251");
    std::ifstream file_in;
    file_in.open("DateSklad.txt");
    if(!file_in)
    {
        std::cerr << "Ошибка, невозможно открыть файл : DateSklad.txt" << std::endl;
    }
    else
    {
        ViewDateStr();
        std::cout <<"Введите номер строки для удаления/редактирования :"<< std::endl;
        int i_number_line_delete = 0; //для хранения номера строки который нужно удалить
        std::cin >> i_number_line_delete;
        int i_number_line_now = 0; //счётчик строк
        std::string line; //для хранения строки
        std::string line_file_text; //для хранения текста файла
        while(getline(file_in,line))
        {
            i_number_line_now++;
            if(!(i_number_line_now == i_number_line_delete))
            {
                line_file_text.insert(line_file_text.size(),line); /*дабавить строку*/
                line_file_text.insert(line_file_text.size(),"\r\n");        /*добавить перенос на слудующую строку*/
            }
        }
        file_in.close();
        std::ofstream file_out;
        file_out.open ("DateSklad.txt",std::ios::trunc); //открыть и обрезать
        file_out.write(line_file_text.c_str(), line_file_text.size());
        file_out.clear();
    }
}

void EditDateStr()
{
    DeleteDateStr();
    AddDateStr();
}

int KolMonth(int dat, int months, int years, int kolMonth)
{
    if (years < 2018)
    {
        if (kolMonth == 12 && years == 2017 && months == 12)
            return 0;
        else
            return 1;
    }
    else
    {
        if ((11 - months) < kolMonth)
            return 0;
        else
            return 1;
    }
}

int IndvTask()
{
    ifstream f4(FName, ios::in);
    if (!f4.is_open())
    {
        cout<<"Файл не существует \n";
        return 0;
    }
    
    int number, i=0;
    Products arr_new_of_prod[200], arr_prod[200];
    while (!f4.eof())
    {
        f4 >> arr_new_of_prod[i].ID >> arr_new_of_prod[i].NameT >>arr_new_of_prod[i].FIO>>arr_new_of_prod[i].dateT[0] >> arr_new_of_prod[i].dateT[1] >>arr_new_of_prod[i].dateT[2] >> arr_new_of_prod[i].quantity >> arr_new_of_prod[i].price;
        i++;
    }
    
    number = i;
    f4.close(); //Закрыли открытый файл
    
    int x,y;
    while (true)
    {
        cout << "Введите количество месяцев:" << endl;
        cin >> x;
        if (x > 12)
            cout << "Количество месяцев не может превышать 12!" << endl;
        else
            break;
    }
    cout << "Введите сумму:" << endl;
    cin >> y;
    for (int i=0; i<number-2; i++)
    {
        for(int j(number-2); j >= i; j--)
        {
            for(int k(0); arr_new_of_prod[j-1].NameT[k]; k++)
            {
                if(arr_new_of_prod[j-1].NameT[k] > arr_new_of_prod[j].NameT[k])
                {
                    arr_prod[0] = arr_new_of_prod[j-1];
                    arr_new_of_prod[j-1] = arr_new_of_prod[j];
                    arr_new_of_prod[j] = arr_prod[0];
                    break;
                } // если буква первого слова больше чем буква второго, то меняем местами слова и переходим к следующему
                else
                {
                    if(arr_new_of_prod[j-1].NameT[k] == arr_new_of_prod[j].NameT[k])
                        continue; // если буквы равны, то проверяем следующую букву
                    else
                        break;
                }
            }
        }
    }
    cout << "--- Перечень отсортированных по наименованию товаров, стоимость которых превышает " << y << " руб ---"  << '\n';
    cout << setw(6) <<"№ п/п "
    << setw(30) << "Наименование товара "
    << setw(12) << "          Дата "
    << setw(30) << left << "      ФИО   "
    << setw(20) << right << "         Количество "
    << setw(10) << right << "     Цена " << '\n';
    
    for (int i=0; i<number-1; i++)
    {
        if (arr_new_of_prod[i].price > y)
            if (KolMonth(arr_new_of_prod[i].dateT[0], arr_new_of_prod[i].dateT[1], arr_new_of_prod[i].dateT[2], x) != 0)
                cout<< setw(6) << left << arr_new_of_prod[i].ID
                << setw(30) << left << arr_new_of_prod[i].NameT
                << left << arr_new_of_prod[i].dateT[0] <<"." << setw(2)<< arr_new_of_prod[i].dateT[1] << "." << setw(6) <<arr_new_of_prod[i].dateT[2]
                << setw(30) << left << arr_new_of_prod[i].FIO
                << setw(10) << right << arr_new_of_prod[i].quantity
                << setw(10) << right << arr_new_of_prod[i].price << '\n';
    }
    cout << '\n';
    return 0;
}

int SortDate()
{
    ifstream f4(FName, ios::in);
    if (!f4.is_open())
    {
        cout<<"Файл не существует \n";
        return 0;
    }
    int number, i=0;
    Products arr_new_of_prod[200], arr_prod[200];
    while (!f4.eof())
    {
        f4 >> arr_new_of_prod[i].ID >> arr_new_of_prod[i].NameT >>arr_new_of_prod[i].FIO>>arr_new_of_prod[i].dateT[0] >> arr_new_of_prod[i].dateT[1] >>arr_new_of_prod[i].dateT[2] >> arr_new_of_prod[i].quantity >> arr_new_of_prod[i].price;
        
        i++;
    }
    number = i;
    f4.close(); //Закрыли открытый файл
    
    for (int i=0; i<number-2; i++)
    {
        for(int j(number-2); j >= i; j--)
        {
            for(int k(0); arr_new_of_prod[j-1].NameT[k]; k++)
            {
                if(arr_new_of_prod[j-1].NameT[k] > arr_new_of_prod[j].NameT[k])
                {
                    arr_prod[0] = arr_new_of_prod[j-1];
                    arr_new_of_prod[j-1] = arr_new_of_prod[j];
                    arr_new_of_prod[j] = arr_prod[0];
                    break;
                    
                } // если буква первого слова больше чем буква второго, то меняем местами слова и переходим к следующему
                else
                {
                    if(arr_new_of_prod[j-1].NameT[k] == arr_new_of_prod[j].NameT[k])
                        continue; // если буквы равны, то проверяем следующую букву
                    else
                        break;
                }
            }
        }
    }
    cout << "-------------Перечень отсортированного по наименованию товара----------------"  << '\n';
    cout << setw(6) <<"№ п/п "
    << setw(30) << "Наименование товара "
    << setw(12) << "          Дата "
    << setw(30) << left << "      ФИО   "
    << setw(20) << right << "         Количество "
    << setw(10) << right << "     Цена " << '\n';
    
    for (int i=0; i<number-1; i++)
    {
        cout<< setw(6) << left << arr_new_of_prod[i].ID
        << setw(30) << left << arr_new_of_prod[i].NameT
        << left << arr_new_of_prod[i].dateT[0] <<"." << setw(2) <<arr_new_of_prod[i].dateT[1] << "." << setw(6) <<arr_new_of_prod[i].dateT[2]
        << setw(30) << left << arr_new_of_prod[i].FIO
        << setw(10) << right << arr_new_of_prod[i].quantity
        << setw(10) << right << arr_new_of_prod[i].price << '\n';
    }
    cout << '\n';
    return 0;
}

int AdminMenu3 ()
{
    while(true)
    {
        cout<<"\n-------Меню администратора по работе с данными склада-------\n";
        int kod;
        cout << "\n\tПросмотр данных- 1.\n\tДобавление новых данных - 2.\n\tУдаление данных - 3.\n\tРедактирование данных - 4.\n\tИндивидуальное задание- 5.\n\tСортировка данных- 6.\n\tВыход – 0.  :  " ;
        cin >> kod;
        switch(kod)
        {
            case 1:
                ViewDateStr();
                break;
            case 2:
                AddDateStr();
                break;
            case 3:
                DeleteDateStr();
                break;
            case 4:
                EditDateStr();
                break;
            case 5:
                IndvTask();
                break;
            case 6:
                SortDate();
                break;
            case 0:
                return 0;        // Выход – EXIT
        }
    }
}

int AdminMenu ()
{
    
    while(true)
    {
        cout<<"\n-------Меню Администратора-------\n";
        int kod;
        cout << "\n\tРабота с логин/паролями - 1.\n\tРабота с файлом данных - 2.\n\tРабота с данными склада - 3.\n\tВыход – 0.  :  " ;
        cin >> kod;
        switch(kod)
        {
            case 1:
                AdminMenu1();
                break;
            case 2:
                AdminMenu2();
                break;
            case 3:
                AdminMenu3();
                break;
                
            case 0:
                return 0;        // Выход – EXIT
        }
    }
}

int UserMenu()
{
    while(true)
    {
        cout<<"-------Меню пользователя--------\n";
        int kod;
        cout << "\n\tПросмотр данных - 1.\n\tИндивидуальное задание - 2.\n\tСортировка данных- 3.\n\tEXIT – 0.  :  " ;
        cin >> kod;
        switch(kod)
        {
            case 1:
                ViewDateStr();
                break;
            case 2:
                IndvTask();
                break;
            case 3:
                SortDate();
                break;
            case 0:
                return 0;        // Выход – EXIT
        }
    }
    
    return 0;
}

int main ()
{
    setlocale(LC_ALL,"rus");
    int int2 = -1;
    while (true)
    {
        int2 = CheckPass();
        if (int2 == -1)
            cout<<"Неправильный пароль\n";
        else
            break;
    }
    if (int2 == 0)
    {
        AdminMenu();
    }
    else
    {
        UserMenu();
    }
    return 0;
}
