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
    int dfs(TreeNode* root,unordered_map<int,int>& un)
    {
        if(root==nullptr)
        {
            return 0;
        }
        int sum=root->val+dfs(root->left,un)+dfs(root->right,un);
        un[sum]++;
        maxi=max(maxi,un[sum]);
        return sum;
        
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int> un;
        dfs(root,un);
        vector<int> ans;
        for(auto i:un)
        {
            if(i.second==maxi) ans.push_back(i.first);
        }
        


        return ans;

    }
};