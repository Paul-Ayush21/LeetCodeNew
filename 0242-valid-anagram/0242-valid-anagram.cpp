class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> fmap1(26,0);
        vector<int> fmap2(26,0);
        for(int i=0;i<s.size();i++){
            fmap1[s[i]-'a']++;
        }
        for(int i=0;i<t.size();i++){
            fmap2[t[i]-'a']++;
        }
        return(fmap1==fmap2);
        
    }
};