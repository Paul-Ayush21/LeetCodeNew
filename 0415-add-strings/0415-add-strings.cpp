class Solution {
public:
    
    void add_carry(string nums,int &i,int& carry, string &ans){
        if(i<0)return;
        int sum=(nums[i]-'0')+carry;
        if(sum<=9){
            ans+=(sum+'0');
            carry=0;
        }
        else{
            carry=sum/10;
            ans+=(sum%10+'0');
            
        }
        i--;
        add_carry(nums,i,carry,ans);
    }
    
    void add_elm(string nums1,string nums2,int &i, int &j,int &carry,string &ans){
        if(i<0||j<0) return;
        int sum=(nums1[i]-'0')+(nums2[j]-'0')+carry;
        if(sum<=9){
            ans+=(sum+'0');
            carry=0;
        }
        else{
            carry=sum/10;
            ans+=(sum%10+'0');
        }
        i--;
        j--;
        add_elm(nums1,nums2,i,j,carry,ans);
    }   
    string addStrings(string nums1, string nums2) {
        int i=nums1.size()-1,j=nums2.size()-1,carry=0;
        string ans="";
        add_elm(nums1,nums2,i,j,carry,ans);
        
        if(i>=0)add_carry(nums1,i,carry,ans);
        if(j>=0)add_carry(nums2,j,carry,ans);
        
        if(carry>0){
            ans+=(carry+'0');
        }
        reverse(ans.begin(),ans.end());
        cout<<('1'+'0');
        cout<<typeid('1'+'0').name();
        return ans;
    }
};