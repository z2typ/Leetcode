class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        int n = s.length();
        int arr[n];
        int flag = 0;
        int l = 1;
        for(int i=0;i<n;i++){
            
            arr[i] = l;
            
            if(flag==0){
                l++;
                if(l==numRows) flag=1;
            }else{
                l--;
                if(l==1) flag=0;
            }
            
        }
        
        string ans = "";
        
        for(int i=1;i<=numRows;i++){
            for(int j=0;j<n;j++){
                if(arr[j]==i){
                    ans.push_back(s[j]);
                }
            }
        }
        
        return ans;
    }
};