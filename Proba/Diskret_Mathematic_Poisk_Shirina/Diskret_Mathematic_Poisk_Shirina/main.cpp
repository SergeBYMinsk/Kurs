//
//  main.cpp
//  Diskret_Mathematic_Poisk_Shirina
//
//  Created by Sergey Sterlikov on 5/14/19.
//  Copyright © 2019 Sergey Sterlikov. All rights reserved.
//
#include <iostream>
using namespace std;

struct node{
    int value;
    node * next;
    node(int v, node * n = NULL){
        value = v;
        next = n;
    }
};

struct queue{ // Структура очередь
    node * start;
    node * finish;
    int len = 0;
    queue(node * s = NULL, node * f = NULL){
        start = s;
        finish = f;
    }
    string push(int n){
        if(len == 0){
            node * new_node = new node(n,finish);
            start = new_node;
            finish = new_node;
        }else{
            node * new_node = new node(n,NULL);
            start -> next = new_node;
            start = new_node;
        }
        len++;
        return "ok";
    }
    int pop(){
        int v = finish -> value;
        finish = finish -> next;
        len--;
        return v;
    }
    int front(){
        return finish -> value;
    }
    int size(){
        return len;
    }
};

int main() {
    int n, s, f;
    cout << "Vedi znachenia" << endl;
    cin >> n >> s >> f;
    int graph[n][n];
    int dist[n]; // Массив расстояний от начальной до i-ой вершины
    bool used[n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> graph[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        dist[i] = 0;
        used[i] = false;
    }
    queue vertex; // Очередь вершин
    vertex.push(s-1);
    used[s-1] = true;
    while(vertex.size() != 0){
        int v = vertex.front();
        for(int i = 0; i < n; i++){
            if(graph[v][i] == 1 && used[i] == false){
                vertex.push(i);
                dist[i] = dist[v] + 1;
                used[i] = true; // i-ая вершина пройдена и не будет корректироваться позже
            }
        }
        used[v] = true;
        vertex.pop();
    }
    cout << dist[f-1];
    return 0;
}
