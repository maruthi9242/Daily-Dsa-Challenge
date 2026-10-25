/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ans=new ListNode(0);
        ListNode* temp=ans;
        int sum=0;

        while(head!=nullptr)
        {
            if(sum!=0 and head->val==0)
            {
                temp->next=new ListNode(sum);
                sum=0;
                
                temp=temp->next;

            }
            sum+=head->val;
            head=head->next;
        }
        
        return ans->next;
    }
};