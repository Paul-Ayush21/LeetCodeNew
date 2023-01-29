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
    ListNode *detectCycle(ListNode *head) {
        
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* temp=head;
        
        
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow){
                while(temp!=slow){
                    temp=temp->next;
                    slow=slow->next;
                }
                return slow;
            }
        }
        return NULL;
//         while(fast!=slow){
//             if(fast->next==NULL || fast->next->next==NULL){
//                 return NULL;
//             }
//             slow=slow->next;
//             fast=fast->next->next;
            
//         }
        
        
//         while(temp!=slow){
//             slow=slow->next;
//             temp=temp->next;
//         }
        
//         return slow;
    }
};