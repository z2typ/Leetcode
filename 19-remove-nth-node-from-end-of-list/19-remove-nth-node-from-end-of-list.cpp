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
        head = new ListNode(0,head);
        ListNode* temp = head;
        int size = 0;
        while(temp){
            temp = temp->next;
            size += 1;
        }
        size = size - 1;
        
        temp = head;
        int k = size-n;
        while(k--){
            temp = temp->next;
        }
        ListNode* ptr = temp->next;
        temp->next = temp->next->next;
        delete   ptr;
        ptr = head;
        head = head->next;
        delete ptr;
        return head;
    }
};