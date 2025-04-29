/**
128. 最长连续序列
给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
请你设计并实现时间复杂度为 O(n) 的算法解决此问题。

示例 1：
输入：nums = [100,4,200,1,3,2]
输出：4
解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
示例 2：
输入：nums = [0,3,7,2,5,8,4,6,0,1]
输出：9
示例 3：
输入：nums = [1,0,1,2]
输出：3
 
提示：
0 <= nums.length <= 105
-109 <= nums[i] <= 109
 */

#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> unset(nums.begin(),nums.end());

        int result = 0;
        for(auto& s : unset)
        {
            if(unset.find(s-1)!=unset.end()) continue;

            int curNum = s;
            int curLen = 1;
            while(unset.find(curNum+1)!=unset.end())
            {
                curNum += 1;
                curLen += 1;
            }
            result = max(result,curLen);
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
    cout << s.longestConsecutive(nums) << endl;
    return 0;
}