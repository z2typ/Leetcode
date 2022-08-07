class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string LCP = "";
        int n = strs.size();
        for(int i=0; true; i++){
            char ch;
                
            if(i<strs[0].size()){
                ch = strs[0][i];
            }else{
                break;
            }
            
            int flag = 1;
            for(int j=0;j<n;j++){
                if(i>=strs[j].size() || strs[j][i]!=ch){
                    flag = 0;
                    break;
                }
            }
            
            if(flag==1){
                LCP += ch;
            }else{
                break;
            }
        }
        return LCP;
    }
};