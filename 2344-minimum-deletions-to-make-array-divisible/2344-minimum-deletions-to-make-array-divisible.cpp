class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        map<int,int> smap;
        
        for(int i =0;i<nums.size();i++){
            if(smap.find(nums[i])!=smap.end()){
                smap[nums[i]]++;
            }
            else{
                smap[nums[i]]=1;
            }
        }
        int count=0;
        
        for(auto i = smap.begin();i!=smap.end();i++){
            int cnt=0;
            for(auto it: numsDivide){
                if(it%i->first!=0){
                    count+=i->second;
                    break;
                }
                else{
                    cnt++;
                }
            }
            if(cnt==numsDivide.size()){
                break;
            }
        }
        if(count==nums.size()){return -1;}
        return count;
    }
};