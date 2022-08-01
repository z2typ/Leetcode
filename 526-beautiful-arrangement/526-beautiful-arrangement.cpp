class Solution {
public:
    int count = 0;
    void perm(int pos,vector<bool> &v){
        int n = v.size()-1;
        if(pos>n){
            count++;
            return;
        }
        
        for(int i = 1; i<=n; i++){
            if(!v[i] && (i%pos==0 || pos%i==0)){
                v[i] = true;
                perm(pos+1,v);
                v[i] = false;
            }
        }
    }
    int countArrangement(int n) {
        vector<bool> v(n+1);
        perm(1,v);
        return count;
    }
};