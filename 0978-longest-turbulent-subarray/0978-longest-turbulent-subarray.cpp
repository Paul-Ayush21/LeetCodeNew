class Solution {
public:
    
    int maxTurbulenceSize(vector<int>& arr) {
        if(arr.size()==1) return 1;
        if(arr.size()==0) return 0;
        // int k=0;
        // if(arr[0]>arr[1]) k=1;
        // return f(0,k,arr);
        int maxi=0;
        int flag;
        int n=arr.size()-1;
        for(int i=0;i<arr.size();i++){
            int cnt=1;
            if(i!=n && arr[i]>arr[i+1])flag=0;
            else if(i!=n && arr[i]<arr[i+1]) flag=1;
            else {
                maxi=max(maxi,cnt);
                continue;
            }
            for(int j=i+1;j<arr.size();j++){
                cnt++;
                if(flag==0){
            
                    if(j!=n && arr[j]<arr[j+1]){
                        flag=1;
                    }
                    else break;
                }
                else{
                    
                    if(j!=n && arr[j]>arr[j+1]){
                        flag=0;
                    }
                    else break;
                }
            }
                maxi=max(maxi,cnt);
            
            
        }
        return maxi;
    }
    
};