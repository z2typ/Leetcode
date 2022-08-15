struct LRUNode{
    int key;
    int val;
    LRUNode* prev = NULL;
    LRUNode* next = NULL;
    LRUNode(int key,int val){
        this->key = key;
        this->val = val;
    }
};

class LRUCache {
public:
    
    
    unordered_map<int,LRUNode*> umap;
    int capacity;
    LRUNode* left = NULL;
    LRUNode* right = NULL;

    LRUCache(int capacity) {
        this->capacity = capacity;
        left = new LRUNode(0,-1);
        right = new LRUNode(0,-1);
        left->next = right;
        right->prev = left;
    }
    
    
    int get(int key) {        

        if(umap.find(key)!=umap.end()){
            LRUNode* l = umap[key]->prev;
            LRUNode* r = umap[key]->next;
            
            l->next = r;
            r->prev = l;
            
            l = right->prev;
            r = right;
            
            umap[key]->next = NULL;
            umap[key]->prev = NULL;
                
            l->next = umap[key];
            umap[key]->next = r;
            
            r->prev = umap[key];
            umap[key]->prev = l;
            return umap[key]->val;
        }
        
        
        return -1;
    }
    
    void put(int key, int value) {
        if(!umap.count(key) && umap.size()<capacity){
            umap[key] = new LRUNode(key,value);

        }else{
            LRUNode* l = NULL;
            LRUNode* r = NULL;

            if(umap.count(key)){

                l = umap[key]->prev;
                r = umap[key]->next;
                umap[key]->val = value;
                umap[key]->prev = NULL;
                umap[key]->next = NULL;
                l->next = r;
                r->prev = l;
            }else{
                l = left;
                r = left->next->next;
                LRUNode* ntd = l->next;
                umap.erase(ntd->key);

                l->next = r;
                r->prev = l;

                delete ntd;
                
                umap[key] = new LRUNode(key,value);

            }

        }
        

        LRUNode* l = right->prev;
        LRUNode* r = right;

        l->next = umap[key];
        umap[key]->next = r;

        r->prev = umap[key];
        umap[key]->prev = l;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */