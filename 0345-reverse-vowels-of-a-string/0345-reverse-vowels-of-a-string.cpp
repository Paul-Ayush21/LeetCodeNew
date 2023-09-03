class Solution {
public:
    string reverseVowels(string s) {
        vector<char> vec;
        vector<int> ind;
        set<char> se={'a','e','i','o','u'};
        for(int i=0;i<s.size();i++){
            if(se.count(tolower(s[i]))){
                vec.push_back(s[i]);
                ind.push_back(i);
            }
        }
        reverse(vec.begin(),vec.end());
        for(int i=0;i<ind.size();i++){
            s[ind[i]]=vec[i];
        }
        return s;
    }
};