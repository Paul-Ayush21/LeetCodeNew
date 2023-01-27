class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> smap(256,-1);
        int len=0,left=0,right=0,n=s.size();
        while(right<n){
            if(smap[s[right]]!=-1)
                left = max(smap[s[right]]+1,left);
            
            smap[s[right]]=right;
            len=max(len,right-left+1);
            right++;
        }
        return len;

//       vector < int > mpp(256, -1);

//       int left = 0, right = 0;
//       int n = s.size();
//       int len = 0;
//       while (right < n) {
//         if (mpp[s[right]] != -1)
//           left = max(mpp[s[right]] + 1, left);

//         mpp[s[right]] = right;

//         len = max(len, right - left + 1);
//         right++;
//       }
//       return len;
    }
};