class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> smap;
        for(int i=0;i<nums2.size();i++){
            int j=i+1;
            for(j;j<nums2.size();j++){
                if(nums2[i]<nums2[j]){
                    smap[nums2[i]]=nums2[j];
                    break;
                }
            }
            if(j==nums2.size()) smap[nums2[i]]=-1;
        }
        vector<int> res;
        for(int i=0;i<nums1.size();i++){
            res.push_back(smap[nums1[i]]);
        }
        return res;
    }
};