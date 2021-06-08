#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 110;
const double PI = acos(-1);

int n;
int r[N];//圆半径的集合

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &r[i]);//将圆的半径存入数组中
	}
	sort(r, r + n, greater<int>());

	double res = 0;
	for (int i = 0; i < n; i += 2) {
		res += PI * (r[i] * r[i] - r[i + 1] * r[i + 1]);
	}
	printf("%lf\n", res);
	return 0;
}