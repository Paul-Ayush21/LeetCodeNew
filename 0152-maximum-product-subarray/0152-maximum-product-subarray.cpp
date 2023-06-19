class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pdt=1;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            pdt=pdt*nums[i];
            maxi=max(pdt,maxi);
            if(pdt==0){
                pdt=1;
            }
        }
        pdt=1;
        for(int i=nums.size()-1;i>=0;i--){
            pdt=pdt*nums[i];
            maxi=max(pdt,maxi);
            if(pdt==0){
                pdt=1;
            }
        }
        return maxi;
    }
};