class Solution {
public:
    string countAndSay(int n) {
        string  res = "1";
        if(n == 1) return res; // 如果是1直接返回
        int cnt = 1;
        string temp;
        // 否则如果是 n > 1的话 需要走 n - 1次循环
        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j < res.size() ; j++){
                // 先看看当前字符出现了多少次
                while(j + 1 < res.size()  && res[j] == res[j+1]){
                    cnt++;
                    j++;
                }
                temp += cnt - 0 + '0';
                temp += res[j];
                cnt = 1;
                // 妙啊 按理来说这里的j还在原本相同一串数的最后位置 但是for最后有j++
            }
            res = temp;
            temp = "";
        }
        return res;
    }
};