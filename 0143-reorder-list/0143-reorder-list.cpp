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
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        ListNode* temp=head;
        ListNode* temp2=head;
        int count=0;
        while(temp!=NULL){
            st.push(temp);
            temp=temp->next;
            count++;
        }
        
        for(int i=0;i<count/2;i++){
            ListNode* k=st.top();
            k->next=temp2->next;
            temp2->next=k;
            temp2=temp2->next->next;
            st.pop();
        }
        temp2->next=NULL;
    }
};