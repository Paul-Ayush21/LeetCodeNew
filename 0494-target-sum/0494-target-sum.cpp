class Solution {
public:
    int f(int ind,vector<int>& nums,int target){
        if(ind==nums.size()){
            // cout<<target<<endl;
            if(target==0){
                // cout<<"here"<<endl;
                return 1;
            }
            // cout<<"HERE"<<endl;
            return 0;
        }
        
        int plus=+nums[ind]+f(ind+1,nums,target+nums[ind]);
        int minus=-nums[ind]+f(ind+1,nums,target-nums[ind]);
        return plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return f(0,nums,target);
    }
};