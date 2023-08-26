class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> prev(n,1),suff(n,1),ans;
        for(int i=0;i<n;i++){
            if(i==0)prev[i]=1;
            else prev[i]=nums[i-1]*prev[i-1];
            
        }
        for(int i=n-1;i>=0;i--){
            if(i==n-1)suff[i]=1;
            else suff[i]=nums[i+1]*suff[i+1];
        }
        for(int i=0;i<n;i++){
            ans.push_back(prev[i]*suff[i]);
        }
        
    return ans;
    }
};