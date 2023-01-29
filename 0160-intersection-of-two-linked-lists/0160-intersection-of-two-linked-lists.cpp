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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        
        if(headA==NULL || headB==NULL) return NULL;
        
        ListNode* tempA=headA;
        ListNode* tempB=headB;
        
        while(tempA!=tempB){
            tempA=tempA==NULL ?headB : tempA->next;
            tempB=tempB==NULL ?headA : tempB->next;
        }
        return tempA;
//         map<ListNode*,int> smap;
        
//         ListNode* temp=headA;
//         int cnt=1; 
//         while(temp->next!=NULL){  
//             smap[temp]=temp->val;
//             cnt++;
//             temp=temp->next;
//         }
        
//         ListNode* tempB=headB;
//         while(tempB->next!=NULL||tempB!=NULL){
//             if(smap.find(tempB)!=smap.end()){
//                 return tempB;
//             }
//             tempB=tempB->next;
//         }
//         return NULL;
        
    }
};