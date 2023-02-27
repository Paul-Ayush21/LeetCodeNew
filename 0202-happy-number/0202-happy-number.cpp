class Solution {
public:
    
   
    bool isHappy(int n) {
        map<int,int> smap;
        while(n!=1){
        int sum=0, current=n;
        
        while(current){
        int temp=current%10;
        sum+=temp*temp;
        current/=10;
        }
        
        if(smap.find(sum)!=smap.end()){
            return false;
        }
            
        smap[sum] ++;
        n=sum;
        
        }
        return true;
    }
};