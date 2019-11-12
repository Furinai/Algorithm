/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int area = 0, l = 0, r = height.size() - 1;
        while (l < r)
        {
            area = max(area, min(height[l], height[r]) * (r - l));
            if (height[l] < height[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return area;
    }
};
