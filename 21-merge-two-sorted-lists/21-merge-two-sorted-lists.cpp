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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode();
        
        ListNode* p1 = list1;
        ListNode* p2 = list2;
        ListNode* p3 = head;
        
        while(p1!=NULL && p2!=NULL){
            if(p1->val<p2->val){
                p3->next = p1;
                p1 = p1->next;
                p3 = p3->next;
                p3->next = NULL;
            }else{
                p3->next = p2;
                p2 = p2->next;
                p3 = p3->next;
                p3->next = NULL;
            }
        }
        
        if(p1!=NULL){
            p3->next = p1;
        }else{
            p3->next = p2;
        }
        
        ListNode* temp = head;
        head = head->next;
        delete temp;
        
        return head;
        
    }
};