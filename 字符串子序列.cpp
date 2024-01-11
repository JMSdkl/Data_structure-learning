#include <list>
#include <iostream>
#include <stack>
#include<vector>
#include <map>
using namespace std;

/////////////////////////////////////Ѱ���ַ����Ӵ�/////////////////////////////////
void process(char chs[], int i, list<char>res)
{
	if (i == sizeof(chs))
	{
		for (char zz : res) {
			cout << zz << " ";
		}
		cout << endl;
		return;
	}
	//��Ҫ�����·
	list<char>keepchar(res);
	keepchar.push_back(chs[i]);
	process(chs, i + 1, keepchar);
	//������ֵ��·��
	list<char>keepchar2(res);
	process(chs, i + 1, keepchar2);
}

void process(string chs, int i, list<char>res)
{
	if (i == chs.size())
	{
		for (char zz : res) {
			cout << zz << " ";

		}
		cout << endl;
		return;
	}
	//��Ҫ�����·
	list<char>keepchar(res);
	keepchar.push_back(chs[i]);
	process(chs, i + 1, keepchar);
	//������ֵ��·��
	list<char>keepchar2(res);
	process(chs, i + 1, keepchar2);
}
/////////////////////////////////////Ѱ���ַ����Ӵ�/////////////////////////////////

class Hanoi
{
public:
	void hanoi(int n)
	{
		if (n > 0)
		{
			func(n, "��", "��", "��");
		}
	}

	void func(int i, string start, string end, string other)
	{
		if (i == 1) {
			cout << "Move 1 from" + start + "to" + end << endl;

		}
		else
		{
			func(i - 1, start, other, end);
			cout << "Move " << i << " from " << start << " to " << end << endl;
			func(i - 1, other, end, start);
		}

	}
};

class StringSort
{
private:
	string str;
public:
	/*StringSort(string str)
	{
		this->str = str;
	}*/
	static void process(string str, int i, list<string>& result) {
		if (i == str.size()) {
			result.push_back(str);
		}
		bool visit[26];
		for (int j = i; j < str.size(); j++) {
			if (!visit[str[j]] - 'a')
			{
				visit[str[j] - 'a'] = true;
				swap(str, i, j);
				process(str, i + 1, result);
				swap(str, i, j);
			}
		}
	}
	static void swap(string& str, int i, int j) //����Ҫ������������  ���ֻ�Ǵ��β� ���õ�ʱ��Ͳ����𵽽�����Ч��
	{
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
};

class Zipai
{
private:
public:


};

class ReverseStack {
private:
	static int f(stack<int>& stackk) //�����ִӶѵ͵���
	{
		int result = stackk.top();
		stackk.pop();
		if (stackk.empty())
		{
			return result;
		}
		else
		{
			int last = f(stackk);
			stackk.push(result);
			return last;
		}
	}
public:
	static void reverse(stack<int>& stackk) {

		if (stackk.empty())
		{
			return;
		}
		else
		{
			int i = f(stackk);
			reverse(stackk);
			stackk.push(i);
		}
	}


};

//��ͬ·�����⣬ʹ�ñ����ݹ�����ˣ����ǳ�������ʱ�䣬��Ҫ�Ķ�̬�滮�������ᡣ������
class Solution {
public:
	int process(int i, int j, int m, int n) {
		if (i == m && j == n) {
			return 1;
		}
		if (i > m || j > n) {
			return 0;
		}
		int res = 0;
		res += process(i, j + 1, m, n);
		res += process(i + 1, j, m, n);
		return res;
	}
	int uniquePaths(int m, int n) {
		int ress = 0;
		ress = process(0 + 1, 0 + 1, m, n);
		return ress;
	}
};
//һ��·���涨������Ŀ��ط����⣺
class Solution2
{
public:
	int process(int N, int E, int rest, int cur) {
		if (rest == 0 && cur == E)
		{
			return 1;
		}
		if (rest < 0)
		{
			return 0;
		}
		int res = 0;
		if (cur == 1)
		{
			//res+=process(N, E, rest-1, 2);//cur + 1
			return process(N, E, rest - 1, 2);
		}
		if (cur == N)
		{
			//res += process(N, E, rest-1, N - 1);//cur - 1
			return process(N, E, rest - 1, N - 1);
		}
		/*res += process(N, E, rest-1, cur + 1);
		res += process(N, E, rest-1, cur - 1);  //��Щ�ǳ��Թ��Ĳ��� ������ʵ�ʵĿ���·�� */
		return res = process(N, E, rest - 1, cur + 1) + process(N, E, rest - 1, cur - 1);
	}
	int mainuse(int N, int S, int E, int K)
	{
		return process(N, E, K, S);
	}
};


class Solution2dp
{
public:
	int process(int N, int E, int rest, int cur, vector<vector<int>>& dp) {

		if (dp[rest][cur] != -1)
		{
			return dp[rest][cur];
		}
		if (rest == 0)//��0��ʱ���Ӧ��ֹͣ��
		{
			dp[rest][cur] = cur == E ? 1 : 0;
			return dp[rest][cur];
		}
		/*if (rest < 0)  //������������ ���Ҫ�ľ�ֱ�Ӳ� ��ֵdp���� dp[rest][cur] = 0;
		{
			dp[rest][cur] = 0;
			return dp[rest][cur];
		}*/
		//int res = 0;
		if (cur == 1)
		{
			//res+=process(N, E, rest-1, 2);//cur + 1
			dp[rest][cur] = process(N, E, rest - 1, 2, dp);
			return dp[rest][cur];
		}
		if (cur == N)
		{
			//res += process(N, E, rest-1, N - 1);//cur - 1
			dp[rest][cur] = process(N, E, rest - 1, N - 1, dp);
			return dp[rest][cur];
		}
		/*res += process(N, E, rest-1, cur + 1);
		res += process(N, E, rest-1, cur - 1);  //��Щ�ǳ��Թ��Ĳ��� ������ʵ�ʵĿ���·�� */
		dp[rest][cur] = process(N, E, rest - 1, cur + 1, dp) + process(N, E, rest - 1, cur - 1, dp);
		return dp[rest][cur];
	}
	int mainuse(int N, int S, int E, int K)
	{
		/*int n = 10;
		int m = 5;*/
		int initial_value = -1;
		vector<vector<int>> dp(K + 1, vector<int>(N + 1, initial_value));


		return process(N, E, K, S, dp);
	}
};

class SoluCoin {
public:
	static int process(vector<int>arr, int index, int rest) {
		//Ǯ��������Ŀ�꣬������Ч
		if (rest < 0)
		{
			return -1;
		}
		//Ǯ�պôﵽĿ�꣬������Ч0
		if (rest == 0)
		{
			return 0;
		}
		//ѡȡ�����������һλ������rest���У�������Ч
		if ((index) == arr.size())
		{
			return -1;
		}
		int p1 = process(arr, index + 1, rest);//ѡȡ��ǰֵ
		int p2next = process(arr, index + 1, rest - arr[index]);
		if (p1 == -1 && p2next == -1)
		{
			return -1;
		}
		else
		{
			if (p1 == -1)
			{
				return p2next + 1;
			}
			if (p2next == -1)
			{
				return p1;
			}
			return min(p1, p2next + 1);
		}
	}
	int mainuse() {
		vector<int>arr;
		process(arr, 0, 5);
	}
};

class Solution62 {
public:
	int process(int i, int j, int m, int n, vector<vector<int>>& dp) {
		if (dp[i - 1][j - 1] != 0) {
			return dp[i - 1][j - 1];
		}
		if (i == m && j == n) {
			dp[i - 1][j - 1] = 1;
			return dp[i - 1][j - 1];
		}
		if (i > m || j > n) {

			return 0;
		}
		//int res = 0;
		dp[i - 1][j - 1] += process(i, j + 1, m, n, dp);
		dp[i - 1][j - 1] += process(i + 1, j, m, n, dp);
		//dp[i - 1][j - 1] = res;
		return dp[i - 1][j - 1];
	}
	int uniquePaths(int m, int n) {
		int ress = 0;
		vector<vector<int>>dp(m + 1, vector<int>(n + 1, 0));

		ress = process(0 + 1, 0 + 1, m, n, dp);
		return ress;
	}
};


class CoinsWays {
public:
	int way1(vector<int>arr, int aim) {
		return process(arr, 0, aim);
	}

	static int process(vector<int>arr, int index, int rest) {
		if (arr.size() == index) {
			return rest == 0 ? 1 : 0;
		}
		int ways = 0;
		for (int zhang = 0; arr[index] * zhang <= rest; zhang++)
		{
			ways += process(arr, index + 1, rest - arr[index] * zhang);
		}
		return ways;
	}
};

class Solution59 {
public:
	vector<vector<int>> generateMatrix(int n) {
		int l = 0, r = n - 1, t = 0, b = n - 1;
		vector<vector<int>> mat(n, vector<int>(n, 0));
		int num = 1, tar = n * n;
		while (num <= tar)
		{
			for (int i = l; i <= r; i++) mat[t][i] = num++; // left to right.
			t++;
			for (int i = t; i <= b; i++) mat[i][r] = num++; // top to bottom.
			r--;
			for (int i = r; i >= l; i--) mat[b][i] = num++; // right to left.
			b--;
			for (int i = b; i >= t; i--) mat[i][l] = num++; // bottom to top.
			l++;

		}
		return mat;
	}
};

class IsLands {
public:
	static int countIslands(vector<vector<int>>& m) {
		if (m.empty())
		{
			return 0;
		}
		int N = m.size();
		int M = m[0].size();
		int res = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++) {
				if (m[i][j] == 1)
				{
					res += 1;
					infect(m, i, j, N, M);
				}
			}
		}
		return res;
	}
	static void infect(vector<vector<int>>& m, int i, int j, int N, int M)
	{
		if (i < 0 || i >= N || j < 0 || j >= M || m[i][j] != 1)
		{
			return;
		}
		m[i][j] = 2;
		infect(m, i + 1, j, N, M);
		infect(m, i - 1, j, N, M);
		infect(m, i, j + 1, N, M);
		infect(m, i, j - 1, N, M);
	}
	void mainuse() {
		vector<vector<int>>mm = {
		{1, 1, 0},
		{1, 0, 0},
		{1, 0, 1}

		};
		//vector<vector<int>>mm(50, vector<int>(50, 1));

		cout << "������Ϊ��" << countIslands(mm) << endl;
	}

};


template <typename V1>
class Element {
public:
	V1 value;
	Element(V1 value) {
		this->value = value;
		cout << "Element���" << value << endl;
	}
	// ����С������������ڱȽ� Element ����
	bool operator<(const Element& other) const {
		return value < other.value;
	}

};

//Element<V2> ���Ӧ�ô��ַ���һ�㣬��Ϊ�������Ƚϵ�ʱ�� �Ƚϵ�ַ�Ƿ���ͬ�Ϳ��Կ��Ƿ���ͬһ��ֵ��
template <typename V2>
class UnionFindSet {
public:
	map<V2, Element<V2>>* elementMap = new map<V2, Element<V2>>();
	map<Element<V2>, Element<V2>>* fatherMap = new map<Element<V2>, Element<V2>>();
	map<Element<V2>, int>* sizeMap = new map<Element<V2>, int>();

	UnionFindSet(list<V2> list) {//Ĭ�Ϲ��죬��ʼ����ЩԪ��

		for (V2 value : list) {
			//cout << value << endl;
			Element<V2>* element = new Element<V2>(value);
			elementMap->insert(make_pair(value, *element));
			fatherMap->insert(pair<Element<V2>, Element<V2>>(*element, *element));
			sizeMap->insert(pair<Element<V2>, int>(*element, 1));
		}
		for (pair<V2, Element<V2>> aa : *elementMap) {
			//cout << &aa.second << " ";
			cout << aa.first << " ";

		}
		cout << endl;
		for (pair<Element<V2>, int> aa : *sizeMap) {
			//cout << &aa.first<<" ";
			cout << aa.second << " ";
		}
		cout << endl;

	}
	Element<V2> findHead(Element<V2> element)
	{
		stack<Element<V2>>* path = new stack<Element<V2>>();
		while (element != (fatherMap->find(element))->second)  //�������Զ������ͱȽ����⣬ �������Ӧ�øĳɵ�ַ �Ƚϴ�ŵ�ַ�Ƿ���ͬ
		{
			path->push(element);
			element = (fatherMap->find(element))->second;
		}
		while (!path->empty())
		{
			fatherMap->insert(pair<Element<V2>, Element<V2>>(path->top(), element));
			path->pop();
		}

	}
	bool isSameSet(V2 a, V2 b) {
		if (elementMap->count(a) > 0 && elementMap->count(b) > 0) {
			findHead(elementMap->find(a)->second);
			return true;
		}
		return false;
	}
};


class KMPalgorithm {
private:
	static vector<int> getNextArray(string ms)
	{
		if (ms.empty() || ms.size() == 1) {
			return vector<int>(1, -1);
		}
		vector<int> next(ms.size());
		next[0] = -1;
		next[1] = 0;
		int i = 2;
		int cn = 0;
		while (i < next.size())
		{
			if (ms[i - 1] == ms[cn]) {
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
	//s�ǳ��ַ��� m��ƥ��Ŀ���ַ���
	int KMP_algorithm(string s, string m) {
		if (s.empty() || m.empty() || s.size() < 1 || m.size() < 1 || s.size() < m.size())
		{
			return -1;
		}
		string str1 = s;
		string str2 = m;
		int i1 = 0;
		int i2 = 0;
		vector<int> next = getNextArray(str2);
		while (i1 < str1.size() && i2 < str2.size()) {
			if (str1[i1] == str2[i2]) {
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

	void main() {
		vector<int> res = getNextArray("abbtabb");
		for (int i : res) {
			cout << i;
		}
		cout << endl;
	}

};


int main()
{
	/////////////////////////////////////Ѱ���ַ����Ӵ�/////////////////////////////////
	//char chs[3] = {'a','b','c'};
	string chs = "abc";
	list<char>res;
	//cout << sizeof(chs) << endl;
	process(chs, 0, res);
	/////////////////////////////////////Ѱ���ַ����Ӵ�/////////////////////////////////

	////////////////////////////////////��ŵ������/////////////////////////////////
	Hanoi aa;
	aa.hanoi(5);
	////////////////////////////////////��ŵ������/////////////////////////////////

	///////////////////////////////////���ظ��ַ�////////////////////////
	StringSort ss;
	list<string>result;
	ss.process("abc", 0, result);
	for (string str : result) {
		cout << str << endl;
	}
	///////////////////////////////////���ظ��ַ�////////////////////////

	///////////////////////////////////ֽ������//////////////////////////////////

	///////////////////////////////////ֽ������//////////////////////////////////

	///////////////////////////////��ת��//////////////////////////////////
	ReverseStack staccck;
	stack<int> stt;
	stt.push(1);
	stt.push(2);
	stt.push(3);
	cout << stt.top() << endl;
	stt.pop();
	cout << stt.top() << endl;
	stt.pop();
	cout << stt.top() << endl;
	stt.pop();
	stt.push(1);
	stt.push(2);
	stt.push(3);
	staccck.reverse(stt);
	cout << stt.top() << endl;
	stt.pop();
	cout << stt.top() << endl;
	stt.pop();
	cout << stt.top() << endl;
	stt.pop();
	//·�����⡢����������������������������������������/////////////////////////
	Solution2 lujing;
	cout << "·����Ϊ��" << lujing.mainuse(4, 1, 2, 3) << endl;
	//·�����⡢����������������������������������������/////////////////////////
	//·�����⡢����������������������������������������/////////////////////////
	Solution2dp lujingdp;
	cout << "·����Ϊ��" << lujingdp.mainuse(4, 1, 2, 3) << endl;
	//·�����⡢����������������������������������������/////////////////////////
	Solution62 likou;
	cout << likou.uniquePaths(3, 2) << endl;
	//Ӳ���������⡢����������������������������������������/////////////////////////
	CoinsWays c1;
	vector<int>arryy;
	arryy.push_back(3);
	arryy.push_back(5);
	arryy.push_back(1);
	arryy.push_back(2);

	cout << "���Ϊ��" << c1.way1(arryy, 10) << endl;


	Solution59 sol;

	auto vect = sol.generateMatrix(4);

	IsLands islandd;
	islandd.mainuse();

	list<int> listl;
	listl.push_back(0);
	listl.push_back(1);
	listl.push_back(2);
	listl.push_back(3);

	UnionFindSet<int> unset(listl);
	//cout<<unset.isSameSet(0, 1);
	KMPalgorithm  kkkk;
	kkkk.main();
	int acaa = kkkk.KMP_algorithm("abbsabbtcabbsabbe", "bbtc");
	string aaxxx = "abbsabbtcabbsabbe";
	string aaxx = "bbtc";
	cout << kkkk.KMP_algorithm("abbsabbtcabbsabbe", "bbtc") << endl;
	//cout << aaxxx[0];
	for (int i11 = (int)acaa; i11 < acaa + aaxx.size(); i11++) {
		cout << aaxxx[i11];
	}
	cout << endl;

	return 0;
}
