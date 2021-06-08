#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 100010;

int n,x;
int w[N];

int main() {
	int T;//表示数据组数
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &x);
		for (int i = 0; i < n; i++) {
			scanf("%d", &w[i]);
		}//把数都存在w[i]中
		LL sum = 0, psum = 0;
		int cnt = N;
		for (int i = 0; i < n; i++) {
			sum += w[i];
			int c = 0;
			for (int j = w[i]; j % x == 0; j /= x) {
				c++;//c代表w[i]可以被展开的次数
			}
			if (c < cnt) {
				cnt = c;
				psum = sum - w[i];
			}
		}

		printf("%lld\n", sum * (cnt + 1) + psum);
	}
	return 0;

}