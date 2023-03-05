class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(),-1);
        stack<int> sk;
        int n=nums.size();
        for(int i=2*n-1;i>=0;i--){
            while(!sk.empty() && nums[i%n]>=sk.top()){
                // cout<<sk.top()<<endl;
                sk.pop();
            }
            if(i<n){
                if(!sk.empty()){
                    res[i]=sk.top();
                }
            }
            sk.push(nums[i%n]);
    
        }
        // cout<<"MOd"<<3%3;
        return res;
        }
    
};