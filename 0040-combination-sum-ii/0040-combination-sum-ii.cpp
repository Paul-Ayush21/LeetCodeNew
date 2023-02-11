class Solution {
    void finds(int index,int target,vector<int>& temp,vector<int> &candidates,vector<vector<int>> &res){
        if(target==0){
            res.push_back(temp);
            return;   
        }
        for(int i=index;i<candidates.size();i++){
            if(i>index && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            temp.push_back(candidates[i]);
            finds(i+1,target-candidates[i],temp,candidates,res);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> res;
        sort(candidates.begin(),candidates.end());
        finds(0,target,temp,candidates,res);
        return res;
    }
};