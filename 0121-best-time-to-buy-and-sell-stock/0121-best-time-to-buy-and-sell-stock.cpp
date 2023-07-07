class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro=0;
        int cost=prices[0];
        for(int i=1;i<prices.size();i++){
            maxPro=max(maxPro,prices[i]-cost);
            cost=min(cost,prices[i]);
        }
        return maxPro;
    }
};