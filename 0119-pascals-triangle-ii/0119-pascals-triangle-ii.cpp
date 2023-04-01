class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        long long temp=1;
        res.push_back(temp);
        for(int i=1;i<=rowIndex;i++){
            temp=temp*(rowIndex-i+1)/i;
            res.push_back(temp);
        }
        return res;
    }
};