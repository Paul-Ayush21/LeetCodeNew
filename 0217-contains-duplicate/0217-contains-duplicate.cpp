class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> sset;
        for(auto it:nums){
                sset.insert(it);
        }
        return !(nums.size()==sset.size());
    }
};