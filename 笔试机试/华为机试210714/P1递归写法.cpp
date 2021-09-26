#include <iostream>
#include <vector>
#define Max 1201
using namespace std;
char bee[Max][Max];
void pollute(int i, int j, int M, int N);

int main() {
	int M, N;
	cin >> M >> N;//读入行和列
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> bee[i][j];
		}
	}//到这里为止初始化完了bee数组
	
	int count = 0;
	
	char temp;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			temp = bee[i][j];
			if (temp == 'C') {
				count++;
				pollute(i, j, M, N);
			}
			else {
				continue;
			}
		}
	}
	
	cout << count << endl;
}

void pollute(int i, int j, int M, int N) {
	if (i >= 1 && i <= M && j >= 1 && j <= N) {
		if (bee[i][j] == 'C') {
			bee[i][j] = 'P';
			pollute(i - 1, j, M, N);
			pollute(i + 1, j, M, N);
			pollute(i, j - 1, M, N);
			pollute(i, j + 1, M, N);
			pollute(i - 1, j + 1, M, N);
			pollute(i + 1, j - 1, M, N);

		}
	}
	else {
		return;
	}
	
	
	
	
}

