/*
 * @lc app=leetcode.cn id=3 lang=java
 *
 * [3] 无重复字符的最长子串
 */
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length(), len = 0;
        Map<Character, Integer> map = new HashMap<>();
        for (int i = 0, j = 0; j < n; j++) {
            if (map.containsKey(s.charAt(j))) {
                i = Math.max(map.get(s.charAt(j)) + 1, i);
            }
            len = Math.max(len, j - i + 1);
            map.put(s.charAt(j), j);
        }
        return len;
    }
}
