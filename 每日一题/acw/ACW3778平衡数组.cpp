#include <iostream>;
#include <cstring>;
#include <algorithm>;

using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        cout << n << endl;
        for(int i = 1;i<=n;i++){
            cout << i << " ";
        }
        cout<<endl;
    }
    return 0;
}