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
    long long kthLargestLevelSum(TreeNode* root, int k) {

        priority_queue<long long> pq;
        queue<TreeNode*> q;
        q.push(root);
        long long sum=0;
        int level=0;
        while(!q.empty())
        {
            level++;
            int k=q.size();
            for(int i=0;i<k;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                sum+=temp->val;
                if(temp->left!=nullptr) q.push(temp->left);
                if(temp->right!=nullptr) q.push(temp->right);
            }
            
            pq.push(sum);
            sum=0;
        }
        if(k>level) return -1;
        k=k-1;
        
        

        while(k>0)
        {
            pq.pop();
            k--;
        }
        return pq.top();


        

        
    }
};