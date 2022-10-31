class LRUCache {
    HashMap<Integer,Node> hm = new HashMap<>();
    Node head = new Node(0,0);
    Node tail = new Node(0,0);
    
    int capacity = 0;
    public LRUCache(int capacity) {
        this.capacity = capacity;
        head.next = tail;
        tail.prev = head;
    }
    
    public int get(int key) {
        if(hm.containsKey(key)){
            Node node = hm.get(key);
            Node prev_node = node.prev;
            Node next_node = node.next;
            prev_node.next = next_node;
            next_node.prev = prev_node;
            Node head_next = head.next;
            head.next = node;
            node.prev = head;
            node.next = head_next;
            head_next.prev = node;
            return node.val;
        }
        else
            return -1;
    }
    
    public void put(int key, int value) {
        if(hm.containsKey(key)){
            Node node = hm.get(key);
            Node prev_node = node.prev;
            Node next_node = node.next;
            prev_node.next = next_node;
            next_node.prev = prev_node;
            Node head_next = head.next;
            head.next = node;
            node.prev = head;
            node.next = head_next;
            head_next.prev = node;
            node.val = value;
        }
        else{
            if(hm.size()==capacity){
                Node node_delete = tail.prev;
                Node prev_node = node_delete.prev;
                prev_node.next = tail;
                tail.prev = prev_node;
                hm.remove(node_delete.key);
            }
            Node node = new Node(value,key);
            Node head_next = head.next;
            head.next = node;
            node.prev = head;
            node.next = head_next;
            head_next.prev = node;
            hm.put(key,node);
        }
    }
}
class Node{
    Node prev,next;
    int val;
    int key;
    Node(int val,int key){
        this.val = val;
        this.key = key;
    }
}
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
