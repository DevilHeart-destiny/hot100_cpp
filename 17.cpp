/**
41. 缺失的第一个正数
提示
给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。
 
示例 1：
输入：nums = [1,2,0]
输出：3
解释：范围 [1,2] 中的数字都在数组中。
示例 2：
输入：nums = [3,4,-1,1]
输出：2
解释：1 在数组中，但 2 没有。
示例 3：
输入：nums = [7,8,9,11,12]
输出：1
解释：最小的正数 1 没有出现。
 */

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
int firstMissingPositive(vector<int>& nums) {
    // 原地哈希
        for(int i = 0; i < nums.size(); i++)
        {
            while(nums[i] != i+1)
            {
                if(nums[i] <= 0 || nums[i] > nums.size() || nums[nums[i]-1] == nums[i]) break;
                int idx = nums[i]-1;
                nums[i] = nums[idx];
                nums[idx] = idx+1;
            }

        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != i+1) return i+1; // 判断条件不能写成nums[i]-1 != i，尽量写加不写减，当nums[i]为intmin时减1可能会造成溢出
        }
        return nums.size()+1;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1,2,0};
    cout << s.firstMissingPositive(nums) << endl;
    return 0;
}