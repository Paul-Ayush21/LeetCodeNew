class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> smap;
        // vector<int> f(265,-1);
        int n=nums.size()/2;
        for(int i=0;i<nums.size();i++){
            smap[nums[i]] ++;
            if(smap[nums[i]]>n){
                return nums[i];
            }
        }
        return 0;
    }
};