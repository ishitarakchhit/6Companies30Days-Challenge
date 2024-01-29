/*
Intuition
we need area of a square so we should compute the side from both the bars and take up minimum from both of them.
Now we will have to compute the area, to do this we can compute a window which has maximum consequtive increasing elements.

Approach
Sorting and sliding window

Complexity
Time complexity: O(hBars.size()) + O(vBars.size())
Space complexity: O(1)
Code
*/
class Solution {
public:
    int maxSize(vector<int> &bars){
        //run a window to find the maximum size of continuos numbers in the array
       
        int maxSize = 1;
        int i = 0, j=0;
        while(i<bars.size() && j<(bars.size()-1)){

            if(bars[j]+1 == bars[j+1]){
                j++;
                maxSize = max(maxSize, j-i+1);
            }
            else{
                maxSize = max(maxSize, j-i+1);
                i=j+1;
                j++;
            }
        }
        
        maxSize = max(maxSize, j-i+1);
        return maxSize;
    }

    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        //for horizontal : n
        //for vertical: m
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        //to find the maximum size of continuous numbers in array
        int height = maxSize(hBars);
        int width = maxSize(vBars);
        int side = min(height, width);
        side++;
        return side*side;
    }
};
