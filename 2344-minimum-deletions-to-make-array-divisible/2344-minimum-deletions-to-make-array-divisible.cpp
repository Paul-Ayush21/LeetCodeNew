class Solution {
public:
    //     int minOperations(vector<int>& A, vector<int>& numsDivide) {
    //     int g = numsDivide[0];
    //     for (int a: numsDivide)
    //         g = gcd(g, a);
    //     cout<<g;
    //     sort(A.begin(), A.end());
    //     for (int i = 0; i < A.size() && A[i] <= g; ++i)
    //         if (g % A[i] == 0)
    //             return i;
    //     return -1;
    // }
    int gcdd(int a,int b){
        int r;
        while((a%b)>0){
            r=a%b;
            a=b;
            b=r;
        }
        return b;
    }
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        sort(numsDivide.begin(),numsDivide.end());
        int g=numsDivide[0];
        for(auto it:numsDivide){
            g=gcdd(g,it);
        }
        cout<<g;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size() && nums[i]<=g;i++){
            if(g%nums[i]==0){
                return i;
            }
        }
        return -1;
    }
};
//         map<int,int> smap;
        
//         for(int i =0;i<nums.size();i++){
//             if(smap.find(nums[i])!=smap.end()){
//                 smap[nums[i]]++;
//             }
//             else{
//                 smap[nums[i]]=1;
//             }
//         }
//         int count=0;
        
//         for(auto i = smap.begin();i!=smap.end();i++){
//             int cnt=0;
//             for(auto it: numsDivide){
//                 if(it%i->first!=0){
//                     count+=i->second;
//                     break;
//                 }
//                 else{
//                     cnt++;
//                 }
//             }
//             if(cnt==numsDivide.size()){
//                 break;
//             }
//         }
//         if(count==nums.size()){return -1;}
//         return count;
//     }
// };