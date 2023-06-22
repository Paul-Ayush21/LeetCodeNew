class Solution {
public:
    string smallestString(string s) {
        int ind=0,count=0;
        for(ind;ind<s.size();ind++){
            if(s[ind]!='a'){
                count=1;
                break;
            }
        }
        if(count==0){
            s[s.size()-1]='z';
            return s;
        }
        for(ind;ind<s.size();ind++){
            if(s[ind]=='a'){
                break;
            }
            else{
                s[ind]-=1;
            }
        }
        return s;
    }
};