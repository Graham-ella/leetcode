class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
          
        //维护一个大顶堆
        priority_queue<int> heap;
        for (auto x : arr) {
            heap.push(x);
            if (heap.size() > k) {
                heap.pop();
            }
        }
        
        vector<int> res;
        while (heap.size()) {
            res.push_back(heap.top());
            heap.pop();
        }
        reverse(res.begin(), res.end());
        return res;

    }
};