class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> fmap(256,0);
        int left=0,right=0,n=s.size(),start=0,len=INT_MAX,count=0;
        for(auto it: t){
            fmap[it]++;
        }
        while(right<n){
            // cout<<s[right]<<" "<<fmap[s[right]]<<endl;
            if(fmap[s[right]]>0){
                count++;
            }
            fmap[s[right]]--;
            // cout<<count<<endl;
                while(count==t.size()){
                    if(len>right-left+1){
                        len=right-left+1;
                        start=left;
                    }
                    
                    fmap[s[left]]++;
                    if(fmap[s[left]]>0){
                        count--;
                    }
                    left++;
                }
            right++;
        }
        if(len==INT_MAX) return "";
        return s.substr(start,len);
    }
};