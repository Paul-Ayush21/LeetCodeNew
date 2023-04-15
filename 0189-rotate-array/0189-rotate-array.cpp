class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int g=k%nums.size();
        vector<int> res;
        for(int i=nums.size()-g;i<nums.size();i++){
            res.push_back(nums[i]);
        }
        for(int i=0;i<nums.size()-g;i++){
            res.push_back(nums[i]);
        }
        nums.clear();
        copy(res.begin(),res.end(),back_inserter(nums));
    }
};