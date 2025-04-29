/**
56. 合并区间
以数组 intervals 表示若干个区间的集合，
其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。

示例 1
输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
输出：[[1,6],[8,10],[15,18]]
解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 */

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //贪心
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end(),[](const vector<int>& l,const vector<int>& r){
            return l[0] < r[0];
        });
        res.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++)
        {
            if(res.back()[1] >= intervals[i][0])
            {
                res.back()[1] = max(intervals[i][1], res.back()[1]);
            }
            else{
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> res = s.merge(intervals);
    for(auto interval : res)
    {
        for(auto n : interval)
        {
            cout << n << ' ';
        }
        cout << endl;
    }
    return 0;
}