class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        if(arr.size()<3) return 0;
        int low=0,high=arr.size()-1;
        while(high>low){
            int mid=(high+low)/2;
            if(arr[mid]>arr[mid+1]) high=mid;
            else low=mid+1;
        }
        return low;
        
    }
};