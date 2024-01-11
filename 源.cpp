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
            int temp = num % 10;//获得最后一位
            numjj.push_back(temp);
            getnum(num / 10,numjj);//整体往后移一位
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
//括号匹配算法
class Solution_20 {
public:
    bool isValid(string s) {
        stack<char> sta;
        if (s.size() % 2 != 0) return false; // 如果s的长度为奇数，一定不符合要求
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '{')sta.push('}');
            else if (s[i] == '(')sta.push(')');
            else if (s[i] == '[')sta.push(']');

            else if (sta.empty() || sta.top() != s[i])return false;//还没遍历完就空了，
                                                    //或者当前字符不是对应的右括号
            else sta.pop();
        }
        return sta.empty(); //字符串遍历完了，但还有符号在里面 说明有不匹配的左在里面
    }
};
//删除字符串中重复字符（对对碰）
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
        while (!stack1.empty()) {//stack里面还有字符，就是删除剩下的字符
            result += stack1.top();
            stack1.pop();
        }
        reverse(result.begin(), result.end()); // 此时字符串需要反转一下
        return result;
    }
};
//逆波兰算数计算
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
//以队列的方法生成栈
class MyStack_225 {
public:
    MyStack_225() {

    }

    void push(int x) {
        que1.push(x);
    }

    int pop() {
        int que1size = que1.size() - 1;//留下一个元素作为结果
        while (que1size--) {
            que2.push(que1.front());
            que1.pop();
        }
        int result = que1.front();
        que1.pop();
        que1 = que2; //让que2的元素赋值给que1
        while (!que2.empty()) {//清空que2 为下次弹出做准备
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
//以栈的方法生成队列
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

//滑动窗口最大值
class Solution_239 {
public:
    class Mydeque {//这个队列用于记录一个递减序列，
                   //如果push的值，没有当前队列的（后面算起）值大，就不放入
                   //如果push的值，大于这个队列的所有值，那就全部弹出，只保留这个值

                    //对于pop 如果当前弹出的目标值，和队列里面的第一个值（最大值）不同，那就不弹出
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
        result.push_back(deque.front());//用于记录最大值
        for (int i = k; i < nums.size(); i++) {
            deque.pop(nums[i - k]);//弹出前面的元素 i-k= 0 1 2 3 ....
            deque.push(nums[i]);//放入k后的元素
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