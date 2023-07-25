class Solution {
public:
    void f(int open, int close,int n,string s, vector<string>& res){
        
        if(s.size()==n*2){
            res.push_back(s);
            return;
        }
        
        if(open<n) f(open+1,close, n,s+'(',res);
        if(close<open) f(open,close+1,n,s+')',res);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        f(0,0,n,"",res);
        return res;
    }
};