class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> smap;
        vector<int> res;
        int temp=nums.size()/3;
        for(auto it:nums){
            smap[it]++;
            if(smap[it]>temp){
                res.push_back(it);
                smap[it]=INT_MIN;
            }
        }
        return res;
    }
};