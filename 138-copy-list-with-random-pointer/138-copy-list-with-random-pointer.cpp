/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        Node* temp = head->next;
        Node* copyList = new Node(head->val);
        Node* temp2 = copyList;
        unordered_map<Node*,int> index;
        index[head] = 0;
        int i = 1;
        while(temp){
            temp2->next = new Node(temp->val);
            index[temp] = i;
            temp = temp->next;
            i++;
            temp2 = temp2->next;
        }
        
        
        
        unordered_map<int,Node*> ptr;
        temp2 = copyList;
        i=0;
        while(temp2){
            ptr[i] = temp2;
            temp2 = temp2->next;
            i++;
        }
        
        temp2 = copyList;
        temp = head;
        while(temp2){
            if(temp->random != NULL)
            temp2->random = ptr[index[temp->random]];
            temp2 =temp2->next;
            temp = temp->next;
        }
        
        return copyList;
        
    }
};