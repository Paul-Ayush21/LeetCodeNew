class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int elem=0;
        for(auto it:nums){
            if(count==0){
                elem=it;
            }
            if(it==elem){
                count++;
            }
            else{
                count--;
            }
        }
        return elem;
    }
};