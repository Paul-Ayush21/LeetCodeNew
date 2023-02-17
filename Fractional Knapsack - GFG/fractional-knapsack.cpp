//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    bool static comp(Item a,Item b){
        double a1=(double)a.value/(double)a.weight;
        double b1=(double)b.value/(double)b.weight;
        return(a1>b1);
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr+n,comp);
        int currWeight=0;
        double finalValue=0;
        for(int i=0;i<n;i++){
            if(currWeight+arr[i].weight<=W){
                finalValue+=arr[i].value;
                currWeight+=arr[i].weight;
            }
            else{
                double remW=W-currWeight;
                double remVal=((double)arr[i].value / (double)arr[i].weight) * remW;
                finalValue+=remVal;
                break;
            }
        }
        return finalValue;
        // Your code here
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends