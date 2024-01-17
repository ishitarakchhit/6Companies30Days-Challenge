// Approach
// using unordered_map, and priority queue

// Complexity
// Time complexity: O(n + n + k*log(n))
// Space complexity: O(n + n)

class Solution {
public:
    struct Compare {
    bool operator()( pair<int, string>& a,  pair<int, string>& b) {
        if(a.first != b.first) return a.first < b.first;
        return a.second > b.second;
    }
};

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;            //string , frequency
        int highest = 0;

        for(auto word: words){
            mp[word]++;
            if(mp[word] >highest) highest = mp[word];
        }

        vector<string> ans;

        //to pick the top most frequent strings
        priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> pq;

        for(auto it: mp){
            pq.push({it.second, it.first});
        }

        while(k){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }

        return ans;
    }
};
