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
    ListNode* deleteMiddle(ListNode* head) {
        
        ListNode* parent = NULL;
        
        parent = head;
        ListNode* slow = NULL;
        slow = head->next;
        if(slow==NULL){
            return NULL;
        }
        
        ListNode* fast = head->next->next;
        
        while(fast!=NULL && fast->next!=NULL){
            parent = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        parent->next = slow->next;
        
        delete slow;
        slow = NULL;
        
        return head;
        
    }
};