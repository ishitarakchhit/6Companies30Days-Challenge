class Solution {
public:
    int modulo = 1000000007;
    int f(int startPos, int endPos, int k, vector<vector<int>> &dp){
        if(startPos == endPos && k == 0){
            return 1;
        }
        if(k==0){
            return 0;
        }
        if(abs(startPos-endPos) > k) return 0;

        if(dp[startPos+1000][k] != -1)return dp[startPos+1000][k];

        //two ways - to left, right
        int a = f(startPos-1, endPos, k-1, dp);
        
        int b = f(startPos+1, endPos, k-1, dp);
        dp[startPos+1000][k] = (a+b)%modulo;
        return (a + b )%modulo;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>> dp(3001, vector<int> (1001, -1));   //limits from 0 to 1000 and with k goes from -1000 to 2000 
        return f(startPos, endPos, k, dp)%modulo;
    }
};
