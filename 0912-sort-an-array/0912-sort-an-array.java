class Solution {
    public static void merge(int[] arr,int l,int m,int r){
        int i = l;
        int j = m+1;
        int n = (r-l+1);
        int[] arr_cpy = new int[n];
        int p = 0;
        while(i<=m && j<=r){
            if(arr[i]<arr[j]){
                arr_cpy[p] = arr[i];
                i++;
            }else{
                arr_cpy[p] = arr[j];
                j++;
            }
            p++;
        }
        while(i<=m){
            arr_cpy[p] = arr[i];
            p++;
            i++;
        }

        while(j<=r){
            arr_cpy[p] = arr[j];
            j++;
            p++;
        }
        
        p = 0;
        while(p<n){
            arr[p+l] = arr_cpy[p];
            p++;
        }

    }
    public static void sort(int[] arr, int l, int r){
        if(l<r){
            int m = (l+r)/2;
            sort(arr,l,m);
            sort(arr,m+1,r);
            merge(arr,l,m,r);
        }
    }
    public int[] sortArray(int[] nums) {
        sort(nums,0, nums.length-1);
        return nums;
    }
}