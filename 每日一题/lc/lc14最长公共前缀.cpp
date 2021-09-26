/*
思路:
要计算最长的公共前缀，可以考虑用0号字符串为基准
其实要得到返回值只需要知道公共前缀末端的下标是多少？
因此假设最开始index = len0
后面遍历每个字符串的过程中，如果当前字符串和0号字符串的公共前缀长度<index 更新index即可
这样循环后就得到了最后的index
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        int strNum = strs.size();
        int len0 = strs[0].size();
        int index = len0;
        // 以0号字符串为基准
        for(int j = 1;j<strNum;j++){//遍历每一个字符串
            int temp = 0;
            int tempLen = strs[j].size();
            while(temp<tempLen && temp < index && strs[j][temp] == strs[0][temp]){
                temp++;
            }
            if(temp < index) index = temp;
        }
        return strs[0].substr(0,index);
    }
};