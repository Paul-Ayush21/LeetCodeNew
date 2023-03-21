class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int k=0;
        for(auto it:nums){
            k=k^it;
        }
        return k;
    }
};