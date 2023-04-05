class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> v;
        stringstream ss(s);
        string word;
        while(ss>>word){
            v.push_back(word);
        }
        if(pattern.size()!=v.size()) return false;
        unordered_map<char,string> smap;
        unordered_map<string,char> map;
        for(int i=0;i<v.size();i++){
            if(smap.find(pattern[i])!=smap.end() && smap[pattern[i]]!=v[i]){
                return false;
            }
            else if(map.find(v[i])!=map.end() && map[v[i]]!=pattern[i]){
                return false;
            }
            smap[pattern[i]]=v[i];
            map[v[i]]=pattern[i];
        }
        return true;
    }
};