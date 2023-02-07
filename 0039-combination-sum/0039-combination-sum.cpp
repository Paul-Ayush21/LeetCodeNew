class Solution {
public:
    
    void findCS(int index,vector<int> &candidates,int target,vector<vector<int>> &res,vector<int> &temp){
        
        if(index==candidates.size()){
            if(target==0){
                res.push_back(temp);
            }
            return;
        }
        
        if(candidates[index]<=target){
            temp.push_back(candidates[index]);
            findCS(index,candidates,target-candidates[index],res,temp);
            temp.pop_back();
        }
        
        findCS(index+1,candidates,target,res,temp);
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int canSize=candidates.size();
        vector<vector<int>> res;
        vector<int> temp;
        findCS(0,candidates,target,res,temp);
        return res;
    }
};