class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //initialize dp array with INT_MAX and dp[0]=0
        int dp[amount + 1];
        dp[0]=0;
        for(int i=1;i<=amount; i++)
            dp[i]=INT_MAX;
        
        int len = coins.size();
        //fill array from amount=1 to amount's value
        for(int i=1; i<= amount; i++){
            for (int j=0; j<len; j++){
                // if the coins value is less than the current amount
                if(coins[j] <= i) {
                    //if acceptable find the cost of rest of the amount
                    int rest = dp[i-coins[j]];
                    if(rest != INT_MAX && rest +1 < dp[i]){
                        dp[i]= rest+1;
                    }
                }
            }
        }
        return dp[amount]==INT_MAX ? -1 : dp[amount];
    }
};
