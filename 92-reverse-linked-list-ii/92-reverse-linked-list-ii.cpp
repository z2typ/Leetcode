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
    void reverse(ListNode* head,ListNode* right,ListNode* parent){
        if(!head){ return; }
        
        if(head!=right){
            reverse(head->next,right,head);
            head->next = parent;
        }
        
        head->next = parent;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* temp = head;
        head = new ListNode(0,head);
        ListNode* parent = head;
        ListNode* prevFirst = NULL;
        ListNode* second = NULL;
        int pos = 0;
        while(temp!=NULL){
            pos++;
            if(pos==left){
                prevFirst = parent;
            }
            if(pos==right){
                second = temp;
            }
            parent = temp;
            temp = temp->next;
            
        }
        reverse(prevFirst->next,second,second->next);
        
        prevFirst->next = second;
        
        return head->next;
        
    }
};