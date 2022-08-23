class Solution
{
    public:
        bool isNStraightHand(vector<int> &hand, int groupSize)
        {
            int n = hand.size();
            
            if(n%groupSize == 0){
                int noGroups = (n / groupSize);
            }else{
                return false;
            }
            unordered_map<int,int> umap;
            
            for(int x : hand){
                umap[x]++;
            }
            vector<int> unique_hand;
            
            for(auto it : umap){
                unique_hand.push_back(it.first);
            }

            priority_queue<int,vector<int>, greater<int>> pq(unique_hand.begin(),unique_hand.end());
            
            while(not pq.empty()){
                int min_val = pq.top();
                for(int i=min_val;i<min_val+groupSize;i++){
                    if(umap.count(i)){
                        umap[i]--;
                        if(umap[i]<0) return false;
                        if(umap[i]==0){
                            if(pq.top() == i){
                                pq.pop();
                            }else{
                                return false;
                            }
                        }
                    }else{
                        return false;
                    }
                }
            }
            
            return true;
        }
};