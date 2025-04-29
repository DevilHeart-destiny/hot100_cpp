/**
438. 找到字符串中所有字母异位词
给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。

示例 1:
输入: s = "cbaebabacd", p = "abc"
输出: [0,6]
解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
示例 2:
输入: s = "abab", p = "ab"
输出: [0,1,2]
解释:
起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。
 */

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> window,need;
        for(char& c : p)
        {
            need[c]++;
        }
        int left = 0;
        int right = 0;
        int valid = 0;
        vector<int> res;

        while(right < s.size())
        {
            char c = s[right];
            right++;
            if(need.count(c))
            {
                window[c]++;
                if(need[c] == window[c])
                {
                    valid++;
                }
            }

            while((right-left)>=p.size())
            {
                if(valid == need.size())
                {
                    res.push_back(left);
                }
                char l = s[left];
                left++;
                if(need.count(l))
                {
                    if(window[l] == need[l])
                    {
                        valid--;
                    }
                    window[l]--;
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    string str = "cbaebabacd";
    string p = "abc";
    vector<int> res = s.findAnagrams(str,p);
    for(auto& n : res)
    {
        cout << n << ' ';
    }
    return 0;
}
/**
 * @brief 滑动窗口伪代码框架
 * // 滑动窗口算法伪码框架
void slidingWindow(string s) {
    // 用合适的数据结构记录窗口中的数据，根据具体场景变通
    // 比如说，我想记录窗口中元素出现的次数，就用 map
    // 如果我想记录窗口中的元素和，就可以只用一个 int
    auto window = ...

    int left = 0, right = 0;
    while (right < s.size()) {
        // c 是将移入窗口的字符
        char c = s[right];
        window.add(c);
        // 增大窗口
        right++;

        // 进行窗口内数据的一系列更新
        ...

        // *** debug 输出的位置 ***
        printf("window: [%d, %d)\n", left, right);
        // 注意在最终的解法代码中不要 print
        // 因为 IO 操作很耗时，可能导致超时

        // 判断左侧窗口是否要收缩
        while (window needs shrink) {
            // d 是将移出窗口的字符
            char d = s[left];
            window.remove(d);
            // 缩小窗口
            left++;

            // 进行窗口内数据的一系列更新
            ...
        }
    }
}
 * 
 */