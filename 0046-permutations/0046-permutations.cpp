class Solution {
public:
    void finS(int ind,vector<int>& nums,vector<int>& map, vector<int>& temp, vector<vector<int>> & res){
        if(temp.size()==nums.size()){
            res.push_back(temp);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            
            if(map[i]==0){
                temp.push_back(nums[i]);
                map[i]=1;
                finS(ind,nums,map,temp,res);
                temp.pop_back();
                map[i]=0;
            }
            
            
//             temp.push_back(nums[i]);
//             finS(i+1,nums,temp,res);
//             temp.pop_back();
//             finS(i+1,nums,temp,res);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> res;
        vector<int> map(nums.size(),0);
        finS(0,nums,map,temp,res);
        return res;
    }
};