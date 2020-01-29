//  Created by Sergey Sterlikov on 22.06.2018.
//  Copyright © 2018 Sergey Sterlikov. All rights reserved.
//
#include <math.h>
#include <iostream>
using namespace std;

int  main()
{
    double a, b, x, h, r, s, y, w;
    int n, k;
    cout << "Input a,b,h,n" << endl;
    cin >> a >> b >> h >> n;
    for(x = a; x<=b; x+=h)
    {
        r = s = 1;
        //int k1 = 0;
        
        for(k = 1; k<=n; k++)
        {
           // k1 = k1*k;
            
            r = -r * x*x / (2*k*(2*k-1));
            
            s+=r*(2*k*k+1);
        }
        
        y = (1-(x*x)/2)*cos(x)-x/2*sin(x);
        w = fabs(y - s);
        
        cout <<"\n x = " << x << "\t   sum = " << s << "\t   y = " << y << "\t   |Y(x)–S(x)| = " << w;
    }
    cout << "\nPress any key ... " << endl;
    return 0;
}
