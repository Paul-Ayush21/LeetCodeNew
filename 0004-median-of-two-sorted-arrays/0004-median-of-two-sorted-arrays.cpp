class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size()<nums1.size()) return findMedianSortedArrays(nums2,nums1);
        int n1=nums1.size();
        int n2=nums2.size();
        int low=0, high=n1;
        while(low<=high){
        
            int cut1=(low+high)>>1;
            int cut2=(n1+n2+1)/2-cut1;
            
            int left1=cut1==0?INT_MIN:nums1[cut1-1];
            int right1=cut1==n1?INT_MAX:nums1[cut1];
            int left2=cut2==0?INT_MIN:nums2[cut2-1];
            int right2=cut2==n2?INT_MAX:nums2[cut2];
            
            if(left1<=right2 && left2<=right1){
                if((n1+n2)%2==0){
                    return (max(left1,left2)+min(right1,right2))/2.0;
                }
                else{
                    return max(left1,left2);
                }
                
            }
            else if(left1>right2){
                high=cut1-1;
            }
            else{
                low=cut1+1;
            }
            
        
        }
        return 0.0;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        // int l=0,i=0,j=0,k;
        // int len1=nums1.size();
        // int len2=nums2.size();
        // vector<int> res;
        // while(i<len1 && j<len2){
        //     if(nums1[i]<nums2[j]){
        //         res.push_back(nums1[i]);
        //         i++;                
        //     }
        //     else{                
        //         res.push_back(nums2[j]);
        //         j++;
        //     }
        // }
        // if(i>=len1){
        //     while(j<len2){
        //         res.push_back(nums2[j]);
        //         j++;                
        //     }            
        // }
        // else{
        //     while(i<len1){
        //         res.push_back(nums1[i]);
        //         i++;                
        //     }
        // }
        // if(res.size()%2==0){            
        //     return (double)(res[res.size()/2] + res[res.size()/2-1])/2;            
        // }
        // else{            
        //     return (res[res.size()/2]);
        // } 
        
        
        
    }
};