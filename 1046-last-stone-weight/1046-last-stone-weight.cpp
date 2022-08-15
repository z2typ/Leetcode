class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> ston(stones.begin(),stones.end());
        
        while(ston.size()>1){
            int a = ston.top();
            ston.pop();
            int b = ston.top();
            ston.pop();
            if(a!=b){
                ston.push(abs(a-b));
            }
        }
        return ston.empty()? 0 : ston.top();
    }
};