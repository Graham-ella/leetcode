/*
已知的是a和b(ai和bi都是0、1)
然后根据ai,bi来决定pi(pi是正整数)
要求是使pi的最大值最小就行

1、如果ai = bi,pi取1即可，不会sum有贡献
2、如果ai < bi,(ai-bi)*pi = -pi 会对sum有负贡献，要使得sum>0，pi要小一点，取1就行
3、如果ai > bi,(ai-bi)*pi = pi 因此这种情况pi的值就和情况2有关

假设情况2出现x次，情况3出现y次，设情况三中pi = t，则yt>x yt>=x+1 t>=(x+1)/y(这里要上取整才能保持sum>0）

补充一个:
a/b上取整 == (a+b-1)/b下取整
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 110;
int n;
int a[N], b[N];

int main() {
	cin >> n;//字符串的长度
	for (int i = 0; i < n; i++) cin >> a[i];//读入a
	for (int i = 0; i < n; i++) cin >> b[i];//读入b
	int x = 0, y = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] < b[i]) x++;
		if (a[i] > b[i]) y++;
	}
	if (!y) cout << -1 << endl;
	else cout << (y + x) / y << endl;

}