class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        
        sort(intervals.begin(),intervals.end());
        vector<int> temp=intervals[0];
        if(intervals.size()==0){
            return intervals;
        }
        else{
            for(auto it:intervals){
                if(it[0]<=temp[1]){
                    temp[1]=max(temp[1],it[1]);
                }
                else{
                    res.push_back(temp);
                    temp=it;
                }
            }
        }
        res.push_back(temp);
        return res;
        
    }
};