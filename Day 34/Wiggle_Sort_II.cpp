/*
Intuition
Since we need alternative increasing decreasing elements. WHy not to place decreasing elements in one go and fill the rest of the space with remaining elements.

Approach
Start by sorting the entire nums array. Now reverse iterate nums and place the elements alternatively in ans.
Now keep two pointers, j and k in the starting and ending blank cell of ans.
Place the remaining nums[i] in ans[j] and then ans[k].

Complexity
Time complexity: O(n logn)
Space complexity: O(n)
Code
*/
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int k=1, n=nums.size();
        vector<int> ans(n, -1);
        int i=n-1;
        while(k<n && i>=0){
            ans[k] = nums[i];
            k+=2; i--;
        }

        int j=0;
        if(ans[n-1] == -1) k=n-1;
        else k=n-2; 

        while(i>=0){
            if(ans[j] == -1)
                ans[j] = nums[i--];
            else
                if(ans[k] == -1)
                    ans[k] = nums[i--];
            j+=2;
            k-=2;
        }
        //for(auto it: ans) cout<<it<<" ";
        cout<<endl;
        nums = ans;
        
    }
};
