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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        vector<int> v;
        q.push(root);
        
        while(!q.empty())
        {
            int k=q.size();

            for(int i=0;i<k;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                v.push_back(temp->val);
            }
            ans.push_back(v);
            v.resize(0);
        }
        int elem=ans[ans.size()-1][0];
        return elem;
    }
};