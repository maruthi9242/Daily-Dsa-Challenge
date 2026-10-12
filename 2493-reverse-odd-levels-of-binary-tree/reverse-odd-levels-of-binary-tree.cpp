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
    TreeNode* reverseOddLevels(TreeNode* root) {
        int level=0;
        queue<TreeNode*> q;
        q.push(root);
        vector<TreeNode*> treenodes;
        vector<int> treevalues;
       
        while(!q.empty())
        {
            int k=q.size();
            for(int i=0;i<k;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                treenodes.push_back(temp);
                treevalues.push_back(temp->val);
                if(temp->left!=nullptr) q.push(temp->left);
                if(temp->right!=nullptr) q.push(temp->right);
            }
            level++;
            if(level%2==0){ 
                reverse(treevalues.begin(),treevalues.end());
                for(int i=0;i<treevalues.size();i++)
                {
                    treenodes[i]->val=treevalues[i];
                }
            };
     
            treenodes.resize(0);
            treevalues.resize(0);
        }
        return root;
        
    }
};