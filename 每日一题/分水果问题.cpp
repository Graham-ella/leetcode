#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int table[7][3] = {
	{0,0,1},
	{0,1,0},
	{0,1,1},
	{1,0,0},
	{1,0,1},
	{1,1,0},
	{1,1,1}
};//给小朋友分水果的方法，最多也只能分给7个小朋友


int main() {
	int T;//记录有多少组测试数据
	cin >> T;
	while (T--) {
		int res = 0;
		int a, b, c;
		cin >> a >> b >> c;//读入水果的数量
		//上面7种分水果的方案都有选和不选的说法，因此共有2^7中可能
		for (int i = 0; i < (1 << 7); i++) {
			int sa = 0, sb = 0, sc = 0;
			int cnt = 0;//记录当前选法分给了多少人
			for (int j = 0; j < 7; j++) {
				if ((i >> j) & 1 == 1) {
					sa += table[j][0];
					sb += table[j][1];
					sc += table[j][2];
					cnt++;
				}
			}
			if (sa <= a && sb <= b && sc <= c) {
				res = max(res, cnt);
			}
		}
		cout << res << endl;
		
	}
	return 0;
}