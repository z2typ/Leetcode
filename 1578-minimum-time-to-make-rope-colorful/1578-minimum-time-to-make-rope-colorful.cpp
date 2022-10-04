class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.length();
        int i = 0;
        char prevColor = colors[0];
        int minTime = 0;
        for(int j=1;j<n;j++){
            if(colors[j]==prevColor){
                if(neededTime[j]<neededTime[i]){
                    minTime += neededTime[j];
                }else{
                    minTime += neededTime[i];
                    i = j;
                }
            }else{
                prevColor = colors[j];
                i = j;
            }
        }
        return minTime;
    }
};