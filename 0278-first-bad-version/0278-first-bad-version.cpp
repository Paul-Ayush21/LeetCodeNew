// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        // if(n==1){return 1;}
        
        int left=0, right=n,k;
        while(right-left>1){
            int mid=left+(right-left)/2;
            cout<<"mid: "<<mid<<endl;
    
                
            if(isBadVersion(mid)==false){
                cout<<"left"<<endl;
                left=mid;
            }
            else{
                cout<<"right"<<endl;
                right=mid;
            }
        }
        cout<<left;
        return right;
    }
};