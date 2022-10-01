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
    ListNode* reverse(ListNode* head,ListNode* parent=NULL){
        if(head==NULL){
            return head;
        }
        if(!head->next){
            head->next = parent;
            return head;
        }
        
        ListNode* new_head = reverse(head->next, head);
        head->next = parent;
        return new_head;
        
    }
    
    ListNode* reverseList(ListNode* head) {
        return reverse(head);
    }
};