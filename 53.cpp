/**
207. 课程表
你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。
在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi] ，表示如果要学习课程 ai 则 必须 先学习课程  bi 。
例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。

示例 1：
输入：numCourses = 2, prerequisites = [[1,0]]
输出：true
解释：总共有 2 门课程。学习课程 1 之前，你需要完成课程 0 。这是可能的。
示例 2：
输入：numCourses = 2, prerequisites = [[1,0],[0,1]]
输出：false
解释：总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0 ；并且学习课程 0 之前，你还应先完成课程 1 。这是不可能的。
 */

 #include<vector>
 #include<iostream>
 #include<queue>
 #include<unordered_map>
 
 using namespace std;
 
 class Solution {
    public:
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            vector<int> indegree(numCourses,0);
            unordered_map<int,vector<int>> umap;
            vector<int> res;
            for(auto& pre : prerequisites)
            {
                indegree[pre[0]]++;
                umap[pre[1]].push_back(pre[0]);
            }

            queue<int> qu;
            for(int i = 0; i < indegree.size(); i++)
            {
                if(indegree[i] == 0)
                {
                    qu.push(i); 
                }
            }
            while(!qu.empty())
                    {
                        int cur = qu.front();
                        qu.pop();
                        res.push_back(cur);
                        vector<int> next = umap[cur];
                        if(next.size())
                        {
                            for(int j = 0; j < next.size(); j++)
                            {
                                indegree[next[j]]--;
                                if(indegree[next[j]] == 0) qu.push(next[j]);
                            }
                        }
                    }
            // cout << res.size() << ' ' << res[1];
            if(res.size() == numCourses) return true;
            return false;
        }
    };
 
 int main()
 {
     Solution s;
     int num = 4;
     vector<vector<int>> grid = {{1,0},{3,2},{2,3}};
     cout << s.canFinish(num,grid) << endl;
     return 0;
 }