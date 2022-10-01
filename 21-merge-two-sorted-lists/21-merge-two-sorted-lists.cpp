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
        ListNode *p1=list1, *p2=list2;
        ListNode *head = NULL;
        ListNode *temp = head;
        while(p1 && p2){
            if(p1->val < p2->val){
                if(head==NULL){
                    temp = p1;
                    head = temp;
                    p1 = p1->next;
                    temp->next = NULL;
                }else{
                    temp->next = p1;
                    p1 = p1->next;
                    temp = temp->next;
                    temp->next = NULL;
                }
            }else{
                if(head==NULL){
                    temp = p2;
                    head = temp;
                    p2 = p2->next;
                    temp->next = NULL;
                }else{
                    temp->next = p2;
                    p2 = p2->next;
                    temp = temp->next;
                    temp->next = NULL;
                }
            }
        }
        
        if(p1){
            if(head)
                temp->next = p1;
            else
                return p1;
        }else{
            if(head)
                temp->next = p2;
            else
                return p2;
        }
        

        return head;
        
    }
};