class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count=0;
        for(int i=low;i<=high;i++){
            string s=to_string(i);
            int size=s.size();
            if(size%2!=0) continue;
            int end=size/2;
            int s1=0,s2=0;
            for(int j=0;j<end;j++){
                s1+=int(s[j]);
            }
            for(int j=end;j<size;j++){
                s2+=int(s[j]);
            }
            if(s1==s2) count++;
        }
        return count;
    }
};