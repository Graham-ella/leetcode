/*
接雨水：
1)双指针算法
按列来计算当前列能接多少雨水 分别往左往右跑 
时间复杂度为 O(n^2) 会 TLE
根本原因就在于每列我们都要遍历它左右两边 其实有很多地方重复算了

2)动态规划算法
如果我们 将位置i的左边最大高度 记录在数组maxLeft[i]中 
右边最大高度记录在数组maxRight[i]中
那么在求位置i的左边最大高度时 有 maxLeft[i] = max(maxLeft[i-1],height[i])
求右边最大高度时有 maxRight[i] = max(maxRight[i-1],height[i])
这样就避免了重复计算

*/

class Solution
{
public:
    // 重复计算太多 会TLE
    int trap(vector<int> &height)
    {
        int sum = 0;
        int len = height.size();
        for (int i = 0; i < len; i++)
        {
            if (i == 0 || i == len - 1)
                continue; //第一列和最后一列是无法接水的

            int rH = height[i]; // 代表右边的最高高度 如果当前列本来就是最高 r不变
            int lH = height[i]; // 同上

            for (int r = i + 1; r < len; r++)
            {
                if (height[r] > rH)
                    rH = height[r];
            }
            for (int l = i - 1; l >= 0; l--)
            {
                if (height[l] > lH)
                    lH = height[l];
            }
            int h = min(lH, rH) - height[i];
            sum += h;
        }
        return sum;
    }
};

class Solution
{
public:
    int trap(vector<int> &height)
    {
        if (height.size() <= 2)
            return 0;
        int len = height.size();
        vector<int> maxLeft(len, 0);
        vector<int> maxRight(len, 0);

        maxLeft[0] = height[0], maxRight[len - 1] = height[len - 1];
        for (int i = 1; i < len; i++)
        {
            maxLeft[i] = max(height[i], maxLeft[i - 1]);
        }

        for (int i = len - 2; i >= 0; i--)
        {
            maxRight[i] = max(height[i], maxRight[i + 1]);
        }

        int sum = 0;
        for (int i = 0; i < len; i++)
        {
            sum += min(maxLeft[i], maxRight[i]) - height[i];
        }
        return sum;
    }
};


/*
单调栈写法 没整明白
*/
class Solution
{
public:
    int trap(vector<int> &height)
    {
        stack<int> stack;

        int water = 0;
        //特殊情况
        if (height.size() < 3)
        {
            return 0;
        }
        for (int i = 0; i < height.size(); i++)
        {
            while (!stack.empty() && height[i] > height[stack.top()])
            {
                //栈顶元素
                int popnum = stack.top();
                stack.pop();
                //相同元素的情况例1，1
                while (!stack.empty() && height[popnum] == height[stack.top()])
                {
                    stack.pop();
                }
                //计算该层的水的单位
                if (!stack.empty())
                {
                    int temp = height[stack.top()]; //栈顶元素值
                    //高
                    int hig = min(temp - height[popnum], height[i] - height[popnum]);
                    //宽
                    int wid = i - stack.top() - 1;
                    water += hig * wid;
                }
            }
            //这里入栈的是索引
            stack.push(i);
        }
        return water;
    }
};
