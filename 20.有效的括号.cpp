/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
class Solution
{
public:
    bool isValid(string s)
    {
        if (s.length() % 2 != 0)
        {
            return false;
        }
        stack<char> sta;
        map<char, char> brackets;
        brackets.insert(map<char, char>::value_type(')', '('));
        brackets.insert(map<char, char>::value_type('}', '{'));
        brackets.insert(map<char, char>::value_type(']', '['));
        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];
            if (brackets.find(c) != brackets.end())
            {
                char top;
                if (sta.empty())
                {
                    top = '#';
                }
                else
                {
                    top = sta.top();
                    sta.pop();
                }

                if (top != brackets[c])
                {
                    return false;
                }
            }
            else
            {
                sta.push(c);
            }
        }
        return sta.empty();
    }
};
