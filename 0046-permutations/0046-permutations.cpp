class Solution {
public:
    void finS(int ind,vector<int>& nums, vector<vector<int>> & res){
        if(ind==nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            swap(nums[i],nums[ind]);
            finS(ind+1,nums,res);
            swap(nums[i],nums[ind]);
        }
    }
//     void finS(int ind,vector<int>& nums,vector<int>& map, vector<int>& temp, vector<vector<int>> & res){
//         if(temp.size()==nums.size()){
//             res.push_back(temp);
//             return;
//         }
//         for(int i=ind;i<nums.size();i++){
            
//             if(map[i]==0){
//                 temp.push_back(nums[i]);
//                 map[i]=1;
//                 finS(ind,nums,map,temp,res);
//                 temp.pop_back();
//                 map[i]=0;
//             }
            
//         }
//     }
    vector<vector<int>> permute(vector<int>& nums) {
        // vector<int> temp;
        vector<vector<int>> res;
        // vector<int> map(nums.size(),0);
        // finS(0,nums,map,temp,res);
        finS(0,nums,res);
        return res;
    }
};