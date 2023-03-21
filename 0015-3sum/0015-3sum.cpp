class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<(int)(nums.size())-2;i++){
            if(i==0 || (i>0 && nums[i]!=nums[i-1])){
                int left=i+1,high=(int)(nums.size())-1;
                int sum=0-(nums[i]);
                while(left<high){
                 if(nums[left]+nums[high]==sum){
                    vector<int> temp;
                    temp.push_back(nums[left]);
                    temp.push_back(nums[high]);
                    temp.push_back(nums[i]);
                    res.push_back(temp);
                     
                     while(left<high && nums[left]==nums[left+1]) left++;
                     while(left<high && nums[high]==nums[high-1]) high--;
                     left++;
                     high--;
                 }
                 else if(nums[left]+nums[high]>sum) high--;
                 else left++;
                }
            }
        }
        return res;
    }
};