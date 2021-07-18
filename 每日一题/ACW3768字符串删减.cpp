/*
现在，需要删掉其中的一些字母，使得字符串中不存在连续三个或三个以上的 x。
请问，最少需要删掉多少个字母？
如果字符串本来就不存在连续的三个或三个以上 x，则无需删掉任何字母。
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int n;
	string s;
	cin >> n >> s;//读入字符串长度和字符串本身
	int res = 0;

	for (int i = 0; i < n; i++) {
		if (s[i] != 'x') continue;
		int j = i + 1;
		while (j < n && s[j] == 'x') j++;
		res += max(0, j - i - 2);
		i = j - 1;
		/*
		比如说     i x x x i x x x x i x  x  x
		对应下标为 0 1 2 3 4 5 6 7 8 9 10 11 12
		*/
	}
	cout << res << endl;

}