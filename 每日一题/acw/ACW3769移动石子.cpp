/*
移动箱子:
要使得1号箱子的石子尽可能多
*/

/*
第一行包含整数 T，表示共有 T 组测试数据。
每组数据第一行包含两个整数 n 和 d。
第二行包含 n 个整数 a1,a2,…,an。

1≤T≤100,
1≤n,d≤100,
0≤ai≤100

*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 101;
int a[N];//代表箱子

int solve(int n, int d);

int main() {
	int T;
	cin >> T;//记录有多少组数据
	while (T--) {
		int n, d;//n:箱子数量 d:能移动的次数
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}//至此读完了箱子的个数
		cout << solve(n, d) << endl;
	}
}

int solve(int n, int d) {
	int res = 0;
	for (int i = 2; i <= n && d > 0; i++) {
		int temp =  (d > ((i-1)*a[i])) ? a[i] : d/(i-1);
		res += temp;
		d -= temp*(i-1);
	}
	return res + a[1];
}