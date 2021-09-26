//1897. 重新分配字符使所有字符串都相等

//如果要想让所有的字符串都相等，得保证每个出现过的字符(char)的个数
//可以被words的个数整除
//显然可以验证这个是充分必要条件


//unordered_map 容器，直译过来就是"无序 map 容器"的意思。
//所谓“无序”，指的是 unordered_map 容器不会像 map 容器那样对存储的数据进行排序。
//换句话说，unordered_map 容器和 map 容器仅有一点不同，即 map 容器中存储的数据是有序的，
//而 unordered_map 容器中是无序的。

//map是根据key的大小来排序的

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char, int> cnt;
        for (auto& w : words) {
            for (auto c : w) {
                cnt[c]++;
            }
        }
        for (auto [k, v] : cnt) {
            if (v % words.size()) {
                return false;
            }
        }
        return true;
    }
};