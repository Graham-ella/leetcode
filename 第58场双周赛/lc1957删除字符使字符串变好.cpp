class Solution {
public:
    string makeFancyString(string s) {
        string res;
        int len = s.size();
        for(int i = 0;i < len;i++){
            int j = i + 1;
            while(j<len && s[j]==s[i]){
                j++;
            }
            for(int k = 0;k<2&&k<(j-i);k++){
                res += s[i+k];
            }
            i = j - 1;
        }
        return res;

    }
};