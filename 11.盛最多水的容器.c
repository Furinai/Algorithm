/*
 * @lc app=leetcode.cn id=11 lang=c
 *
 * [11] 盛最多水的容器
 */

int max(int a, int b)
{
    return a > b ? a : b;
}
int min(int a, int b)
{
    return a < b ? a : b;
}
int maxArea(int *height, int heightSize)
{
    int area = 0, l = 0, r = heightSize - 1;
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
