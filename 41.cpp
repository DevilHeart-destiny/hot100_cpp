/**
102. 二叉树的层序遍历
给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。

示例 1：
输入：root = [3,9,20,null,null,15,7]
输出：[[3],[9,20],[15,7]]
示例 2：
输入：root = [1]
输出：[[1]]
示例 3：
输入：root = []
输出：[]
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> qu;
        vector<vector<int>> res;
        qu.push(root);
        while(!qu.empty())
        {
            int len = qu.size();
            vector<int> r;
            while(len--)
            {
                TreeNode* node = qu.front();
                qu.pop();
                r.push_back(node->val);
                if(node->left) qu.push(node->left);
                if(node->right) qu.push(node->right);
            }
            res.push_back(r);
        }
        return res;
    }
};

int main()
{
    Solution s;
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(9);
    vector<vector<int>> res = s.levelOrder(root);
    for(auto& r : res)
    {
        for(auto& n : r)
        {
            cout << n << ' ';
        }
        cout << endl;
    }
    return 0;
}