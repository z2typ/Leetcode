class mypair{
public:
    int freq;
    string word;
    mypair(int freq,string word){
        this->freq = freq;
        this->word = word;
    }
    bool operator <(const mypair & p)const{
        if(this->freq==p.freq){
            return this->word>p.word;
        }else{
            return this->freq<p.freq;
        }
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string,int> umap;
        for(auto word : words){
            umap[word]++;
        }
        
        priority_queue<mypair> pq;
        
        for(auto it=umap.begin();it!=umap.end();it++){
            pq.push(mypair(it->second,it->first));
        }
        
        vector<string> ans;
        
        while(k-- && !pq.empty()){
            string word = pq.top().word;
            pq.pop();
            ans.push_back(word);
        }
        return ans;
    }
};