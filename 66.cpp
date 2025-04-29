/**
33. 搜索旋转排序数组
整数数组 nums 按升序排列，数组中的值 互不相同 。
在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，
使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。
例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。
给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。
你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。

示例 1：
输入：nums = [4,5,6,7,0,1,2], target = 0
输出：4
示例 2：
输入：nums = [4,5,6,7,0,1,2], target = 3
输出：-1
示例 3：
输入：nums = [1], target = 0
输出：-1
 
提示：
1 <= nums.length <= 5000
-104 <= nums[i] <= 104
nums 中的每个值都 独一无二
题目数据保证 nums 在预先未知的某个下标上进行了旋转
-104 <= target <= 104
 */

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// on复杂度
// class Solution {
// public:
//     int erfen(const vector<int>& nums, int x, int y, int target)
//     {
//         int left = x;
//         int right = y;
//         while(left <= right)
//         {
//             int mid = left + (right - left)/2;
//             if(nums[mid] == target) return mid;
//             else if(nums[mid] < target) left = mid + 1;
//             else right = mid - 1;
//         }
//         return -1;
//     }


//     int search(vector<int>& nums, int target) {
//         int k = max_element(nums.begin(),nums.end()) - nums.begin();
//         // cout << k << endl;
//         int res = erfen(nums,0,k,target);
//         if(res == -1) res = erfen(nums,k+1,nums.size()-1,target);
//         return res;
//     }
// };

class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int n = (int)nums.size();
            if (!n) {
                return -1;
            }
            if (n == 1) {
                return nums[0] == target ? 0 : -1;
            }
            int l = 0, r = n - 1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (nums[mid] == target) return mid;
                // 左边或者右边至少有一边是连续递增的
                // 左边是连续的情况
                if (nums[0] <= nums[mid]) {
                    if (nums[0] <= target && target < nums[mid]) {// target在递增区域内，向左收缩
                        r = mid - 1;
                    } else {
                        l = mid + 1;
                    }
                } else {// 右边是连续的情况
                    if (nums[mid] < target && target <= nums[n - 1]) {// target在递增区域内，向右收缩
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
            }
            return -1;
        }
    };

int main()
{
    Solution s;
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 5;
    cout << s.search(nums,target) << endl;
    return 0;
}