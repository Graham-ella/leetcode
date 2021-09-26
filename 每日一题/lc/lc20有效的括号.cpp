class Solution {
public:
    bool isValid(string s) {
       int n = s.size();
        if (n % 2) return false;
        stack<char> stack;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stack.push(s[i]);
            }
            else {
                if (stack.empty()) return false;
                else {
                     if ((s[i]-stack.top())!=2&&((s[i] - stack.top()) != 1)) {
                        return false;
                    }
                    else stack.pop();
                }
            }
        }
        return stack.empty();
    }
};