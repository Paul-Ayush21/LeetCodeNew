class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int temp1=INT_MAX,temp2=INT_MAX;
        for(auto i:nums){
            if(i<=temp1){
                temp1=i;
            }
            else if(i<=temp2){
                temp2=i;
            }
            else{
                return true;
            }
        }
        
        return false;
    }
};