class Solution {
    public int minCut(String s) {
         int n = s.length();
         int dp[] = new int[n];
         boolean check_palin[][] = new boolean[n][n];
         for(int k=0;k<n;k++){
             for(int i=0;i<n-k;i++){
                 int j = i+k;
                 if(k==0){
                     check_palin[i][j] = true;
                 }
                 else if(k==1){
                     if(s.charAt(i)==s.charAt(j)){
                         check_palin[i][j] = true;
                     }
                 }
                 else{
                     if(s.charAt(i)==s.charAt(j) && check_palin[i+1][j-1]){
                         check_palin[i][j] = true;
                     }
                 }
             }
         }
         dp[0] = 1;
         for(int i=1;i<n;i++)
         {
             int min = Integer.MAX_VALUE;
             if(check_palin[0][i])
                 min = 1;
             for(int j=1;j<=i;j++){
                 if(check_palin[j][i]){
                     min = Math.min(min,1+dp[j-1]);
                 }
             }
             dp[i] = min;
         } 
        return dp[n-1]-1;
    }
}