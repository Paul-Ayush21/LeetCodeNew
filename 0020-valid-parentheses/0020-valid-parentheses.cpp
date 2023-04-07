class Solution {
public:
    bool isValid(string s1) {
        stack<char> s;
        for(auto it:s1){
            if(it=='('||it=='['||it=='{'){
                s.push(it);
            }
            else{
                if(s.size()==0){return false;}
                char ch=s.top();
                s.pop();
                if(it==')'&&ch=='(' || it=='}' && ch=='{' || it==']' && ch=='['){
                    continue;
                }
                else{return false;}
            }
            
        }
        return s.empty();
    }
};