class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int num1;
        int count1 = 0;
        int num2;
        int count2 = 0;
        for(int x : nums){
            if(num1==x){
                count1++;
            }else if(num2==x){
                count2++;
            }else if(count1==0){
                num1 = x;
                count1 = 1;
            }else if(count2==0){
                num2 = x;
                count2 = 1;
            }else{
                count1--;
                count2--;
            }
        }
        int c1 = 0, c2 = 0;
        for(int x : nums){
            if(x==num1){
                c1++;
            }else if(x==num2){
                c2++;
            }
        }
        vector<int> res;
        if(c1>n/3){
            res.push_back(num1);
        }
        if(c2>n/3){
            res.push_back(num2);
        }
        
        return res;
    }
};