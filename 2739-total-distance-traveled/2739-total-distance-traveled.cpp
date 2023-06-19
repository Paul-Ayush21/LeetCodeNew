class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int used=0;
        int total=0;
        while(true){
            if(used==5){
                if(additionalTank>0){
                    mainTank+=1;
                    additionalTank-=1;
                    used=0;
                }
            }
            if(mainTank>0){
                mainTank=mainTank-1;
                used++;
                total++;
            }
            else{
                break;
            }
        }   
        return total*10;
    }
};