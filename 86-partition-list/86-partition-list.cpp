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
        if(head==NULL) return NULL;
        
        ListNode* i  = new ListNode();
        ListNode* j  = new ListNode();
        
        ListNode* temp = head;
        
        ListNode* i_ptr = i;
        while(temp!=NULL){
            if(temp->val < x){
                    i_ptr->next = new ListNode(temp->val);
                    i_ptr = i_ptr->next;
            }
            
            temp = temp->next;
        }
        
        temp = head;
        ListNode* j_ptr = j;
        
        while(temp!=NULL){
            if(temp->val >= x){
                    j_ptr->next = new ListNode(temp->val);
                    j_ptr = j_ptr->next;
            }
            
            temp = temp->next;
        }
        
        i_ptr->next = j->next;
        
        return i->next;
        
    }
};