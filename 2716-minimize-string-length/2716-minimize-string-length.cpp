class Solution {
public:
    int minimizedStringLength(string s) {
        set<char> smap(s.begin(),s.end());
        return smap.size();
    }
};