/*
按照道理来说 这种匹配方式要满足 ( 和 )数量相等
对于最后满足条件的字符串它的前缀中 )数量 不能比 (多
*/
class Solution {
public:
    vector<string> res;
    string s;
    
    void dfs(int l,int r,int n){
        if(l == n && r == n){
            res.push_back(s);
            return;
        }
        if(r > l) return;
        if(l == n + 1 || r == n + 1) return;

        s.push_back('(');
        dfs(l+1,r,n);
        s.pop_back();

        s.push_back(')');
        dfs(l,r+1,n);
        s.pop_back();
    }
    
    vector<string> generateParenthesis(int n) {
        if(n == 1) return vector<string>{"()"};
        dfs(0,0,n);
        return res;
    }
};