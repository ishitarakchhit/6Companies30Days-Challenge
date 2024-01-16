// Approach
// generate all the disjoint subsequences and find lcs

// Complexity
// Time complexity: O(2^n * n^2)
// Space complexity: O(n + n*n)
// Code
class Solution {
public:
    int func(string s){
        string s2 = s;
        reverse(s2.begin(), s2.end());
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        for(int i=0; i<=n; i++){
            dp[i][0] = 0;
            dp[0][i] = 0;
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[n][n];
    }

    void generate(string &s, string s1, string s2, int n, int &ans){
        if(n<0){
            ans = max(ans, func(s1)*func(s2));
            return;
        }

        //put the current char in s1 or s2
        generate(s, s1+s[n], s2, n-1, ans);
        generate(s, s1, s2+s[n], n-1, ans);
    }

    int maxProduct(string s) {
        int n= s.size();
        int ans = 0;
        string s1 = "";
        generate(s, s1, s1, n-1, ans);
        return ans; 
    }
};
