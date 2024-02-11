//approach 1: brute force
//approach 2: using trie data structure
class WordDictionary {
public:
    vector<string> words;
    WordDictionary() {

    }
    
    void addWord(string word) {
        words.push_back(word);        
    }
    bool match(string &word, string &temp){
        for(int i=0; i<word.size(); i++){
            if(temp[i] == '.') continue;
            if(temp[i]!= word[i]) return false;
        }
        return true;
    }
    bool search(string word) {
        for(int i=0; i<words.size(); i++){
            if(words[i].size() == word.size()){
                if(words[i][0] == word[0] || word[0] == '.'){
                    if(match(words[i], word)) return true;
                }
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
