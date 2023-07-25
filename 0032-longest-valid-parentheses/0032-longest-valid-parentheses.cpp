class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> sk;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') sk.push(i);
            else if(!sk.empty()){
                s[sk.top()]=s[i]='*';
                sk.pop();
            }
        }
        int cnt=0, res=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='*') cnt++;
            else{
                res=max(cnt,res);
                cnt=0;
            }
        }
        return max(res,cnt);
    }
};