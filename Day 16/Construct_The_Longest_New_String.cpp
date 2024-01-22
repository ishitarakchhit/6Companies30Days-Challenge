class Solution {
public:

    int helper(int x, int y, int z, int last, auto &dp){
        if(x == 0 && y == 0 && z== 0) return 0;

        if(dp[x][y][z][last] != 0) return dp[x][y][z][last];
        //add x
        int a =0, b = 0, c= 0; 
        if(last!=1){
            if(x)
                a = 2 + helper(x-1, y, z, 1, dp);
        }

        if(last!=1){
            if(z)
                c = 2 + helper(x, y, z-1, 3, dp);
        }
        //add y
        if(last <= 1){
            if(y)
                b = 2+ helper(x, y-1, z, 2, dp);
        }

        dp[x][y][z][last] = max(max(a, b), c);
        return max(max(a, b), c);
    }

    int longestString(int x, int y, int z) {
        int last = 0;
        int dp[51][51][51][4] = {};
        return helper(x, y, z, last, dp);
    }
};





//approach 2
class Solution {
public:

    

    int longestString(int x, int y, int z) {
        //for string with ABABABAB
        int ans = z*2;

        //for string with AABBAABB 
        ans += min(x, y)*4;

        if(x>y || y>x) ans+=2;
        return ans;
    }
};
