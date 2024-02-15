/*
Approach
everytime dp[i] will represent the number of people who will share the secret on ith day.
dp[i] will be who can share the secret + who will start sharing the secret after their delay period - who will forget the secret after their forget period

Complexity
Time complexity: O(n)
Space complexity: O(n)
Code
*/
class Solution {
public:
    int modulo = 1e9 + 7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        //dp[i] will represent the number of people who will share the secret on ith day
        vector<long long> days(n+1, 0);

        //variable to keep track of people who can share the secret
        long long newPeopleSharingSecret = 0;
        days[1] = 1;                           //on the first day only A knows the secret
        for(int i=2; i<=n; i++){
            long long peopleDelay = 0, peopleForget = 0;  //people who will start sharing the secret after their delay period, and people who will forget the secret after their forget period

            if(i-delay <1) peopleDelay = 0;
            else peopleDelay = days[i-delay];

            if(i-forget<1) peopleForget = 0;
            else peopleForget = days[i-forget];

            newPeopleSharingSecret = newPeopleSharingSecret + peopleDelay - peopleForget;

            days[i] = newPeopleSharingSecret%modulo;
        }
        long long ans = 0;

        //now in the end the no. of people who knows the secret will be total number who didn't forget the secret 
        for(int d = n-forget+1; d<=n; d++){
            ans = (ans + days[d])%modulo;
        }
        return ans;
    }
};
