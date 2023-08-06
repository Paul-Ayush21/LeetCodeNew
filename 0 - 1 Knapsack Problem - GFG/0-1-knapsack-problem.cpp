//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int f(int ind, int W, int n,int wt[],int val[],vector<vector<int>> &dp){
        if(ind==n-1){
            if(wt[ind]<=W) return val[ind];
            return 0;
        }
        
        if(W==0){
            return 0;
        }
        
        if(dp[ind][W]!=-1) return dp[ind][W];
        int take=0;
        if(wt[ind]<=W){
            take=val[ind]+f(ind+1,W-wt[ind],n,wt,val,dp);
        }
        int notTake=f(ind+1,W,n,wt,val,dp);
        return  dp[ind][W]= max(take,notTake);
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>> dp(n,vector<int>(W+1,-1));
       // Your code here
       return f(0,W,n,wt,val,dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends