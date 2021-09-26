#include <iostream>

using namespace std;

int main(){
    int T;//代表输入的数据组数
    cin>>T;
    while(T--){
        int res = 0;//当前组数的最后结果
        int n,x;
        cin>>n>>x;
        if(n<=2){
            res = 1;
        }else{
            res = (n-2+x-1)/x+1;
        }
        cout<<res<<endl;
    }
}