//原题链接：https://leetcode-cn.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/

class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        vector<int> l[2], r[2];//定义一下两种状态
        l[0] = l[1] = r[0] = r[1] = vector<int>(n);//初始化一个长度为n的数组
        for (int i = 0; i < 2; i++) {
            for (int j = 0, c = 0, k = i; j < n; j++, k ^= 1) {
                if (k != s[j] - '0') {
                    c++;
                }
                l[i][j] = c;
            }
        }
        for (int i = 0; i < 2; i++) {
            for (int j = n - 1, c = 0, k = i; j >= 0; j--, k ^= 1) {
                if (k != s[j] - '0') {
                    c++;
                }
                r[i][j] = c;
            }
        }
        if (n % 2 == 0) {
            return min(l[0][n - 1], l[1][n - 1]);
        }
        else {
            int res = min(l[0][n - 1], l[1][n - 1]);
            for (int i = 0; i + 1 < n; i++) {
                res = min(res, l[0][i] + r[1][i + 1]);
                res = min(res, l[1][i] + r[0][i + 1]);
            }
            return res;
        }
    }
};