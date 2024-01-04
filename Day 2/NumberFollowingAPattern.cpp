
//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string pattern){
        stack<char> s; string ans = "";

        if(pattern[0] == 'I') ans += '1';
        else s.push('1');

        for(int i=1; i<=pattern.size(); i++){
            if(pattern[i-1] == 'I'){
                while(!s.empty()) {
                    ans += s.top(); s.pop();
                }
            }
            s.push('0' + i+ 1);
        }

        while(!s.empty()) {
            ans += s.top(); s.pop();
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 

// } Driver Code Ends
