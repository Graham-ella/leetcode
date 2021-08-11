/*
如果一个年份的各位数字中非零数字不超过 1 个，则称该年是一个幸运年。
比如，100,40000,5 都是幸运年，而 12,3001,12345 则不是幸运年。
现在，给定你一个年份，请你求出当前年份距离下一个幸运年多少年？
*/

/*
思路:
题目很简单，幸运年都是些固定的年份，比如
1-9(假设不包含0)
10-90
100-900
....
因此只要枚举这些幸运年到最早能大于n的情况，打印差值就行了
*/
#include <iostream>;
#include <cstring>;
#include <algorithm>;

using namespace std;
typedef long long LL;

int main(){
    int T;//数据组数
    cin>>T;
    while(T--){
        int n;
        cin >> n;
        bool flag = false;
        for(LL i = 1; ;i*=10){
            for(int j = 1;j<10;j++){
                if(i*j>n){
                    cout<<i*j-n<<endl;
                    flag = true;
                    break;
                }
            }
            if(flag){
                break;
            }
        }
    }
    return 0;
}