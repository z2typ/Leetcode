class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26);
        
        for(char c : tasks){
            count[c-'A']++;
        }
        
        sort(count.begin(),count.end(),greater<int>());
        
        int max_ct = count[0];
        int empty_slots = (max_ct-1)*n;
        
        for(int i=1;i<26;i++){
            empty_slots -= min(max_ct-1,count[i]);
            empty_slots = max(0,empty_slots);
        }
        
        return empty_slots + tasks.size(); 
    }
};