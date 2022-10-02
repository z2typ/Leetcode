class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        if(strs.empty()){
            return res;
        }
        
        int flag = 0;
        
        for(int j=0; j<strs[0].size(); j++){
            
            for(int i=0;i<strs.size();i++){
                if(strs[0][j]!=strs[i][j]){
                    flag = 1;
                }
            }
            
            if(flag){
                break;
            }else{
                res += strs[0][j];
            }
        }
        return res;
    }
};