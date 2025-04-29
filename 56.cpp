/**
78. 子集
给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。

示例 1：
输入：nums = [1,2,3]
输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
示例 2：
输入：nums = [0]
输出：[[],[0]]

提示：
1 <= nums.length <= 10
-10 <= nums[i] <= 10
nums 中的所有元素 互不相同
 */

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void backtracing(vector<int>& nums, int startIndex)
    {
        res.push_back(path);
        if(startIndex >= nums.size()) return;

        for(int i = startIndex; i < nums.size(); i++)
        {
            path.push_back(nums[i]);
            backtracing(nums,i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        path.clear();
        res.clear();
        backtracing(nums,0);
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1,2,3};
    vector<vector<int>> res = s.subsets(nums);
    for(auto rs : res)
    {
        for(auto r : rs)
        {
            cout << r << ' ';
        }
        cout << endl;
    }
}