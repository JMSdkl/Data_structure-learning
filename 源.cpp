#include<iostream>
#include<vector>
# include<unordered_set>
#include<stack>
#include<queue>
#include <string>
//#include<stol>
using namespace std;
class Solution {
public:
    vector<int> numvector;
    vector<int> getnum(int num,vector<int>&numjj) {
        //vector<int> numjj;
        if (num > 0) {
            int temp = num % 10;//������һλ
            numjj.push_back(temp);
            getnum(num / 10,numjj);//����������һλ
        }
        return numjj;
    }
    bool isHappy(int n) {
        unordered_set<int> uniqueset;
        while (1) {
            vector<int> dkjfk;
            if (n == 1) { return true; }
            uniqueset.insert(n);
            numvector=getnum(n, dkjfk);
            int temp = 0;
            for (int i = 0; i < numvector.size(); i++) {
                temp += numvector[i] * numvector[i];
            }
            n = temp;
            
            if (uniqueset.find(temp) != uniqueset.end()) {
                return false;
            }
            
        }
        
        //return false;

    }
};
//����ƥ���㷨
class Solution_20 {
public:
    bool isValid(string s) {
        stack<char> sta;
        if (s.size() % 2 != 0) return false; // ���s�ĳ���Ϊ������һ��������Ҫ��
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '{')sta.push('}');
            else if (s[i] == '(')sta.push(')');
            else if (s[i] == '[')sta.push(']');

            else if (sta.empty() || sta.top() != s[i])return false;//��û������Ϳ��ˣ�
                                                    //���ߵ�ǰ�ַ����Ƕ�Ӧ��������
            else sta.pop();
        }
        return sta.empty(); //�ַ����������ˣ������з��������� ˵���в�ƥ�����������
    }
};
//ɾ���ַ������ظ��ַ����Զ�����
class Solution_1047 {
public:
    string removeDuplicates(string s) {
        stack<char> stack1;
        for (char a : s) {
            if (stack1.empty() || stack1.top() != a)stack1.push(a);
            else {
                stack1.pop();
            }
        }
        string result = "";
        while (!stack1.empty()) {//stack���滹���ַ�������ɾ��ʣ�µ��ַ�
            result += stack1.top();
            stack1.pop();
        }
        reverse(result.begin(), result.end()); // ��ʱ�ַ�����Ҫ��תһ��
        return result;
    }
};
//�沨����������
class Solution_150 {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long>sta1;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                long temp1 = sta1.top();
                sta1.pop();
                long temp2 = sta1.top();
                sta1.pop();
                if (tokens[i] == "+")sta1.push(temp2 + temp1);
                if (tokens[i] == "-")sta1.push(temp2 - temp1);
                if (tokens[i] == "*")sta1.push(temp2 * temp1);
                if (tokens[i] == "/")sta1.push(temp2 / temp1);

            }
            else {
                sta1.push(stol(tokens[i]));
            }
        }
        int result = (int)sta1.top();
        return result;
    }
};
//�Զ��еķ�������ջ
class MyStack_225 {
public:
    MyStack_225() {

    }

    void push(int x) {
        que1.push(x);
    }

    int pop() {
        int que1size = que1.size() - 1;//����һ��Ԫ����Ϊ���
        while (que1size--) {
            que2.push(que1.front());
            que1.pop();
        }
        int result = que1.front();
        que1.pop();
        que1 = que2; //��que2��Ԫ�ظ�ֵ��que1
        while (!que2.empty()) {//���que2 Ϊ�´ε�����׼��
            que2.pop();
        }
        return result;

    }

    int top() {
        return que1.back();
    }

    bool empty() {
        return que1.empty();
    }
private:
    queue<int> que1;
    queue<int> que2;
};
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
//��ջ�ķ������ɶ���
class MyQueue_232 {
public:
    MyQueue_232() {

    }

    void push(int x) {
        stIn.push(x);
    }

    int pop() {
        if (stOut.empty()) {
            while (!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        int result = stOut.top();
        stOut.pop();
        return result;
    }

    int peek() {
        // stIn.pop();
        int result = this->pop();
        stOut.push(result);
        return result;
    }

    bool empty() {
        return stIn.empty() && stOut.empty();
    }
private:
    stack<int> stIn;
    stack<int> stOut;
};
/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

//�����������ֵ
class Solution_239 {
public:
    class Mydeque {//����������ڼ�¼һ���ݼ����У�
                   //���push��ֵ��û�е�ǰ���еģ���������ֵ�󣬾Ͳ�����
                   //���push��ֵ������������е�����ֵ���Ǿ�ȫ��������ֻ�������ֵ

                    //����pop �����ǰ������Ŀ��ֵ���Ͷ�������ĵ�һ��ֵ�����ֵ����ͬ���ǾͲ�����
    private:
        deque<int> deque;
    public:
        int front() {
            return deque.front();
        }
        void pop(int value) {
            if (!deque.empty() && value == deque.front()) {
                deque.pop_front();
            }
        }
        void push(int value) {
            while (!deque.empty() && value > deque.back()) {
                deque.pop_back();
            }
            deque.push_back(value);
        }

    };

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        Mydeque deque;
        vector<int> result;
        for (int i = 0; i < k; i++) {
            deque.push(nums[i]);
        }
        result.push_back(deque.front());//���ڼ�¼���ֵ
        for (int i = k; i < nums.size(); i++) {
            deque.pop(nums[i - k]);//����ǰ���Ԫ�� i-k= 0 1 2 3 ....
            deque.push(nums[i]);//����k���Ԫ��
            result.push_back(deque.front());
        }
        return result;

    }
};


int main() {
    Solution ss;
    cout<<ss.isHappy(3);

    return 0;
}