/**
104. 二叉树的最大深度
给定一个二叉树 root ，返回其最大深度。
二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数。

示例 1：
输入：root = [3,9,20,null,null,15,7]
输出：3
示例 2：
输入：root = [1,null,2]
输出：2
 */

 #include<iostream>
 #include<vector>
 
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
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return 1+max(left,right);
    }
};
 
 int main()
 {
     Solution s;
     TreeNode* root = new TreeNode(0);
     root->left = new TreeNode(2);
     root->right = new TreeNode(5);
     root->left->left = new TreeNode(9);
     cout << s.maxDepth(root) << endl;
     return 0;
 }