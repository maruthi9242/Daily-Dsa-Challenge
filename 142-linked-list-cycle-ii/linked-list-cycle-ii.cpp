/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode * detectCycle(ListNode *head) {
        set<ListNode*> set;
        
        int count=0;
        while(head!=nullptr)
        {
            if(set.contains(head)) return head;
            set.insert(head);
            
            head=head->next;
        }
        return nullptr;
    }
};