class Solution {
public:
    int partition(vector<int>& nums,int l,int r){
        int pivot = l + (rand())%(r-l+1);
        swap(nums[pivot],nums[l]);
        pivot = l;
        int i = l+1;
        for(int j=l+1;j<=r;j++){
            if(nums[j]<nums[pivot]){
                swap(nums[j],nums[i]);
                i++;
            }
        }
        swap(nums[pivot],nums[i-1]);
        return pivot = i-1;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, r = n - 1;
        
        while(l<=r){
            int pivot = partition(nums,l,r);
            if(pivot==n-k){
                return nums[pivot];
            }else if(pivot > n-k){
                r = pivot-1;
            }else{
                l = pivot+1;
            }
        }
        return -1;
    }
};