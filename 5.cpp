/**
11. 盛最多水的容器
给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
返回容器可以储存的最大水量。

说明：你不能倾斜容器。
 */

#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public:
        int maxArea(vector<int>& height) {
            int left = 0;
            int right = height.size()-1;
            int result = 0;
            while(left < right)
            {
                result = max(min(height[left],height[right]) * (right-left), result);
                if(height[left] < height[right])
                {
                    left++;
                }
                else right--;
            }
            return result;
        }
    };
int main()
{
    Solution s;
    vector<int> nums = {1,8,6,2,5,4,8,3,7};
    cout << s.maxArea(nums) << endl;
    return 0;
}