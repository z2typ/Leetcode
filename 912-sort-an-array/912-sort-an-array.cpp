class Solution {
public:
    // void merge_sort(vector<int>& nums,int i,int j);
    // void merge(vector<int>& nums, int i,int mid,int j);
    
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        merge_sort(nums,0,n-1);
        return nums;
    }
    
    void merge_sort(vector<int>& nums, int i,int j){
        if(i==j) return;
        
        int mid = (i+j)/2;
        
        merge_sort(nums, i, mid);
        merge_sort(nums, mid+1,j);
        
        merge(nums,i,mid,j);
    }
    
    void merge(vector<int>&nums,int i,int mid,int j){
        int n = j-i+1;
        vector<int> arr(n);
        
        int p1 = i;
        int p2 = mid+1;
        int pArr = 0;
        
        while(p1<=mid && p2<=j){
            if(nums[p1]<nums[p2]){
                arr[pArr] = nums[p1];
                pArr++;
                p1++;
            }else{
                arr[pArr] = nums[p2];
                pArr++;
                p2++;
            }
        }
        
        while(p1<=mid){
                arr[pArr] = nums[p1];
                pArr++;
                p1++;
        }
        while(p2<=j){
                arr[pArr] = nums[p2];
                pArr++;
                p2++;
        }
        
        for(int k=i;k<=j;k++){
            nums[k] = arr[k-i];
        }
        
    }
    
};