/**
4. 寻找两个正序数组的中位数
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
算法的时间复杂度应该为 O(log (m+n)) 。

示例 1：
输入：nums1 = [1,3], nums2 = [2]
输出：2.00000
解释：合并数组 = [1,2,3] ，中位数 2
示例 2：
输入：nums1 = [1,2], nums2 = [3,4]
输出：2.50000
解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5

提示：
nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106
 */

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int n1 = nums1.size();
        const int n2 = nums2.size();
        if(n1 > n2) return findMedianSortedArrays(nums2,nums1);
        int left = 0;
        int right = nums1.size()-1;
        int k = (n1 + n2 + 1)/2;
        while(left <= right)
        {
            int m1 = left + (right - left)/2;
            int m2 = k - m1;
            if(nums1[m1] < nums2[m2-1])
            {
                left = m1+1;
            }
            else{
                right = m1-1;
            }
        }
        int m1 = left;
        int m2 = k-left;
        cout<< m1 << ' ' << m2 << endl;
        int c1 = max(m1 <= 0 ? INT_MIN : nums1[m1-1],m2 <= 0 ? INT_MIN : nums2[m2-1]);
        if((n1+n2)%2 == 1)
        {
            cout << "c1 :" << c1 << endl;
            for(auto n : nums1)
            {
                cout << n << ' ';
            }
            cout << endl;
            return c1;
        }
        int c2 = min(m1 >= n1 ? INT_MAX : nums1[m1],m2 >= n2 ? INT_MAX : nums2[m2]);
        cout << "c2 :" << c2 << endl;
        for(auto n : nums2)
        {
            cout << n << ' ';
        }
        cout << endl;
        return (c1+c2)*0.5;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3};
    cout << s.findMedianSortedArrays(nums1,nums2) << endl;
    return 0;
}