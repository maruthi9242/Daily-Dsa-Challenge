/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "null";
        string ans="";
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int k=q.size();

            for(int i=0;i<k;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                 
                
                if(temp)
                {
                    q.push(temp->left);
                    q.push(temp->right);
                    ans+=to_string(temp->val)+',';
                    
                }
                if(!temp){
                    ans+="null,";
                }
            }

        }
        return ans;
        
    }
    queue<TreeNode*> obtainQ(string str)
    {
        int i=0;
        
        int size=str.size();
        queue<TreeNode*> q;
        while(i<size)
        {
            if(str[i]==',')
            {
                i++;
                continue;
            }
            else if(str[i]=='n')
            {
                q.push(nullptr);
                i+=4;
                continue;
            }
            string num="";
            while(i<size and str[i]!=',')
            {
                num+=str[i++];
            }
            int number=stoi(num);
            TreeNode* root=new TreeNode(number);
            q.push(root);
        }
        return q;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<TreeNode*> q1=obtainQ(data);
        queue<TreeNode*> q2;
        TreeNode* root=q1.front();
        if(root==nullptr) return nullptr;
        q2.push(root);
        q1.pop();
        while(!q1.empty())
        {
            TreeNode* temp=q2.front();
            q2.pop();
            if(temp!=nullptr){
                TreeNode* templeft=q1.front();
                q1.pop();
                if(q1.empty()) break;
                if(templeft) temp->left=templeft;
                q2.push(templeft);
            
            
                TreeNode* tempright=q1.front();
                q1.pop();
                if(q1.empty()) break;
                if(tempright) temp->right=tempright;
                q2.push(tempright);
            }
            

        }
        return root;

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));