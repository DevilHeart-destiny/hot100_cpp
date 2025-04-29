/**
189. 轮转数组
给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。

示例 1:
输入: nums = [1,2,3,4,5,6,7], k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右轮转 1 步: [7,1,2,3,4,5,6]
向右轮转 2 步: [6,7,1,2,3,4,5]
向右轮转 3 步: [5,6,7,1,2,3,4]
 */

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // foolish method
        // int len = nums.size();
        // if(k > len) k = k%len;
        // vector<int> tmp(nums.size());
        // int tmp_index = 0;
        // for(int i = len-k; i < len; i++)
        // {
        //     tmp[tmp_index++] = nums[i]; 
        // }
        // for(int i = 0; i < len-k; i++)
        // {
        //     tmp[tmp_index++] = nums[i]; 
        // }
        // for(int i = 0; i < len; i++)
        // {
        //     nums[i] = tmp[i];
        // }

        // fanzhuan
        k %= nums.size();
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;
    s.rotate(nums,k);
    for(auto r : nums)
    {
        cout << r << ' ';
    }
    return 0;
}