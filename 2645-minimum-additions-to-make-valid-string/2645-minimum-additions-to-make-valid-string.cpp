class Solution {
public:
    int addMinimum(string word) {
        int count=0;
        int i=0;
        while(i<word.length()){
            if(i==word.length()-1){
                count+=2;
                i++;
            }
            else if(word[i]==word[i+1]){
                // cout<<"in";
                count+=2;
                i++;
            }
            else if(word[i]=='a' && word[i+1]=='b'){
                if(word[i+2]=='c'){i+=3;}
                else{count++; i+=2;}
            }
            else if(word[i]=='a' && word[i+1]=='c'){
                count+=1; 
                i+=2;
            }
            else if(word[i]=='b' && word[i+1]=='a'){
                count+=2; 
                i++;
            }
            else if(word[i]=='b' && word[i+1]=='c'){
                count++; 
                i+=2;
            }
            else if(word[i]=='c'){
                count+=2; 
                i++;
            }
            // i++;
        }
        return count;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
//         vector<int> fmap(3,0);
        
//         if(word.length()==1)return 2;
//         for(auto it:word){
//             switch(it){
//                 case 'a':
//                     // cout<<it;
//                     fmap[0]++;
//                     break;
//                 case 'b':
//                     // cout<<it;
//                     fmap[1]++;
//                     break;
//                 case 'c':
//                     // cout<<"c";
//                     fmap[2]++;
//                     break;
//             }
//         }
        
//         int maxi=*max_element(fmap.begin(),fmap.end());
//         // cout<<"m: "<<maxi;
//         int count=0;
//         while(fmap[0]!=maxi){
//             count++;
//             fmap[0]++;
//         }
//          while(fmap[1]!=maxi){
//             count++;
//             fmap[1]++;
//         }
//          while(fmap[2]!=maxi){
//             count++;
//             fmap[2]++;
//         }
//     return count;
    }
};