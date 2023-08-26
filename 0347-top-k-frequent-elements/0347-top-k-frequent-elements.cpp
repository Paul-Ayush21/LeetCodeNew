class Solution {
public:
    multimap<int,int> invert(unordered_map<int,int>&smap ){
        multimap<int,int> mmap;
        for(auto it:smap){
            mmap.insert(make_pair(it.second,it.first));
        }
        return mmap;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> smap;
        vector<int> ans;
        for(auto it:nums){
            smap[it]++;
        }
        multimap<int,int> mmap=invert(smap);
        // sort(smap.begin(),smap.end(),sortByVal());
        // for(auto it:smap){
        //     cout<<it.first<<" : "<<it.second<<endl;
        // }
        // cout<<endl;
        // for(auto it:mmap){
        //     cout<<it.first<<" : "<<it.second<<endl;
        // }
        int cnt=0;
        for(auto it=mmap.rbegin();it!=mmap.rend();it++){
            if(cnt==k) break;
            ans.push_back(it->second);
            cnt++;
        }
        return ans;
    }
};