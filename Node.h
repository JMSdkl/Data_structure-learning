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
    int in;//�ж��ٸ���ָ��õ�
    int out;//�õ�ָ�����ٸ���
    vector<Node>*nexts;//vector�����ֶ������ڴ�   �õ��ֱ���ڽӵ�
    vector<Edge>*edges;//���ڸõ�ı�  ָ���������ڣ�����ʱ��
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