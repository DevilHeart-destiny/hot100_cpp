/**
152. 乘积最大子数组
给你一个整数数组 nums ，请你找出数组中乘积最大的非空连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
测试用例的答案是一个 32-位 整数。

示例 1:
输入: nums = [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。
示例 2:
输入: nums = [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。

提示:
1 <= nums.length <= 2 * 104
-10 <= nums[i] <= 10
nums 的任何子数组的乘积都 保证 是一个 32-位 整数
 */

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> dp_max(nums.begin(),nums.end());
        vector<int> dp_min(nums.begin(),nums.end());
        int res = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            dp_max[i] = max(max(dp_max[i-1]*nums[i],nums[i]),dp_min[i-1]*nums[i]);
            dp_min[i] = min(min(dp_min[i-1]*nums[i],nums[i]),dp_max[i-1]*nums[i]);
            res = max(dp_max[i],res);
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {2,3,-2,4};
    cout << s.maxProduct(nums) << endl;
    return 0;
}