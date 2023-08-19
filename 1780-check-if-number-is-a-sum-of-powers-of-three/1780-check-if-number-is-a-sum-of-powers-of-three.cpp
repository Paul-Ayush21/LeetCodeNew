class Solution {
public:
    bool f(int n,int power){
        if(n==0) return true;
        if(power>n) return false;
        return f(n,power*3) || f(n-power,power*3);
    }
    bool checkPowersOfThree(int n) {
        return f(n,1);
    }
};