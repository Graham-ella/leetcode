#include <iostream>
#include <vector>
#define Max 1201
using namespace std;
char bee[Max][Max];

bool isConnect(int x1, int y1, int x2, int y2);//x1,y1 指我现在循环的 x2,y2是我rs里的

int main() {
	int M, N;
	cin >> M >> N;//读入行和列
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> bee[i][j];
		}
	}//到这里为止初始化完了bee数组

	/*
	思路:
	
	*/
	
	vector<vector<pair<int, int>>> rs;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			if (bee[i][j] == 'P') {
				continue;
			}
			else {
				if (rs.size() == 0) {
					pair<int, int> tempP(i,j);
					vector<pair<int, int>> tempV;
					tempV.push_back(tempP);
					rs.push_back(tempV);
				}
				else {
					int length1 = rs.size();
					int flag = false;
					for (int k = 0; k < length1; k++) {
						int length2 = rs[k].size();
						for (int q = 0; q < length2; q++) {
							if (isConnect(i, j, rs[k][q].first, rs[k][q].second)) {
								//如果有相邻
								//将这个当前的C加入其中
								flag = true;
								pair<int, int> p(i, j);
								rs[k].push_back(p);
								break;
							}
						}
					}
					//如果没有相邻的话，我就要自己添加新的
					if (!flag) {
						pair<int, int> tempP(i, j);
						vector<pair<int, int>> tempV;
						tempV.push_back(tempP);
						rs.push_back(tempV);

					}
					
				}

			}
		}
	}

	//rs此时已经好了
	cout << rs.size() << endl;
	return 0;

}

bool isConnect(int x1, int y1, int x2, int y2) {
	
   


	bool a1 = x1 == x2 && abs(y1 - y2) == 1;
	bool a2 = abs(x1 - x2) == 1 && y1 == y2;
	bool a3 = (x1 == x2 + 1 ) && (y1 == y2 - 1);



	/*if ((x1 == x2 && abs(y1 - y2) == 1) || (abs(x1 - x2) <= 1 && abs(y1 - y2) <= 1)) {
		return true;
	}*/

	if (a1 || a2 || a3) {
		return true;
	}

	return false;
}