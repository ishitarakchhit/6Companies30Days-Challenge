/*
Intuition
the question starts from a basic version like pick not pick problem using recursion.

Approach 1 (TLE & Not AC)
Recursion

Complexity
Time complexity: O(2^n)
Space complexity: O(n)
Code
*/
class Solution {
public:
int func(vector<vector> &envelopes, int i, int last){
if(i==envelopes.size()) return 0;

    int a= 0, b = 0;
    pair<int,int> lastDoll = {0,0};

    if(last!=0)
        lastDoll = {envelopes[last-1][0], envelopes[last-1][1]};
    
    pair<int,int> curr = {envelopes[i][0], envelopes[i][1]};
    
    if((last == 0)||(curr.first>lastDoll.first && curr.second > lastDoll.second)){
        a = 1+func(envelopes, i+1, i+1);
    }
    b = func(envelopes, i+1, last);
    return max(a, b);

}

int maxEnvelopes(vector<vector<int>>& envelopes) {    
    int last = 0;
    int n = envelopes.size();
    sort(envelopes.begin(), envelopes.end());
    int i=0;
    return func(envelopes, i, last);
}
};


/*
Approach 2 (TLE & Not AC)
Recursion + memoization

Complexity
Time complexity: O(n^2)
Space complexity: O(n^2 + n)
Code
*/
class Solution {
public:
int func(vector<vector> &envelopes, int i, int last, vector<vector> &dp){
if(i==envelopes.size()) return 0;

    if(dp[i][last]!=-1) return dp[i][last];
    int a= 0, b = 0;
    pair<int,int> lastDoll = {0,0};

    if(last!=0)
        lastDoll = {envelopes[last-1][0], envelopes[last-1][1]};
    
    pair<int,int> curr = {envelopes[i][0], envelopes[i][1]};
    
    if((last == 0)||(curr.first>lastDoll.first && curr.second > lastDoll.second)){
        a = 1+func(envelopes, i+1, i+1, dp);
    }
    b = func(envelopes, i+1, last, dp);
    dp[i][last] = max(a, b);
    return max(a, b);

}

int maxEnvelopes(vector<vector<int>>& envelopes) {    
    int last = 0;
    int n = envelopes.size();
    vector<vector<int>> dp(n, vector<int> (n, -1));
    sort(envelopes.begin(), envelopes.end());
    int i=0;
    return func(envelopes, i, last, dp);
}
};


/*
Approach 3 (MLE & Not AC)
Recursion + Tabulation

Complexity
Time complexity: O(n^2)
Space complexity: O(n^2)
Code
*/
class Solution {
public:
int func(vector<vector> &envelopes, int i, int last, vector<vector> &dp){
if(i<0) return 0;

    int n = envelopes.size();
    if(dp[i][last]!=-1) return dp[i][last];
    int a= 0, b = 0;
    pair<int,int> lastDoll = {0,0};

    if(last!=n)
        lastDoll = {envelopes[last][0], envelopes[last][1]};
    
    pair<int,int> curr = {envelopes[i][0], envelopes[i][1]};
    
    if((last == n)||(curr.first<lastDoll.first && curr.second < lastDoll.second)){
        a = 1+func(envelopes, i-1, i, dp);
    }
    b = func(envelopes, i-1, last, dp);
    dp[i][last] = max(a, b);
    return max(a, b);

}

int func(vector<vector<int>> &envelopes, int last){
    int n = envelopes.size();
    vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

    for(int j=1; j<=n; j++){
        if((j==n) || (envelopes[0][0]<envelopes[j][0] && envelopes[0][1]< envelopes[j][1]))
            dp[0][j] = 1;
    }

    for(int i=1; i<n; i++){
        for(int j=i; j<=n; j++){
            int a= 0, b = 0;
            pair<int,int> lastDoll = {0,0};

            if(j!=n)
                lastDoll = {envelopes[j][0], envelopes[j][1]};
            
            pair<int,int> curr = {envelopes[i][0], envelopes[i][1]};
            
            if((j == n)||(curr.first<lastDoll.first && curr.second < lastDoll.second)){
                a = 1+ dp[i-1][i];
            }
            b = dp[i-1][j];
            dp[i][j] = max(a, b);
        }

    }

    return *max_element(dp[n-1].begin(), dp[n-1].end());
}

int maxEnvelopes(vector<vector<int>>& envelopes) {    
    int n = envelopes.size();
    int last = n;
    sort(envelopes.begin(), envelopes.end());
    vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
    return func(envelopes,n);
}
};


/*
Approach 4 (TLE & Not AC)
Optimization using Binary Search

Complexity
Time complexity: O(n * log(n))
Space complexity: O(n)
Code
*/
class Solution {
public:
    
    static bool comp(vector<int> a, vector<int> b){
            if(a[0] == b[0]) return a[1]> b[1];
            else return a[0] < b[0];
        }
    
    //function to return the lower bound of an element
    int lower_bound(vector<int> &arr, int k){
        int s = 0, e = arr.size()-1;
        int ans = -1;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(arr[mid]>= k){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return ans;
    }

    //function to find the longest increasing subsequence
    int b_search(vector<vector<int>> &envelopes, int n){
        int len = 1;
        vector<int> temp;
        temp.push_back(envelopes[0][1]);

        for(int i=1; i<n; i++){
            if(temp.back()< envelopes[i][1]){
                len++;
                temp.push_back(envelopes[i][1]);
            }

            //else find the lower bound to push after that index
            int l_Bound = lower_bound(temp, envelopes[i][1]);
            if(l_Bound!=-1)
            temp[l_Bound] = envelopes[i][1];
        }
        return len;
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {    
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), comp);
        
        for(int i=0; i<n; i++) cout<<envelopes[i][1]<<" ";
        return b_search(envelopes, n);
        //return func(envelopes,n);
    }
};
