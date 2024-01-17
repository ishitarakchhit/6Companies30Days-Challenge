// Approach
// max heap and hashing
// store all frequencies in the hashmap then store frequency with chars in priority queue to get the character with current highest frequency

// Complexity
// Time complexity: O(n + n*log(n))
// Space complexity: O(n + n)
// Code
class Solution {
public:
    string frequencySort(string s) {
        string ans = "";
        
        priority_queue<pair<int,char>> pq;

        map<char, int> mp;          //character mapped to its frequency
        for(int i=0; i<s.size(); i++){
            char ch =s[i];
            mp[ch]++;
        }

        for(auto it: mp){
            pq.push({it.second, it.first});
        }


        while(pq.size()>=1){
            int frequency = pq.top().first;
            int character = pq.top().second;
            pq.pop();

            while(frequency){
                ans += character;
                frequency--;
            }
        }
         
        return ans;
    }
};
