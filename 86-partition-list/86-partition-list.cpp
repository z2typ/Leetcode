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
        
        ListNode* i  = NULL;
        ListNode* j  = NULL;
        
        ListNode* temp = head;
        
        ListNode* i_ptr = NULL;
        while(temp!=NULL){
            if(temp->val < x){
                if(i==NULL){
                    i = new ListNode(temp->val);
                    i_ptr = i;
                }else{
                    i_ptr->next = new ListNode(temp->val);
                    i_ptr = i_ptr->next;
                }
            }
            
            temp = temp->next;
        }
        
        temp = head;
        ListNode* j_ptr = NULL;
        
        while(temp!=NULL){
            if(temp->val >= x){
                if(j==NULL){
                    j = new ListNode(temp->val);
                    j_ptr = j;
                }else{
                    j_ptr->next = new ListNode(temp->val);
                    j_ptr = j_ptr->next;
                }
            }
            
            temp = temp->next;
        }
        if(i_ptr==NULL) return j;
        i_ptr->next = j;
        
        return i;
        
    }
};