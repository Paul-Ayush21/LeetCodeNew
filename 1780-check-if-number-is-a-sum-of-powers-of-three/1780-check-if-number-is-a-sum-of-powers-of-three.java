class Solution {
    public boolean recur(int n , int x){
        if(n==0)return true;
        if(x>n)return false;
        return recur(n,x*3)||recur(n-x,x*3);
    }
    public boolean checkPowersOfThree(int n) {
        return recur(n,1);
    }
}