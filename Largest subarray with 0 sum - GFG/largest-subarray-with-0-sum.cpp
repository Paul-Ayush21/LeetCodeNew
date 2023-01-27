//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        unordered_map<int,int> smap;
        
        int maxi=0,sum=0;
        for(int i=0;i<n;i++){
            sum+=A[i];
            if(sum==0){
                maxi=i+1;
            }
            else{
                if(smap.find(sum)!=smap.end()){
                    maxi=max(maxi,i-smap[sum]);
                }
                else{
                    smap[sum]=i;
                    // smap.insert(sum,i);
                }
            }
        }
        return maxi;
        
        
        
        // int startingElm=INT_MIN,sum=0,maxlen=0,iniMaxLen=0,tempElm;
        // for(int i=0;i<n;i++){
        //     if(startingElm==INT_MIN){
        //     startingElm=A[i];
        //     tempElm=A[i];
        //     sum+=A[i];
        //     maxlen=1;
        //     }
        //     else{
        //         startingElm=A[i];
        //         sum=0;
        //         sum+=A[i];
        //         maxlen=1;
        //     }
        //     while(sum!=0 || tempElm!=A[n-1]){
        //         tempElm=A[i++];
        //         sum+=tempElm;
        //         maxlen++;
        //     }
        //     iniMaxLen=max(maxlen,iniMaxLen);
        // }
        
        // return iniMaxLen;
        // Your code here
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends