class Solution {
public:
    string convert(string s, int numRows) {
    string res = "";
    int n = numRows;
    int len = s.size();
    if (n == 1 || len == 1) {
        return s;
    }
    for (int k = 0; k < n; k++) {
        if (k == 0 || k == n - 1) {
            for (int i = k; i < len; i += (2 * n - 2)) {
                res += s[i];
            }
        }//第0行和第n-1行比较特殊
        else {
            for (int p = k, q = 2 * n - 2 - k; p < len || q < len; p += (2 * n - 2), q += (2 * n - 2)) {
                if(p<len)res += s[p];
                if(q<len)res += s[q];
            }
        }
    }
    return res;
    }

   

};