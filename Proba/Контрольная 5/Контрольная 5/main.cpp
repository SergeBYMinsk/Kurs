//  Контрольная 5
//  Created by Sergey Sterlikov on 12.06.2018.
//  Copyright © 2018 Sergey Sterlikov. All rights reserved.

#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    double n;
    int i, sum = 0;
    const int N = 10;
    int a[N], plus = -2;
    do                              // проверка ввода
    {
        cout << " Введите размер массива (<=10) ";
        cin >> n;
    }
    while ( n < 1 || n > 10 ) ;                             // проверка ввода
    
    for (i = 0; i < n; i++)
    {
        cout<<"a["<<i+1<<"]= ";
        cin >> a[i];                        // вводим значения элементов массива
    }
    for (i = 0; i < n; i++)
    {
      if (a[i] > 0)
      {
        plus = i;
        break;
      }
    }
    if ( plus < 0 )
    {
        cout << "нет положительного" << endl;
        return 0;
    }
    if ( plus == n-1 )
    {
        cout << "последнее положительное" << endl;
        return 0;
    }
    for (i = plus+1; i < n; i++)
        sum += a[i];
    
    cout << "Сумма элементов расположенных после первого положительного  = " << sum <<endl;
    
    return 0;
}

