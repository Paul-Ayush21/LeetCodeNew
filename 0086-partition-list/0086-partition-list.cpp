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
    ListNode* partition(ListNode* head, int x) {
        ListNode* left=new ListNode(0);
        ListNode* right=new ListNode(0);
        
        ListNode* leftp=left;
        ListNode* rightp=right;
        ListNode* temp=head;
        
        while(temp!=NULL){
            if(temp->val<x){
                leftp->next=temp;
                leftp=leftp->next;
            }
            else{
                rightp->next=temp;
                rightp=rightp->next;
            }
            temp=temp->next;
        }
        leftp->next=right->next;
        rightp->next=NULL;
        return left->next;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
//         ListNode* temp=head;
//         int count=0;
//         while(temp->val!=x){
//             temp=temp->next;
//             count++;
//         }
//         ListNode* temp2=head;
//         ListNode* k=head;
//         // k->next=head;
//         int count2=0;
//         for(int i=0;i<count;i++){
//             if(temp2->val>x){
//                 if(temp2->val>k->val){
//                     k=temp2;
//                 }
//             }
//             temp2=temp2->next;
//         }
//         ListNode* prev=head;
//         while(prev->next!=temp2){
//             prev=prev->next;
//         }
//         ListNode* k2=temp->next;
//         ListNode* k2Pre=temp;
//         while(k2!=NULL){
//             if(k2->val<temp->val){
//                 k2Pre->next=k2->next;
//                 k2->next=temp2;
//                 prev->next=k2;
//             }
//             k2=k2->next;
//             k2Pre=k2Pre->next;
//         }
        
//         return head;
    }
};