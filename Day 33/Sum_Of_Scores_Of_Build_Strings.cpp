/*
Intuition
The question involved string matching pattern but with higher constraints. So brute force method wouldn't work. Here, z-algorithm comes to rescue.

Approach
Find the z-array using z-algorithm and then find the sum of entire z-array + original string size.

How Z-Function works?
In Z-array, z[i] represents the length of substring which starts from index i and matches with the original string.
Brute force: to find z-array involves two loop approach for pattern matching and requires a time complexity of O(n^2)
Best approach, tracks the range of most recent substring that was matched with the original string.
It then uses the already calculated values of z[i] to find the current value of z[i].
z[0] is initialized with 0 as an inital configuration.
Now you calculate the length of substring matched for z[1] and update it. While doing this you already traversed or checked the values s[i+1], s[i+2], s[i+3], s[i+4]... until the substring was matching. So when you now have to calculate z[i+1], why to again check these values ?
To avoid these repeated checks, we keep a track of range by using variables l and r.
When you have to calculate the value of z[j] (z[j] represents the current index), you check if you are inside the range or not. If yes, then you can use the previously computed values(make sure its value doesn't exceed your current substring) uptil the length your z[i] performed checks and then check for further string via naive method and increment z[j].
Once you are done, update l and r.
Complexity
Time complexity: O(n)
Space complexity: O(n)
Code
*/
class Solution {
public:

    void z_function(string &s, vector<int> &z){
        int n = s.length();
        int l = 0, r = 0;   // this represents the range of last substring that matched with the original string
        for(int i=1; i<s.length(); i++){
            //store the previous result of pattern matching
            if(i<r){
                z[i] = z[i-l];
                if(i+z[i] > r) z[i] = r-i;
            }

            //now match further letters from the current index
            while(z[i]+i<n && s[i+z[i]]==s[z[i]])   z[i]++;

            //update l,r 
            if(i+z[i] > r){
                l = i;
                r = i+z[i];
            }
        }
    }

    long long sumScores(string s) {

        //approach: Z-algorithm
        
        vector<int> z(s.length(), 0);
        z_function(s, z);

        long long ans = s.length();
        for(auto it: z) ans+= it;
        
        return ans;
    }
};
