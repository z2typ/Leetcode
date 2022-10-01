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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode* temp = head;
        while(temp){
            length += 1;
            temp = temp->next;
        }
        
        int k = length - n;
        
        ListNode* new_head = new ListNode(0,head);
        temp = new_head;
        while(k--){
            temp = temp->next;
        }
        temp->next = temp->next->next;
        
        return new_head->next;
        
    }
};