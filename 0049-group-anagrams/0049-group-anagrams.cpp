class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> smap;
        for(auto it: strs){
            string k=it;
            sort(k.begin(),k.end());
            smap[k].push_back(it);
        }
        vector<vector<string>> res;
        for(auto it:smap){
            res.push_back(it.second);
        }
        return res;
    }
};