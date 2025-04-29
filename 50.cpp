/**
124. 二叉树中的最大路径和
二叉树中的 路径 被定义为一条节点序列，序列中每对相邻节点之间都存在一条边。
同一个节点在一条路径序列中至多出现一次 。该路径至少包含一个节点，且不一定经过根节点。
路径和是路径中各节点值的总和。
给你一个二叉树的根节点 root ，返回其 最大路径和 。

示例 1：
输入：root = [1,2,3]
输出：6
解释：最优路径是 2 -> 1 -> 3 ，路径和为 2 + 1 + 3 = 6
示例 2：
输入：root = [-10,9,20,null,null,15,7]
输出：42
解释：最优路径是 15 -> 20 -> 7 ，路径和为 15 + 20 + 7 = 42
 */

 #include<iostream>
 #include<vector>
 #include<climits>
 #include<unordered_map>
 
 using namespace std;
 
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    
    int dfs(TreeNode* root, int& val)
    {
        if(root == nullptr) return 0;

        int left = dfs(root->left,val);
        int right = dfs(root->right,val);

        int lmr = root->val + max(0,left) + max(0,right);
        int ret = root->val + max(0,max(left,right));
        val = max(val,max(ret,lmr));
        return ret;
    }

    int maxPathSum(TreeNode* root) {
        int val = INT_MIN;
        dfs(root,val);
        return val;
    }
};
 
 int main()
 {
     Solution s;
     TreeNode* root = new TreeNode(2);
     root->left = new TreeNode(2);
     root->right = new TreeNode(2);
     root->left->left = new TreeNode(2);
     cout << s.maxPathSum(root) << endl;
     return 0;
 }