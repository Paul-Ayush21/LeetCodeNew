class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if(nums.size()==NULL){
            return 0;
        }
        int cnt=0;
        int maxi=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]==1){
                cnt++;
            }
            else{
                cnt=0;
            }
            maxi=max(maxi,cnt);
        }
        return maxi;
    }
};