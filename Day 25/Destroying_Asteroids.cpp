/*
Approach
sorting + greedy

Complexity
Time complexity: O(nlogn + n)
Space complexity: O(1)
Code
*/
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long m = (long long)mass;
        for(int i=0; i<asteroids.size(); i++){
            if(m<asteroids[i]) return false;
            else m+= asteroids[i];
        }
        return true;
    }
};
