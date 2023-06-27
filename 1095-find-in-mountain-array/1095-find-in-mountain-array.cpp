/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int low=0;
        int high=mountainArr.length()-1;
        int max=0;
//         while(true){
//             if(mountainArr.get(max)>mountainArr.get(max+1)){
//                 break;
//             }
//             max++;
//         }
    
        int l1=1,h1=mountainArr.length()-1;
        while(l1<=h1){
            int mid=(l1+h1)/ 2;
            int g=mountainArr.get(mid);
            int g1=mountainArr.get(mid-1);
            int g2=mountainArr.get(mid+1);
            if(g>g2 && g1<g){
                max=mid;
                break;
            }
            else if(g<g2){
                l1=mid+1;
            }
            else{
                h1=mid-1;
            }
        }
        
        // cout<<max<<endl;
        int low2=max+1;
        // cout<<low2;
        int k=INT_MAX;
        while(low<=max){
            int mid=(low+max)/ 2;
            int g=mountainArr.get(mid);
            if(target==g){
                k=mid;
                break;
            }
            else if(target>g){
                low=mid+1;
            }
            else{
                max=mid-1;
            }
        }
        // cout<<"High: "<<high<<endl;
        while(low2<=high){
            int mid=(low2+high)/ 2;
            int g=mountainArr.get(mid);
            if(target==g){
                return min(mid,k);
            }
            else if(target<g){
                low2=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        if(k!=INT_MAX){
            return k;
        }
        return -1;
    }
};