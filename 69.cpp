/**
20. 有效的括号
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。

示例 1：
输入：s = "()"
输出：true
示例 2：
输入：s = "()[]{}"
输出：true
示例 3：
输入：s = "(]"
输出：false
示例 4：
输入：s = "([])"
输出：true
 */

#include<iostream>
#include<stack>
#include<string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if(s == "") return true;
        stack<char> st;
        for(const char& c : s)
        {
            if(c == '(') st.push(')');
            else if(c == '[') st.push(']');
            else if(c == '{') st.push('}');
            else if(!st.empty() && st.top() == c) st.pop();
            else return false;
        }
        return st.empty() ? true : false;
    }
};

int main()
{
    Solution s;
    string str = "([])";
    cout << s.isValid(str) << endl;
    return 0;
}