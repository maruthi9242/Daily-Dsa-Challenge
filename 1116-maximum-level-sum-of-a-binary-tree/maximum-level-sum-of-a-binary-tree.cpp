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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level=0;
        int max_level=INT_MIN;
        int max_sum=INT_MIN;
        while(!q.empty())
        {
            int k=q.size();
            level++;
            int sum=0;
            for(int i=0;i<k;i++)
            {
                TreeNode* temp=q.front();
                sum+=temp->val;
                q.pop();
                if(temp->left!=nullptr) q.push(temp->left);
                if(temp->right!=nullptr) q.push(temp->right);
            }
            if(sum>max_sum)
            {
                max_sum=sum;
                max_level=level;
            }
        }

        return max_level;
    }
};