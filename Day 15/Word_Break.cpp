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

    //function to insert word in trie
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

    //function to search for a word in the trie
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

    bool wordBreak(string s, vector<string>& wordDict) {
        //insert all word into the trie
        Node* root = new Node('-');
        for(auto word: wordDict) insertWord(root, word);
        
        vector<bool> dp(s.size()+1, 0);    //dp[i] states that were we able to find all words occuring before i in the trie if yes then find the next word otherwise don't
        dp[0] = true;
        
        for(int len = 1; len<=s.size(); len++){
            for(int i=0; i<len; i++){
                if(dp[i] && searchWord(root, s.substr(i, len-i))) dp[len] = 1;
            }
        }
        return dp[s.size()];
    
    }
};
