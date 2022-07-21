class Solution {
public:
    bool valid(vector<int>& arr, int i){
        int n = arr.size();
        if((i-1<0 || arr[i-1]==0) && (i+1>=n || arr[i+1]==0) && arr[i]==0){
            arr[i] = 1;
            return true;
        }
        return false;
    }
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count =0;
        for(int i=0;i<flowerbed.size();i++){
            if(valid(flowerbed,i)) count++;
        }
        
        if(count>=n) return true;
        return false;
    }
};