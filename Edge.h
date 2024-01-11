#pragma once
#include <iostream>
#include <map>
#include <set>
#include<vector>
#include"Node.h"

using namespace std;
class Edge
{
public:
    Edge(int weight,Node *from,Node *to)
    {
        this->weight = weight;
        this->from = from;
        this->to = to;
        
    }
    int weight;
    Node *from;
    Node *to;

};