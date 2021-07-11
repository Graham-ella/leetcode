//unordered_map是无序的map(C++容器)
//内部用哈希表实现
//插入，删除，查找都是O(1)的复杂度
//下面给出基本的使用方法:
#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
	unordered_map<char,int> m;//key:char类型 value:int类型
	m['a'] = 9;
	m['?'] = 5;
	m['z'] = 99;
	m['A'] = 50;
	m[' '] = 0;
	cout << m.size() << endl;
	if(m.count(' ')) == 1){
		cout << m[' '] << endl;
	}
	for(auto it = m.begin();it!=m.end();it++){
		cout << it->first << " " << it->second << endl; 
	}
	return 0;
	
}
