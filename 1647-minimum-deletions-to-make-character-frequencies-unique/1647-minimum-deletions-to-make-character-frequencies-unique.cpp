class Solution {
public:
    int minDeletions(string s) {
        vector<int> fmap(256,-1);
        for(auto it:s){
            fmap[it]++;
        }
        
        set<int> sset;
        int count=0;
        for(auto it:fmap){
            if(it!=-1){
                it++;
                // cout<<it<<endl;
                if(sset.count(it)){
                    int temp=it;
                    // cout<<"temp: "<<temp<<endl;
                    // cout<<sset.count(temp)<<endl;
                    temp--;
                    count++;
                    while(sset.count(temp)!=0 && temp>=0){
                        
                        temp--;
                        count++;
                        // cout<<"temp2: "<<temp<<endl;
                        // cout<<"count: "<<count<<endl;
                    }
                    if(temp!=0){
                    sset.insert(temp);
                    }
                }
                else{
                    sset.insert(it);
                }
            }
        }
        return count;
    }
};