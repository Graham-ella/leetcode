/*
left = 0 right = nums.size() - 1
while(left<right)
left = mid + 1
right = mid -1
return时候还要打个补丁
*/
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        //int index = -1;
        int left = 0;
        int right = nums.size() - 1;

        while (left < right)
        {
            int mid = left + (right - left) / 2; // 这样选取的话 nums为偶数时会选取左侧值
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return (nums[left] == target)?left:-1;
    }
};

/*
left = 0 right = nums.size() - 1
while(left<=right)
left = mid + 1
right = mid - 1
*/
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        //int index = -1;
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2; // 这样选取的话 nums为偶数时会选取左侧值
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return -1;
    }
};


