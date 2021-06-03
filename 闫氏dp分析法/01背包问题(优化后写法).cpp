//01背包问题 题目链接如下：https://www.acwing.com/problem/content/2/

//N件物品，容量为V，每件物品只能使用一次

#include <iostream>
using namespace std;

const int N = 1010;

int n,m;//n代表物品数量, m代表背包容量

int w[N]={0};//存放物品的价格
int v[N]={0};//存放物品的体积
int f[N]={0};

int main(){
	cin>>n>>m;
	for(int i = 1; i <= N;i++){
		cin>>v[i]>>w[i];
	}
	for(int i = 1;i<=n;i++){
		for(int j = m;j>=v[i];j--){
				f[j] = max(f[j],f[j-v[i]]+w[i]);
		}
	}
	cout<<f[m]<<endl;
	return 0;
}

