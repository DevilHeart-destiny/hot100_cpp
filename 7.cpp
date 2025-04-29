/**
42. 接雨水
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 */

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        vector<int> lmax(height.size());
        vector<int> rmax(height.size());
        lmax[0] = height[0];
        rmax[height.size()-1] = height[height.size()-1];
        for(int i = 1; i < height.size(); i++)
        {
            lmax[i] = max(lmax[i-1],height[i]);
        }
        for(int i = height.size()-2; i >= 0; i--)
        {
            rmax[i] = max(rmax[i+1],height[i]);
        }
        for(int i = 1; i < height.size()-1; i++)
        {
            res += min(rmax[i],lmax[i])-height[i];
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << s.trap(height) << endl;
    return 0;
}