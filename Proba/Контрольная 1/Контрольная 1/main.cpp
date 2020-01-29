//  Контрольная 1
//  Created by Sergey Sterlikov on 06.06.2018.
//  Copyright © 2018 Sergey Sterlikov. All rights reserved.

#include <iostream>
#include <math.h>
#pragma hdrstop
#pragma argsused
using namespace std;

int main()
{
    setlocale(0, "");
    double x, y, z, a, b ,c, res;
    cout << "Введи значения x\nX= ";
    cin >> x;
    cout << "Введи значения y\nY= ";
    cin >> y;
    cout << "Введи значения z\nZ= ";
    cin >> z;
    a = pow(2,pow(y,x))+pow(pow(3,x),y);
    b = y*(atan(z)-3.1415926535/6);
    c = fabs(x)+(1/(pow(y,2)+1));
    res = a-(b/c);
    cout << "\nX= " << x << "\nY= " << y << "\nZ= " << z << "\nРезультат вычисления:\n "
    << res << endl;
 
    return 0;
}


