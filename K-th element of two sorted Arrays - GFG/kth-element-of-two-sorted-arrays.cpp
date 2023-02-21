//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {   
    int res[n+m];
        int l1=0,l2=0,i=0;
        while(l1<n && l2<m){
            if(arr1[l1]<=arr2[l2]){
                res[i]=arr1[l1];
                i++;
                l1++;
            }
            else{
                res[i]=arr2[l2];
                i++;
                l2++;
            }
        }
        while(l1<n){
            res[i]=arr1[l1];
            i++;
            l1++;
        }
        while(l2<m){
            res[i]=arr2[l2];
            i++;
            l2++;
        }
        
        return res[k-1];
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends