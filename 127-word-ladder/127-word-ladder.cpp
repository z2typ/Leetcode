class Solution {
public:
    bool comp(string &a, string &b){
        int diff = 0;
        for(int i=0; i<a.size(); i++){
            if(a[i]!=b[i]){
                diff += 1;
            }
        }
        return diff==1;
    }
        
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        int m = beginWord.size();
        
        
        unordered_map<string,int> distance;
        for(string s : wordList){
            distance[s] = 0;
        }
        
        queue<string> q;
        q.push(beginWord);
        distance[beginWord] = 0;
        
        while(!q.empty()){
            string node = q.front();
            q.pop();
            if(node==endWord){
                return distance[endWord]+1;
            }
            
            for(int i=0;i<m;i++){
                string adj_node = node;
                for(int j=0;j<26;j++){
                    adj_node[i] = 'a'+j;
                    if(adj_node!=node && distance.count(adj_node) && distance[adj_node]==0){
                        distance[adj_node] = distance[node] + 1;
                        q.push(adj_node);
                    }
                }
            }
        }
        
        
        return 0;
    }
};