/*
给定一个字符串 s , 请你找出其中不含有重复字符的最长子串的长度

输入: s = "abcabcbb"
输出 : 3
解释 : 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

输入: s = ""
输出: 0

0 <= s.length <= 5 * 10^4
s 由英文字母、数字、符号和空格组成

*/


/*
将字符串从头遍历到尾
遇到不同的字符串就将它存入哈希表中
如果有遇到重复的了，我读取此时表的大小，从重复的那个后面开始继续读
a b c a d e 
*/

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s == "") {
			return 0;
		}
		//bool flag = false;//标志位，代表有没有出现重复的
		int res = 0;
		unordered_map<char, int> map;
		int n = s.size();
		for (int i = 0; i < n; i++) {
			if (map.count(s[i])) {//如果map中之前已经有这个了
				res = (res > map.size()) ? res : map.size(); // 这一行不用也行
				i = map[s[i]];
				map.clear();
			}
			else {//如果map前之前没有
				map[s[i]] = i;
				res = (res > map.size()) ? res : map.size();
			}
		}
		return res;

	}
};



