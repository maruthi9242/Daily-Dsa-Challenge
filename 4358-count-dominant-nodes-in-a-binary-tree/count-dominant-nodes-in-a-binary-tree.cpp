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
    int count=0;
    int dfs(TreeNode* root)
    {
        if(root==nullptr)
        {
            return 0;
        }
        int left=dfs(root->left);
        int right=dfs(root->right);
        if(root->val>=left and root->val>=right)
        {
            count++;
        }
        return max(root->val,max(left,right));
    }
    int countDominantNodes(TreeNode* root) {
        dfs(root);
        return count;
        
    }
};