/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */
class Solution
{
public:
    vector<string> res;
    void backtrace(string cur, int open, int close, int max)
    {
        if (cur.size() == max * 2)
        {
            res.push_back(cur);
        }
        if (open < max)
        {
            backtrace(cur + "(", open + 1, close, max);
        }
        if (close < open)
        {
            backtrace(cur + ")", open, close + 1, max);
        }
    }
    vector<string> generateParenthesis(int n)
    {
        backtrace("", 0, 0, n);
        return res;
    }
};
