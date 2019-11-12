/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        int n = nums.size();
        if (nums.empty() || n < 3)
        {
            return result;
        }
        int l = 0, r = 0, s = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++)
        {
            if (nums[i] > 0)
            {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            l = i + 1;
            r = n - 1;
            while (l < r)
            {
                s = nums[i] + nums[l] + nums[r];
                if (s == 0)
                {
                    result.push_back(vector<int>{nums[i], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[l + 1])
                    {
                        l++;
                    }
                    while (l < r && nums[r] == nums[r + 1])
                    {
                        r--;
                    }
                    l++;
                    r--;
                }
                else if (s < 0)
                {
                    l++;
                }
                else if (s > 0)
                {
                    r--;
                }
            }
        }
        return result;
    }
};
