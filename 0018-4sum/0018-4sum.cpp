class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n-3;i++){
                for(int j=i+1;j<n-2;j++){                   
                        int left=j+1;
                        int right=n-1;
                        while(left<right){
                            long long sum=(long long)nums[i]+(long long)nums[j]+(long long)nums[left]+(long long)nums[right];
                            if(sum==target){
                                vector<int> temp;
                                temp.push_back(nums[i]);
                                temp.push_back(nums[j]);
                                temp.push_back(nums[left]);
                                temp.push_back(nums[right]);
                                
                                ans.push_back(temp);
                                
                                while(left<right && nums[left]==nums[left+1]) left++;
                                while(left<right && nums[right]==nums[right-1]) right--;
                                
                                left++;
                                right--;
                            }
                            else if(sum>target){
                                right--;
                            }
                            else{
                                left++;
                            }
                        }
                    while(j+1<n && nums[j]==nums[j+1]) j++;
                    }
                
            while(i+1<n && nums[i]==nums[i+1]) i++;
            
        }
        return ans;
    }
};