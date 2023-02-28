class Solution {
public:
    int reverse(int x) {
        int temp=abs(x),res=0,ax=1;
        while(temp!=0){
            int t=temp%10;
            if((double)INT_MAX/res<=10) return 0;
            res=res*10+t;
            cout<<res<<" ";
            temp=temp/10;
            // ax=ax*10;
        }
        
        if(x<0) return -res;
        return res;
    }
};