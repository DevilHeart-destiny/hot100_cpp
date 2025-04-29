/**
105. 从前序与中序遍历序列构造二叉树
给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。

示例 1:
输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
输出: [3,9,20,null,null,15,7]
示例 2:
输入: preorder = [-1], inorder = [-1]
输出: [-1]
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0 || inorder.size() == 0) return nullptr;
        return traversal(preorder, inorder, 0, 0, inorder.size()-1);
    }

    TreeNode* traversal(vector<int>& preorder, vector<int>& inorder, int prestart, int instart, int inend)
    {
        if(prestart >= preorder.size() || instart > inend) return nullptr;

        int rootval = preorder[prestart];
        TreeNode* root = new TreeNode(rootval);

        int inindex = -1;
        for(int i = instart; i <= inend; i++)
        {
            if(inorder[i] == rootval)
            {
                inindex = i;
                break;
            }
        }

        int leftsubtreesize = inindex - instart;

        root->left = traversal(preorder,inorder,prestart+1,instart,inindex-1);
        root->right = traversal(preorder,inorder,prestart+leftsubtreesize+1,inindex+1,inend);
        return root;
    }
};
 
 void tranverse(TreeNode* root, vector<int>& res)
 {
    if(root == nullptr) return;
    tranverse(root->left,res);
    res.push_back(root->val);
    tranverse(root->right,res);
 }
 int main()
 {
    Solution s;
    vector<int> pre = {3,9,20,15,7};
    vector<int> mid = {9,3,15,20,7};
    TreeNode* r = s.buildTree(pre,mid);
    vector<int> res;
    tranverse(r,res);
    for(auto& n : res)
    {
        cout << n << ' ';
    }
    return 0;
 }  