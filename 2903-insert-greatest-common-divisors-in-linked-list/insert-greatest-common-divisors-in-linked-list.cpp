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
    int GCD(int a,int b)
    {
        int mini=min(a,b);
        for(int i=mini;i>=1;i--)
        {
            if(a%i==0 and b%i==0)
            {
                return i;
            }
        }
        return mini;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp=head;
        while(temp!=nullptr and temp->next!=nullptr){
            ListNode* temp1=temp->next;
            temp->next=new ListNode(GCD(temp->val,temp1->val),temp1);
            temp=temp->next->next;
        }
        return head;
        
    }
};