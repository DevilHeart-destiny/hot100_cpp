/**
199. 二叉树的右视图
给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

示例 1：
输入：root = [1,2,3,null,5,null,4]
输出：[1,3,4]

示例 2：
输入：root = [1,2,3,4,null,null,null,5]
输出：[1,3,4,5]
 */
#include<iostream>
#include<vector>
#include<queue>

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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> qu;
        vector<int> res;
        qu.push(root);
        while(!qu.empty())
        {
            int qu_size = qu.size();
            while(qu_size != 1)
            {
                TreeNode* cur = qu.front();
                if(cur->left) qu.push(cur->left);
                if(cur->right) qu.push(cur->right);
                qu.pop();
                qu_size--;
            }
            TreeNode* r = qu.front();
            qu.pop();
            if(r->left) qu.push(r->left);
            if(r->right) qu.push(r->right);
            res.emplace_back(r->val);
        }
        return res;
    }
};

int main()
{
    Solution s;
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    vector<int> res = s.rightSideView(root);
    for(auto& n : res)
    {
        cout << n << ' ';
    }
    return 0;
}