struct TrieNode{
    char val;
    bool endWord = false;
    vector<TrieNode*> links;
    TrieNode(char ch){
        val = ch;
        links = vector<TrieNode*>(26,NULL);
    }
};
class Trie {
public:
    TrieNode* head = new TrieNode('.');
    
    Trie() {
        
    }
    
    void insert(string word) {
        int n= word.size();
        TrieNode* temp = head;
        for(int i=0;i<n;i++){
            if(temp->links[word[i]-'a']==NULL){
                temp->links[word[i]-'a'] = new TrieNode(word[i]-'a');
            }
            temp = temp->links[word[i]-'a'];
        }
        temp->endWord = true;
    }
    
    bool search(string word) {
        int n = word.size();
        TrieNode* temp = head;
        int k = 0;
        for(int i=0; i<n; i++){
            if(temp->links[word[i]-'a']){
                k++;
                temp = temp->links[word[i]-'a'];
            }else{
                break;
            }
        }
        if(k<n){
            return false;
        }
        if(temp->endWord){
            return true;
        }
        
        return false;
        
    }
    
    bool startsWith(string prefix) {
        int n = prefix.size();
        TrieNode* temp = head;
        int k = 0;
        for(int i=0; i<n; i++){
            if(temp->links[prefix[i]-'a']){
                k++;
                temp = temp->links[prefix[i]-'a'];
            }else{
                break;
            }
        }
        if(k<n){
            return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */