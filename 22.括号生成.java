/*
 * @lc app=leetcode.cn id=22 lang=java
 *
 * [22] 括号生成
 */
class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> res = new ArrayList<>();
        backtrace(res, "", 0, 0, n);
        return res;
    }

    public void backtrace(List<String> res, String cur, int open, int close, int max) {
        if (cur.length() == max * 2) {
            res.add(cur);
        }
        if (open < max) {
            backtrace(res, cur + "(", open + 1, close, max);
        }
        if (close < open) {
            backtrace(res, cur + ")", open, close + 1, max);
        }
    }
}
