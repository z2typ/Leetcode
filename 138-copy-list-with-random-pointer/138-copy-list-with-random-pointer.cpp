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
        
        unordered_map<Node*, int> index; // pointer : index (original list)
        unordered_map<int, Node*> addrs; // index : pointer (copy list)
        
        Node* copy_list = new Node(0);
        Node* temp = head;
        Node* copy_temp = copy_list;
        
        int i = 0;
        while(temp){
            index[temp] = i;
            copy_temp->next = new Node(temp->val);
            temp = temp->next;
            copy_temp = copy_temp->next;
            i++;
        }
        
        copy_list = copy_list->next; // needs to be deleted
        
        copy_temp = copy_list;
        
        i = 0;
        while(copy_temp){
            addrs[i] = copy_temp;
            copy_temp = copy_temp->next;
            i++;
        }
        
        temp = head;
        copy_temp = copy_list;
        
        while(temp){
            if(temp->random){
                copy_temp->random = addrs[index[temp->random]];
            }
            temp = temp->next;
            copy_temp = copy_temp->next;
        }
        
        return copy_list;
        
    }
};