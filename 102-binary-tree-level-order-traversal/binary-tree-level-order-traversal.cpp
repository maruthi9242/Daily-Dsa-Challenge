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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr) return {};
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        vector<vector<int>> ans;
        vector<int> v;
        int level=1;
        while(!q.empty())
        {
            auto temp=q.front();
            q.pop();
            if(level!=temp.second){
                level=temp.second;
                ans.push_back(v);
                v.resize(0);
            }
            
                v.push_back(temp.first->val);
            
            if(temp.first->left!=nullptr) q.push({temp.first->left,temp.second+1});
            if(temp.first->right!=nullptr) q.push({temp.first->right,temp.second+1});
        }
        if(!v.empty()) ans.push_back(v);
        return ans;
    }
};