#include <iostream>
#include <algorithm>
using namespace std;

//三元数异或
/*
给定一个可能很长的三元数 x，其首位数字（最左边那位）保证为 2，其他位数字为0或1或2
对于每个给定的 x，求出可以满足 a ⊙ b = x，并且 max(a,b) 尽可能小的a , b
*/

int main() {
	int T;
	cin >> T;//读入有多少组数据
	while(T--){
		int n;//n代表字符串x长度
		string x;
		cin >> n >> x;
		string a, b;
		bool flag = false;//能否确定a>b了
		for (auto c : x) {
			if (c == '0') {
				a += '0';
				b += '0';
			}
			else if (c == '1') {
				/*
				a b
				0 1  a>b
				1 0  a=b
				*/
				if (flag) {
					a += '0';
					b += '1';
				}
				else {
					a += '1';
					b += '0';
					flag = true;
				}
			}
			else {
				/*
				a b
				0 2 a>b
				1 1 a=b
				*/
				if (flag) {
					a += '0';
					b += '2';
				}
				else {
					a += '1';
					b += '1';
				}
			}
		}
		cout << a << endl << b << endl;
	}
}

