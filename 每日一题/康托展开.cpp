/*
康托展开 : 一个全排列 到 一个自然数的 双射
已知 1,2,3,...,n-1,n 这n个数 可以构成的全排列有n!个
随便给我们一个全排列s 利用康托展开算出来的就是 在n!个全排列里比它小的排列的个数
因此 要想知道 全排列s在所有全排列里排名第几个 只需要 康托展开+1 即可

cantor[s] = a[1](n-1)! + a[2](n-2)! + ... + a[k](k-1)! + ... + a[n]0!
其中a[k]代表 后面还未出现的数字里有多少比当前数字小的数

举个例子: 4 2 3 1
cantor[4231] = 3 * 3! + 1 * 2! + 1 * 1! + 0 * 0! = 18 + 2 + 1 = 21
因此4231在所有排列里排名在 22
*/

void init(){
    int f[10]; // 递归求出 0! - 9!
    f[0] = 1;
    for(int i = 1 ; i <= 9; ++i) f[i] = f[i-1]*i;
}

int cantor(int a[],int n){
    int res = 0;
    for(int i = 0 ; i < n ; ++i){
        int cnt = 0;
        for(int j = i + 1 ; j < n ; ++j)
            if(a[j] < a[i]) cnt++;
        // 算出系数
        res += cnt * fact[n - 1 - i];
    }
    return res + 1; // 返回它的排名
}

/*
上面也提到了 这是一个双射
如果高速我们某个排列的名次(或者比它小的个数) 显然我们可以逆推出它的样子

举个例子 : 4231 它的排名是22 cantor的结果为21
所以我们用21逆康托推回去 商代表当前未出现的数里有几个比当前系数小
21 / 3! = 3 ... 3   得到 4 
3 /  2! = 1 ... 1   得到 2 
1 /  1! = 1 ... 0   得到 3
0 / 0! = 0 ... 0    得到 1
*/

vector<int> recantor(int x , int n){
    x--; // 得到真实的cantor值
    vector<int> res(n);
    int cnt;
    bool st[n+1]; // 来标记 1 - n 中的数出现过了没
    memset(st,0,sizeof(st));
    
    for(int i = 0 ; i < n ; ++i){
        cnt = x / f[n - 1 - i]; // 获得未出现的比当前系数小的数的个数
        x %= f[n - 1 - i]; // 更新x
        for(int j = 1 ; j <= n ; ++j){
            if(st[j]) continue;
            if(!cnt){ // 找到了当前的系数
                st[j] = 1;
                res[i] = j;
                break;
            }
            cnt--; // 没找完继续找
        }
    }
    
    return res;
}
