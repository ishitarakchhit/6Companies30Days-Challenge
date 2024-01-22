// //Approach 1: Recursion
// leetscode dictionary= {leet, code}
// pass idx , check if l, le, lee, leet, leetc, leetco, leetcod, leetcode are present in the dictionary or not, if yes then call for the remaining string and store minimum of size-idx and answer from recursive call of remaining string. 
// in the end call for remaining string after idx and store min of ans and 1(if we do not include current char in ans this will be an extra string) + answer from recursive call of remaining string after idx.
// time: O(2^n)
// space: O(n)

// //approach2: optimisation with memorization
// use single array to store dp[idx]
// time: O(n^2)
// space: O(n) + O(n+L)

// //approach3: optimisation with tabulation
// time: O(n^2)
// space: O(n+L)

// //apporoach 4: dp with trie(for word matching)
// time: O(n^2)
// space: O(n + L)

class Solution {
public:
    bool isPresent(vector<string>& dictionary, string &word){
        for(auto d: dictionary){
            if(d== word) return true;
        }
        return false;
    }

    int f(string &s, int idx, vector<string> &dictionary, vector<int> &dp){
        if(idx == s.size()) return 0;

        if(dp[idx]!=-1) return dp[idx];
        
        //run a loop to check for all strings 
        string temp = "";
        int ans = s.size() - idx;
        

        for(int i=idx; i<s.size(); i++){
            temp += s[i];
            if(isPresent(dictionary, temp)){
                ans = min(ans, f(s, i+1, dictionary, dp));
            }
        }
        ans = min(ans, 1+f(s, idx+1, dictionary, dp));
        dp[idx] = ans;
        return ans;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        int idx = 0;
        vector<int> dp(s.size()+1, -1);
        return f(s, 0, dictionary, dp);
    }
};

//Approch3
class Solution {
public:
    bool isPresent(vector<string>& dictionary, string &word){
        for(auto d: dictionary){
            if(d== word) return true;
        }
        return false;
    }

    // int f(string &s, int idx, vector<string> &dictionary, vector<int> &dp){
    //     if(idx == s.size()) return 0;

    //     if(dp[idx]!=-1) return dp[idx];

    //     //run a loop to check for all strings 
    //     string temp = "";
    //     int ans = s.size() - idx;
        

    //     for(int i=idx; i<s.size(); i++){
    //         temp += s[i];
    //         if(isPresent(dictionary, temp)){
    //             ans = min(ans, f(s, i+1, dictionary, dp));
    //         }
    //     }
    //     ans = min(ans, 1+f(s, idx+1, dictionary, dp));
    //     dp[idx] = ans;
    //     return ans;
    // }

    int f(string &s, vector<string> &dictionary, vector<int> &dp){
        int idx = 0;

        int n = s.size();
        dp[n] = 0;

        for(int idx = n-1; idx>=0; idx--){
            string temp = "";
            int ans = n - idx;

            for(int i=idx; i<s.size(); i++){
                temp += s[i];
                if(isPresent(dictionary, temp)){
                    ans = min(ans, dp[i+1]);
                }
            }
            ans = min(ans, 1+dp[idx+1]);
            dp[idx] = ans;     
        }
        return dp[0];
        
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        vector<int> dp(s.size()+1, -1);
        return f(s, dictionary, dp);
    }
};

//Approach 4
class Solution {
public:
    class Node{
        public:
        char data;
        Node* children[26];
        bool isTerminal;
        Node(char d){
            this->data = d;
            for(int i=0; i<26; i++) this->children[i] = NULL;
            this->isTerminal = false;
        }
    };

    void insertWord(Node* root, string word){
        //base case: if the word has exhausted mark it to be terminal
        if(word.size() == 0){
            root->isTerminal = true;
            return;
        }
        char ch= word[0];
        int index = ch-'a';
        if(root->children[index]!= NULL){
            root = root->children[index];
        }
        else{
            Node* newNode = new Node(ch);
            root->children[index] = newNode;
            root = root->children[index];
        }
        insertWord(root, word.substr(1));
    }

    bool searchWord(Node* root, string s){
        //base caase
        if(s.size() == 0){
            if(root->isTerminal == true) return true;
            else return false;
        }
        
        char ch = s[0];
        int index = ch - 'a';

        if(root->children[index] == NULL) return false;
        else{
            root = root->children[index];
        }
        
        return searchWord(root, s.substr(1));
    }

    int f(string &s, Node* &root, vector<int> &dp){
        int idx = 0;

        int n = s.size();
        dp[n] = 0;

        for(int idx = n-1; idx>=0; idx--){
            string temp = "";
            int ans = n - idx;

            for(int i=idx; i<s.size(); i++){
                temp += s[i];
                if(searchWord(root, temp)){
                    ans = min(ans, dp[i+1]);
                }
            }
            ans = min(ans, 1+dp[idx+1]);
            dp[idx] = ans;     
        }
        return dp[0];
        
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        Node* root = new Node('-');
        //insert all words into trie
        for(auto d: dictionary) insertWord(root, d);

        vector<int> dp(s.size()+1, -1);
        return f(s, root, dp);
    }
};
