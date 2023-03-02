class Solution {
public:
    bool isValid(string s) {
        stack<char> q;
        for(auto it:s){
            if(it=='(' || it=='{' || it=='['){
                q.push(it);
            }
            else{
                if(q.size()==0) return false;
                char ch=q.top();
                q.pop();
                if((ch=='(' and it==')') or (ch=='{' and it=='}') or (ch=='[' and it==']')){
                    continue;
                }
                else{ return false; }
            }
        }
        return q.empty();
    }
};