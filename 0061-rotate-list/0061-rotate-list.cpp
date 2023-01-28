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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(!head||!head->next||k==0){
            return head;
        }
        
        int lenLL=1;
        ListNode* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
            lenLL++;
        }
        
        temp->next=head;
        k=k%lenLL;
        int cutPnt=lenLL-k;
        
        while(cutPnt>0){
            temp=temp->next;
            cutPnt--;
        }
        
        
        head=temp->next;
        temp->next=NULL;
        
        return head;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
//         if(head==NULL||head->next==NULL){
//                 return head;
//             }
//         while(k>0){
//             ListNode* dummy=head;
//             ListNode* temp=head->next;
            
//             while(temp->next!=NULL){
//                 temp=temp->next;
//                 dummy=dummy->next;
//             }
//             dummy->next=temp->next;
//             temp->next=head;
//             head=temp;
//             k--;
//         }
//         return head;
    }
};