struct Interval{
    int length;
    int left;
    int right;
    
    Interval(int left,int right){
        this->left = left;
        this->right = right;
        this->length = (right-left+1);
    }
    
    Interval(vector<int> &v){
        this->left = v[0];
        this->right = v[1];
        this->length = (right-left+1);
    }
    
    
    bool operator >(const Interval &a) const{
        if(this->length!=a.length){
            return this->length > a.length;
        }
        return this->right > a.right;
    }
    
};


class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        struct mygreater{
            bool operator ()(Interval &a, Interval &b){
                if(a.length!=b.length){
                    return a.length > b.length;
                }
                return a.right > b.right;
            }
        };
        priority_queue<Interval, vector<Interval>, mygreater > pq;
        unordered_map<int, vector<int>> index;
        for(int i=0;i<queries.size();i++){
            index[queries[i]].push_back(i);
        }
        sort(intervals.begin(),intervals.end());
        sort(queries.begin(),queries.end());
        vector<int> res(queries.size(),-1);
        int query = queries[0];
        
        int i = 0;
        for(int query : queries){
            while(i < intervals.size() && intervals[i][0] <= query){
                pq.push(Interval(intervals[i]));
                i++;
            }
            
            while(!pq.empty() && pq.top().right < query){
                pq.pop();
            }
            
            if(!pq.empty()){
                for(int idx : index[query])
                    res[idx] = pq.top().length;
            }
            
        }
        
        return res;
        
        
    }
};