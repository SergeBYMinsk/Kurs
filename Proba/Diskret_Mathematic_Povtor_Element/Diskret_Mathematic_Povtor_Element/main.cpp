//
//  main.cpp
//  Diskret_Mathematic_Povtor_Element
//
//  Created by Sergey Sterlikov on 5/22/19.
//  Copyright © 2019 Sergey Sterlikov. All rights reserved.
//

//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//bool next_combination (vector<size_t>& a, size_t k)
//{
//    int n = (int) a.size();
//    for (long i=k-1; i>=0; --i)
//    {
//        if (a[i] < (int) (n-k+i))
//        {
//            ++a[i];
//            for (long j = i + 1; j < (int)k; ++j)
//                a[j] = a[j-1] + 1;
//            return true;
//        }
//    }
//
//    return false;
//}
//
//long k = 0;
//
//void dump(const string& str, const vector<size_t>& indices, size_t k)
//{
//    for(size_t i = 0; i < k; ++i)
//        putchar(str[indices[i]]);
//    putchar('\n');
//}
//
//class nat
//{
//public:
//    nat();
//    size_t operator () ();
//
//private:
//    size_t curr;
//};
//
//nat::nat()
//: curr(0)
//{
//}
//
//size_t nat::operator () ()
//{
//    return curr++;
//}
//
////функция ввода длинны последовательности
//void InputK()
//{
//    while (1)
//    {
//        cout << "Введите длинну последовательности (от 1 до 8): ";
//        cin >> k;
//        if (k >= 1)
//            if (k <= 8)
//                break;
//    }
//}
//
//int main()
//{
//    string str = "aabbbddc";
//    size_t size = str.size();
//    InputK();
//
//    vector<size_t> indices(size);
//    generate(indices.begin(), indices.end(), nat());
//
//    do
//    {
//        dump(str, indices, k);
//    }
//
//    while(next_combination(indices, k));
//
//    return 0;
//}

#include <iostream>
#include <string>
#include <cstring>
using namespace std;
// сочетания с повторениями  aa bbb cc d
//   Алгоритм сдвига массива
bool NextSet(string *mas1, string *mas, int k, int i)
{
    int j = 1, ii, jj, Kol = 8;
    if (k != 1) Kol = Kol - k + 1;
    
    if (i == 0 || i == 2 || i == 5 || i == 7)
    {
        j = 1;
        for(ii = i; ii < Kol ; ii++)
        {
            mas1[j] = mas[i];
            int KolPos = 1;
            for(jj = 1; jj < k; jj++)
            {
                mas1[j] =  mas1[j] + mas[ii+ jj];
                KolPos ++;
            }
            
            if (mas1[j] != mas1[j-1] && KolPos == k)
                j++;
            else
                mas1[j] = "";
        }
    }
    
    return true;
}

void Print(string *a)
{
    int i = 1;
    while(a[i] != "")
    {
        cout << a[i] << " ";
        cout << endl;
        i++;
    }
}

//функция ввода длинны последовательности
int InputK()
{
    int kk = 0;
    while (1)
    {
        cout << "Введите длинну последовательности (от 1 до 8): ";
        cin >> kk;
        if (kk >= 1)
            if (kk <= 8)
                break;
    }
    
    return kk;
}

int main()
{
    int k = 0;
    string *aa, *aaa;
    aa = new string[8];
    aa[0] = "a";
    aa[1] = "a";
    aa[2] = "b";
    aa[3] = "b";
    aa[4] = "b";
    aa[5] = "c";
    aa[6] = "c";
    aa[7] = "d";
    
    // последовательность aa bbb cc d
    k = InputK();
    aaa = new string[30];
    for (int j = 0; j < 30; j++)
        aaa[j] = "";
    
    for (int i = 0; 9 - k; i++)
    {
        NextSet(aaa, aa, k, i);
        Print(aaa);
        for (int j = 0; j < 30; j++)
            aaa[j] = "";
    }
    
    cin.get();
    cin.get();
    delete aaa;
    delete aa;
    
    return 0;
}
