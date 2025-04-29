/**
238. 除自身以外数组的乘积
提示
给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。
题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。
请 不要使用除法，且在 O(n) 时间复杂度内完成此题。

示例 1:
输入: nums = [1,2,3,4]
输出: [24,12,8,6]
示例 2:
输入: nums = [-1,1,0,-3,3]
输出: [0,0,9,0,0]
 */

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // foolish method
        // int flag = 0; // zero num
        // vector<int> prefix_mul(nums.size());
        // vector<int> res(nums.size());
        // if(nums[0] == 0){
        //     flag = 1;
        //     prefix_mul[0] = 1;
        // }
        // else prefix_mul[0] = nums[0];
        // for(int i = 1; i < nums.size(); i++)
        // {
        //     if(nums[i] == 0)
        //     {
        //         flag++;
        //         prefix_mul[i] = prefix_mul[i-1];
        //     }
        //     else prefix_mul[i] = prefix_mul[i-1] * nums[i];
        // }
        // if(flag > 1)
        // {
        //     for(int i = 0; i < nums.size(); i++)
        //     {
        //         res[i] = 0;
        //     }
        // }
        // else if(flag == 0)
        // {
        //     for(int i = 0; i < nums.size(); i++)
        //     {
        //         res[i] = prefix_mul[nums.size()-1]/nums[i];
        //     }
        // }
        // else
        // {
        //     for(int i = 0; i < nums.size(); i++)
        //     {
        //         if(nums[i] == 0) res[i] = prefix_mul[nums.size()-1];
        //         else res[i] = 0;
        //     }
        // }

        // return res;

        // shuangzhizhen 
        int left = 0;
        int right = nums.size()-1;
        vector<int> res(nums.size(),1);

        int lp = 1;//zuocechengji
        int rp = 1;//youcechengji

        while(left < nums.size() && right >= 0)
        {
            res[right] *= rp;
            res[left] *= lp;
            rp *= nums[right--];
            lp *= nums[left++];
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1,2,3,4};
    vector<int> res = s.productExceptSelf(nums);
    for(auto n : res)
    {
        cout << n << ' ';
    }
    return 0;
}