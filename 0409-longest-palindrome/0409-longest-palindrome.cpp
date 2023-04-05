class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> smap;
        int oddCount=0;
        for(auto it:s){
            if(smap.find(it)!=smap.end()){
                smap[it]++;
            }
            else{
                smap[it]=1;
            }
            if(smap[it]%2!=0){
                oddCount++;
            }
            else{
                oddCount--;
            }
        }
        if(oddCount>1){
            return s.size()-oddCount+1;
        }
        else{
            return s.size();
        }
    }
};