//
//  main.cpp
//  Graph Search
//
//  Created by Sergey Sterlikov on 11/6/19.
//  Copyright © 2019 Sergey Sterlikov. All rights reserved.
//

                            //Алгоритм Дейкстры


//#include <iostream>
//#include <vector>
//using namespace std;
//
//void Dijkstra(vector<vector<pair<int, int>>>&, int&);
//
//int main() {
//    //==========================================================//
//    // Список смежности (рис. 8)                                //
//    // представляет собой вектор векторов пар.                  //
//    // Первый элемент пары смежная вершина (в массиве 1-я - 0), //
//    // а второй элемент - вес инцидентного ребра                //
//    //==========================================================//
//    vector<vector<pair<int, int>>> G {
//        { {1, 1}, {3, 6}                                 }, // 1
//        { {0, 1}, {2, 4}, {3, 3}, {4, 9}, {5, 8}, {6, 7} }, // 2
//        { {0, 6}, {1, 4}                                 }, // 3
//        { {1, 3}, {4, 2}                                 }, // 4
//        { {3, 2}, {1, 9}                                 }, // 5
//        { {1, 8}, {6, 5}                                 }, // 6
//        { {1, 7}, {5, 5}                                 }  // 7
//    };
//    int vortex;
//    cout << "Введите номер вершины: ";
//    cin >> vortex;
//    Dijkstra(G, vortex);
//
//    return 0;
//}
//
//void Dijkstra(vector<vector<pair<int, int>>> &myG, int &s) {
//    // Определяем значение infinity
//    const int inf = 2000000000;
//    size_t n = myG.size();
//    //==========================================================//
//    // Определяем три массива:                                  //
//    // D - для хранения кратчайших путей в графе от исходной    //
//    // P - для хранения промежуточных итогов длин путей         //
//    // U - для хранения булевских флагов посещения вершин       //
//    //==========================================================//
//    vector<size_t> D(n, inf);
//    vector<size_t> P(n);
//    vector<bool> U(n, false);
//    // Исходная вершина (в данном случае первая)
//    // s = 0;
//    D[s] = 0;
//    for (size_t i = 0; i < n; i++) {
//        // Определяем уникальное значение стартовой вершины
//        // Количество вершин не должно превышать это значение
//        size_t v = 1000000000;
//        for (size_t j = 0; j < n; j++)
//        if (!U[j] && (v == 1000000000 || D[j] < D[v]))
//                v = j;
//        // Выходим, если встретился хоть один inf,
//        // что значит: кратчайших маршрутов больше не найдено
//        if (D[v] == inf)
//            break;
//        // Говорим, что посетили вершину
//        U[v] = true;
//        // Определяем итераторы по текущему списку
//        auto beg = myG[v].begin();
//        auto lst = myG[v].end();
//        while (beg != lst) {
//            auto to = beg -> first;
//            auto len = beg -> second;
//            // Этот процесс называют "релаксацией", т. е.
//            // поиск как можно меньшего пути,
//            // что повторяет алгоритм Флойда — Уоршелла
//            if (D[v] + len < D[to]) {
//                D[to] = D[v] + len;
//                P[to] = v;
//            }
//            beg++;
//        }
//    }
//    // Выводим список кратчайших маршрутов от
//    // исходной вершины ко всем остальным:
//    for (auto &r : D)
//        cout << r << " ";
//    cout << endl;
//}





                                        //Обход графа в ширину


//
//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//
//void BFS(vector<vector<int>>&, int&, int&);
//
//int main() {
//    // Список смежности (рис. 9)
//    vector<vector<int>> G {
//        {1, 4, 5}, {0, 6}, {3, 5}, {2, 7},
//        {0, 5, 9}, {0, 2, 4, 9, 10}, {1, 11}, {3, 10},
//        {9, 13}, {4, 5, 10, 12}, {5, 7, 9, 15}, {6, 14},
//        {9}, {8, 14}, {11, 13}, {10}
//    };
//    int start, finish; // стартовая и конечная вершины
//    cout << "Введите стартовую вершину => "; cin >> start;
//    cout << "Введите конечную вершину => ";  cin >> finish;
//    BFS(G, start, finish);
//    return 0;
//}
//
//void BFS(vector<vector<int>> &myG, int &s, int &fin) {
//    size_t n = myG.size(); // число вершин
//    queue<int> Q; // подготовим очередь
//    // и поместим в нее исходную вершину
//    Q.push(s);
//    vector<bool> used(n, false);
//    // если нужно сохранять длины путей
//    // то определяем и массив D[]:
//    // vector<int> D(n);
//    vector<int> P(n);
//    used[s] = true;
//    P[s] = -1;
//    // Пока очередь не пуста
//    while (!Q.empty()) {
//        // Берем элемент вначале очереди
//        int v = Q.front();
//        Q.pop();
//        for (size_t i=0; i < myG[v].size(); ++i) {
//            // Осматриваем соседей
//            int to = myG[v][i];
//            // если не заходили к ним,
//            if (!used[to]) {
//                // то заходим
//                used[to] = true;
//                // и ставим их в очередь
//                Q.push(to);
//                // увеличиваем и сохраняем длину,
//                // если нужно
//                // D[to] = D[v] + 1;
//                // запоминаем номер откуда пришли
//                P[to] = v;
//            }
//        }
//    }
//    // Определение и вывод пути
//    // из вершины s в вершину fin
//    // включительно
//    if (!used[fin])
//        cout << "Пути нет!";
//    else {
//        vector<int> path;
//        while (fin != -1) {
//            path.push_back(fin);
//            fin = P[fin];
//        }
//        auto first = path.crbegin();
//        auto last  = path.crend();
//        cout << "Путь: ";
//        while (first != last)
//            cout << *first++ << " ";
//    }
//}




                                        //Обход графа в глубину




#include <iostream>
#include <stack>
#include <vector>
using namespace std;
 
int DFS(vector<vector<int>>&, int&, int&);
 
int main() {
    // Список смежности графа
    vector<vector<int>> G {
        {1, 2, 3},
        //----------------------------------------------
        {0, 4, 5}, {0, 6, 7}, {0, 8, 9},
        //----------------------------------------------
        {1, 10, 11, 12}, {14, 13, 14}, {2, 15},
        {2, 16, 17}, {3}, {3, 18},
        //----------------------------------------------
        {4}, {4}, {4, 19, 20}, {5}, {5}, {6, 21, 22, 23},
        {7, 24, 25}, {7, 26, 27}, {9, 28, 29},
        //-----------------------------------------------
        {12}, {12}, {15}, {15}, {15}, {16}, {16}, {17},
        {17}, {18}, {18}
        //-----------------------------------------------
    };
 
    int start, finish; // стартовая и конечная вершины
    cout << "Введите стартовую вершину => "; cin >> start;
    cout << "Введите конечную вершину => ";  cin >> finish;
    cout << "Длина /*кратчайшего*/пути из вершины "
         << start
         << "\nв вершину "
         << finish
         << " равна "
         << DFS(G, start, finish)
         << endl;
 
    return 0;
}
 
int DFS(vector<vector<int>> &myG, int &s, int &u) {
    size_t n = myG.size();
    // Массив флагов посещаемости вершин
    vector<bool> used(n, false);
    // Подготовим стек
    stack<int> S;
    // Кладем исходную вершину в стек
    S.push(s);
    used[s] = true;
    // Будем считать длину пути
    vector<int> D(n);
    // Если нужно, запоминаем путь
    // vector<int> P(n);
    // P[start] = -1; длинна
    
    // Пока стек не пуст
    while (!S.empty()) {
        //Посещаем вершину
        size_t v = S.top();
        S.pop();
        // Идем в глубину графа
        auto first = myG[v].begin();
        auto last  = myG[v].end();
        // Осматриваем смежные вершины
        while (first != last) {
            // Если какие-то ещё не посещались
            if (!used[*first]) {
                // Отправляем их в стек
                S.push(*first);
                // и фиксируем их посещение
                used[*first] = true;
                // если нужно запоминать путь, то
                // P[*first] = v;
                
                D[*first] = D[v] + 1;
            }
            first++;
        }
    }
    return D[u];
}
