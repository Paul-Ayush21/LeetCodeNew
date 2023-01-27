class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set <int> hashSet;
        
        for(auto it:nums){
            hashSet.insert(it);
        }
        int maxMaxLen=0;
        
        for(auto it: nums){
            // int startingElm=0,maxLen=0;
            if(!hashSet.count(it-1)){
                
                int startingElm=it;
                int maxLen=1;
                while(hashSet.count(startingElm+1)){
                    startingElm++;
                    maxLen++;
                }
                
                maxMaxLen=max(maxMaxLen,maxLen);
            }
        }
        return maxMaxLen;
    }
};