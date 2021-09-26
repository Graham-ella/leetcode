/*
思路:
这种换法可以让我们对矩阵中任意两个数据实现变号操作，
要想和最大，用分类讨论
1、矩阵中负数个数为偶数 
   正好负数两两配对，同时变正数
2、矩阵中负数个数为奇数
   显然无论怎么变，矩阵中最后都会有一个数据是负数
   考虑将绝对值最小的那个变成负数

这么讨论涉及一个问题:如果数据中有0
对于情况1不影响，对于情况2，如果负数个数为奇数的情况下，
绝对值最小的数一定是0，意思就是说最大的和还是等于所有数据的绝对值
的和，可以这么来想，
抽出一个0和负数组合，这样就可以把所有负数变成正数了
*/


#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int T;
	cin >> T;//读入有多少组数据
	while (T--) {
		int n, m;//表示行,列
		int count = 0;//表示负数的个数
		int minABS = 1e8;//表示绝对值最小的数
		int temp;
		int sum = 0;//表示和
		cin >> n >> m;
		for (int i = 0; i < (n * m); i++) {
			cin >> temp;
			sum += abs(temp);
			minABS = min(abs(temp), minABS);
			if (temp < 0) {
				count++;
			}
		}
		if (count % 2) {
			cout << sum - 2 * minABS << endl;
		}
		else {
			cout << sum << endl;
		}

	}

}