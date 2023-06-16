class Solution {
public:
    string getPermutation(int n, int k) {
        string s;
        vector<int> nums;
        int fact=1;
        for(int i=1;i<n;i++){
            fact=fact*i;
            nums.push_back(i);
        }
        nums.push_back(n);
        k=k-1;
        while(true){
            s=s+to_string(nums[k/fact]);
            nums.erase(nums.begin()+k/fact);
            if(s.size()==n) break;
            
            k=k%fact;
            fact=fact/nums.size();
            
        }
        return s;
    }
};