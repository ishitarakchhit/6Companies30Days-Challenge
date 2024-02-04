/*
Approach
push sum with values into the heap and always take out the max sum and distribute according to turn wise

Complexity
Time complexity: O(n)
Space complexity: O(n)
Code
*/
class Solution {
public:
    class Compare{
        public:
        bool operator()(pair<int,int> a, pair<int,int> b){
            return b.second<a.second;
        }
    };

    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        priority_queue<pair<int,pair<int,int>>> pq;

        for(int i=0; i<aliceValues.size(); i++){
            pq.push({aliceValues[i]+bobValues[i], {aliceValues[i], bobValues[i]}});
        }
        bool turn = 1;
        int a_scores=0, b_scores = 0;

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            //cout<<top.second.first<<" "<<top.second.second<<"     ";
            if(turn ==1 ){
                a_scores+= top.second.first;
                turn =0;
            }
            else{
                b_scores+= top.second.second;
                turn =1;
            }
            //cout<<a_scores<<" "<<b_scores<<endl;
        }
        if(a_scores==b_scores) return 0;
        else if(a_scores>b_scores) return 1;
        else return -1;
    

        
    }
};
