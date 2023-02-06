//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:

    void findSm(int index,int sum,vector<int> &arr,int N,vector<int> &res){
        if(index==N){
            res.push_back(sum);
            return;
        }
        
        findSm(index+1,sum+arr[index],arr,N,res);
        findSm(index+1,sum,arr,N,res);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> res;
        findSm(0,0,arr,N,res);
        sort(res.begin(),res.end());
        return res;
        // Write Your Code here
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends