/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxi=0;
    int dfs(TreeNode* root,int par_val)
    {
        if(root==nullptr)
        {
            return 0;
        }
        int left=dfs(root->left,root->val);
        int right=dfs(root->right,root->val);
        maxi=max(maxi,left+right);
        if(root->val==par_val) return 1+max(left,right);
        else{
            return 0;
        }
    }
    int longestUnivaluePath(TreeNode* root) {
        dfs(root,0);
        return maxi;
    }
};