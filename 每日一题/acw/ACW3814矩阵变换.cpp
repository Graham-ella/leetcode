#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
题干：
对于n*n的矩阵，可以选择任意列来变换
输出：这个矩阵经过变换后 全为1的行的最大数量

思路：
1、这种列的变换不会影响到行之间的相等关系
2、任意行都可以通过这种变化变成全1

意思就是说某一些行你想要把它变成全1那么和它不相等的行就不能是全1，
否则它们就是相等了

因此其实相等于就是找到出现最多次数的那一行就行 利用哈希表就行
*/
int main(){
	int n;
	cin >> n;
	unordered_map<string,int> cnt;
	while(n--){
		string str;
		cin >> str;
		cnt[str]++;
	}//统计每行出现的次数
	
	int res = 0;
	// for(auto& v:cnt) res = max(res,v.second);
	for(auto& [k,v]:cnt) res = max(res,v);
	cout<<res<<endl;
	
	return 0;
}