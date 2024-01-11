#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <list>
#include <math.h>
using namespace std;
class KMPalgorithm
{
private:
    static vector<int> getNextArray(string ms)
    {
        if (ms.empty() || ms.size() == 1)
        {
            return vector<int>(1, -1);
        }
        vector<int> next(ms.size());
        next[0] = -1;
        next[1] = 0;
        int i = 2;
        int cn = 0;
        while (i < next.size())
        {
            if (ms[i - 1] == ms[cn])
            {
                next[i++] = ++cn;
            }
            else if (cn > 0)
            {
                cn = next[cn];
            }
            else
            {
                next[i++] = 0;
            }
        }
        return next;
    }

public:
    // s是长字符串 m是匹配目标字符串
    int KMP_algorithm(string s, string m)
    {
        if (s.empty() || m.empty() || s.size() < 1 || m.size() < 1 || s.size() < m.size())
        {
            return -1;
        }
        string str1 = s;
        string str2 = m;
        int i1 = 0;
        int i2 = 0;
        vector<int> next = getNextArray(str2);
        while (i1 < str1.size() && i2 < str2.size())
        {
            if (str1[i1] == str2[i2])
            {
                i1++;
                i2++;
            }
            else if (next[i2] == -1)
            {
                i1++;
            }
            else
            {
                i2 = next[i2];
            }
        }
        return i2 == str2.size() ? i1 - i2 : -1;
    }

    void main()
    {
        vector<int> res = getNextArray("abbtabb");
        for (int i : res)
        {
            cout << i;
        }
        cout << endl;
    }
};
class Lcp
{
public:
    static string manacherString(string str) {
        string charArr = str;
        string res;
        res.resize(str.size() * 2 + 1);
        int index = 0;
        for (size_t i = 0; i != res.size(); i++)
        {
            /* code */
            res[i] = (i & 1) == 0 ? '#' : charArr[index++];
        }
        return res;

    }
    void mainuse() {
        cout << manacherString("kljkdl") << endl;

    }
    int maxLcpsLength(string s) {
        if (s.empty() || s.size() == 0)
        {
            return 0;
        }
        string str = manacherString(s);
        vector<int> pArr(str.size());//找到arry里面的最大值,他的索引号就是回文中心
        int C = -1;
        int R = -1;
        int maxx = INT64_MIN;
        for (int i = 0; i != str.size(); i++)
        {
            pArr[i] = R > i ? min(pArr[2 * C - i], R - i) : 1;
            while (i + pArr[i]<str.size() && i - pArr[i]>-1)
            {
                if (str[i + pArr[i]] == str[i - pArr[i]])//边界往外走,如果i'那边有对称的,回文半径++
                {
                    pArr[i]++;
                }
                else {
                    break;
                }
                if (i + pArr[i] > R)
                {
                    R = i + pArr[i];
                    C = i;
                }
                maxx = max(maxx, pArr[i]);
            }
        }
        for (int i : pArr) {
            cout << i;
        }
        cout << endl;
        cout << pArr[maxx] - maxx << endl;
        int LL, RR;
        LL = 0;
        RR = 0;
        int maxint = INT64_MIN;
        for(;RR<pArr.size();RR++)
        {
            if (pArr[LL] < pArr[RR]) {
                LL = RR;
            }
            //cout << pArr[LL] << ' ' << LL << endl;
        }
         cout << pArr[LL] << ' ' << LL << endl;
         cout << "index:" << LL - pArr[LL] << endl;
        // cout<<"回文中心索引:"<<C/2<<endl;
        return maxx - 1;//maxx-1是因为处理串半径-1对应原来 字符串的最大回文直径


    }

};
int main()
{
    cout << "hello world" << endl;

    KMPalgorithm kmp;
    kmp.main();

    cout << kmp.KMP_algorithm("12345623", "456") << endl;
    Lcp ll;
    ll.mainuse();
    cout << ll.manacherString("aaddfscdfscbabcsdauix") << endl;
    cout << ll.maxLcpsLength("aaddfscdfscbabcsdauix") << endl;//怎么获得最大回文长度的起点?
}