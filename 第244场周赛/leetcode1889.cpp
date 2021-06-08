typedef long long LL;

const LL MOD = 1e9 + 7, INF = 1e18;

class Solution {
public:
    int minWastedSpace(vector<int>& a, vector<vector<int>>& bs) {
        sort(a.begin(), a.end());//先对包裹从小到大进行排序
        LL sum = accumulate(a.begin(), a.end(), 0ll);//

        int n = a.size();
        LL res = INF;
        for (auto& b : bs) {//遍历每一个供应商
            sort(b.begin(), b.end());//对供应商提供的箱子进行排序
            if (b.back() < a.back()) continue;//如果供应商提供的最大的箱子比我最大的包裹要小，直接去找下一个供应商
            LL t = -sum, last = -1;
            for (auto x : b) {//对当前供应商提供的所有箱子进行遍历
                int l = last, r = n - 1;//初始值l = -1 r = n-1
                while (l < r) {
                    int mid = l + r + 1 >> 1;
                    if (a[mid] > x) r = mid - 1;
                    else l = mid;
                }//通过二分查找，在包裹里找，从哪个包裹开始可以被放在第一个箱子里
                if (r == last) continue;
                t += (r - last) * x;
                last = r;
            }
            res = min(res, t);
        }

        if (res == INF) res = -1;
        return res % MOD;
    }
};
