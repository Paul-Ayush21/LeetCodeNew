/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *itr= head;
        Node *front=head;
        while(itr!=NULL){
            front=itr->next;
            Node *newn= new Node(itr->val);
            itr->next=newn;
            newn->next=front;
            itr=front;
        }
        
        itr=head;
        while(itr!=NULL){
            if(itr->random !=NULL){
                itr->next->random=itr->random->next;
            }
            itr=itr->next->next;
        }
        
        Node* dummy = new Node(0);
        // dummy->next=itr->next;
        Node *x= dummy;
        itr=head;
        while(itr!=NULL){
            front=itr->next->next;
            x->next=itr->next;
            // x=itr->next;
            itr->next=front;
            // x->next=front->next;
            x=x->next;
            itr=front;
        }
        return dummy->next;
        
        
    }
};