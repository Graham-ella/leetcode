//还是原来的思路
//设计一个unordered_map key为sal值，value为这个sal对应的vector<int>
#include <iostream>
#include <unordered_map>
using namespace std;

int findMaxSAL(unordered_map<int, vector<int>> map);
int findMaxPoint(vector<int> *temp);


int main() {
	int n;//工单数量
	cin >> n;
	unordered_map<int, vector<int>> map;
	
	//读n次
	for (int i = 1; i <= n; i++) {
		int sal;
		cin >> sal;
		int point;
		cin >> point;
		if (map.count(sal)) {//如果之前已经有这个sal值了
			map[sal].push_back(point);
		}
		else {//如果之前没有过
		    map[sal] = vector<int>({ point });
		}

	}//读取sal和point

	//现在就对应上了

	//这个到什么时候肯定能停了呢？当处理的工单数量达到n时吗？不可能
	//应该是到时间截至了（求最大的sal）
	//可能在时间截至之前就已经处理完全部工单了

	
	//还是得先找到最大的sal才行

	int maxSAL = findMaxSAL(map);
	int count = 0;//已经处理的工单数量
	int Time = 1;//当前时间
	int sum = 0;
	int j = Time;
	//不能通过处理工单数==count来判断while退出条件
	while ((Time <= maxSAL) && (count < n) && (j < maxSAL)) {
		j = Time;
		while (!map.count(j)||map[j].size()==0) {
			j++;
		}
		//sal为j的就是我们要做的工单，此时我们还要找到积分最多的那个
		//把最大积分找到，找到了删除即可
		int maxPoint = findMaxPoint(&map[j]);
		sum += maxPoint;
		Time++;
		count++;
	}

	cout << sum << endl;
	
	return 0;
	
}


int findMaxSAL(unordered_map<int, vector<int>> map) {
	
	int maxSAL = -1;
	for (unordered_map<int, vector<int>>::iterator it = map.begin(); it != map.end(); it++) {
		if (it->first > maxSAL) {
			maxSAL = it->first;
		}
	}
	return maxSAL;
}

int findMaxPoint(vector<int> *temp) {
	int maxPoint = -1;
	int maxPointIndex = -1;
	for (int i = 0; i <(*temp).size(); i++) {
		if ((*temp)[i] > maxPoint) {
			maxPoint = (*temp)[i];
			maxPointIndex = i;
		}
	}
	
	vector<int>::iterator it = (*temp).begin();
	for (int i = 0; i < maxPointIndex; i++) {
		it++;
	}

	(*temp).erase(it);

	return maxPoint;
}