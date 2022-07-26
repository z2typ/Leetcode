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
    
    void reverse(ListNode* head,ListNode* kth,ListNode* parent){
        
        if(head!=kth){
            reverse(head->next,kth,head);
        }
        
        head->next = parent;
        
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int K = k;
        head = new ListNode(0,head);
        ListNode* subHead = head->next;
        ListNode* kth = head;
        ListNode* new_head = head;
        while(true){
            K = k;
            while(kth!=NULL && K--){
                kth = kth->next;
            }
            if(kth==NULL) break;
                    
            ListNode* nextSubHead = kth->next;
            reverse(subHead,kth,nextSubHead);
            new_head->next = kth;
            
            new_head = subHead;
            kth = subHead;
            subHead = nextSubHead;
            
        }

        
        return head->next;
    }
};