#define M 1000'000'007
class Solution {
public:
    int mul(long long a, long long b){
        return ((a%M)*(b%M))%M;
    }
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        long long maxHorizontal= 0;
        long long maxVertical = 0;
        long long prevCut = 0;
        for(int x : horizontalCuts){
            maxHorizontal = max(maxHorizontal, x - prevCut);
            prevCut = x;
        }
        prevCut = 0;
        for(int x : verticalCuts){
            maxVertical = max(maxVertical, x - prevCut);
            prevCut = x;
        }
        int ans = mul(maxHorizontal,maxVertical);
        return ans;
    }
};