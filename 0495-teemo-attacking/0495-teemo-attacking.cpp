class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int seconds=duration;
        int n=timeSeries.size();
        for(int i=0;i<n-1;i++){
            if(timeSeries[i]+duration>timeSeries[i+1]){
                seconds+=timeSeries[i+1]-timeSeries[i];
            }
            else{
                seconds+=duration;
            }
        }
        return seconds;
    }
};