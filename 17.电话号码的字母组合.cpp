/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */
class Solution
{
public:
    vector<string> result;
    map<char, string> phone = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    void traceback(string combination, string next_digits)
    {
        if (next_digits.length() != 0)
        {
            char digit = next_digits[0];
            string letters = phone[digit];
            for (int i = 0; i < letters.length(); i++)
            {
                char letter = letters[i];
                traceback(combination + letter, next_digits.substr(1));
            }
        }
        else
        {
            result.push_back(combination);
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if (digits.length() != 0)
        {
            traceback("", digits);
        }
        return result;
    }
};
