class Solution {
public:
    
    void func(int index, string s, vector<string> &temp, vector<vector<string>> &res){
        if(index==s.size()){
            res.push_back(temp);
            return;
        }
        
        for(int i=index;i<s.size();i++){
            if(isPal(s, index,i)){
                temp.push_back(s.substr(index,i-index+1));
                func(i+1,s,temp,res);
                temp.pop_back();
            }
        }
    }
    bool isPal(string s,int index, int i){
        while(i>=index){
            if(s[index++]!=s[i--]){
                return false;;
            }
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> res;
        
        func(0,s,temp,res);
        return res;
    }
};