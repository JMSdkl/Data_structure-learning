#pragma once

#include <iostream>
#include <map>
#include <set>
#include<vector>
#include "Edge.h"
using namespace std;
class Node
{
public:
    int value;
    int in;//有多少个点指向该点
    int out;//该点指出多少个点
    vector<Node>*nexts;//vector无需手动分配内存   该点的直接邻接点
    vector<Edge>*edges;//属于该点的边  指出才是属于（有向时）
    Node(int value)
    {
        this->value = value;
        in = 0;
        out = 0;
        nexts = new vector<Node>();
        edges = new vector<Edge>();
        
    }
    Node()
    {
        this->value = 0;
        in = 0;
        out = 0;
        nexts = new vector<Node>();
        edges = new vector<Edge>();
    }

};