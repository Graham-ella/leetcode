/*
很巧妙的思路:
利用sort函数对str根据字典序进行排序
然后只需要获得第一个和最后一个字符串的公共前缀即可
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        sort(str.begin(),str.end());
        string &s1=str.front();
        string &s2=str.back();
        int i=0;
        while(i<s1.size()&&i<s2.size()&&s1[i]==s2[i]){
            ++i;
        }
        return string(s1.begin(),s1.begin()+i);
    }
};