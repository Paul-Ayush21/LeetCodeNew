class Solution {
public:
    int romanToInt(string s) {
        // char arr[s.length()+1];
        // strcpy(arr,s.c_str());
        unordered_map<char,int> smap;
        smap['I']=1;
        smap['V']=5;
        smap['X']=10;
        smap['L']=50;
        smap['C']=100;
        smap['D']=500;
        smap['M']=1000;
        int maxi=0,ans=0;
        
        
        for(int i=0;i<s.length();i++){
            if(smap[s[i]]<smap[s[i+1]]){
                ans-=smap[s[i]];
            }
            else{
                ans+=smap[s[i]];
            }
        }
        return ans;
//          for (int i= 0 ; i<s.length() ; i++){
//              if(smap[s[i]]<smap[s[i+1]]){
//                  maxi=max(maxi,i+1);
//              }
//              else if(smap[s[i]]>smap[s[i+1]]){
//                  maxi=max(maxi,i);
//              }
//          }
//         cout<<maxi;
//         for(int i=maxi,j=maxi;i<s.length()-1,j>=0;i++,j--){
//             ans+=smap[s[i]];
//             ans-=smap[s[j]];
//         }
        
//         return ans;
        
    }
};