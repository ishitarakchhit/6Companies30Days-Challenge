/*
Intuition
resolve all RLs then SL then RS

Complexity
Time complexity: O(n)
Space complexity: O(1)
Code
*/
class Solution {
public:
    int countCollisions(string directions) {
        //first convert all RL to SS
        int collisions = 0;

        for(int i=0; i<directions.size()-1; i++){
            if(directions[i]=='R' && directions[i+1]=='L'){
                collisions+=2;
                directions[i] = 'S'; 
                directions[i+1] = 'S';
                i++;
            }
        }
        //now convert all SL to SS
        for(int i=0; i<directions.size()-1; i++){
            if(directions[i] == 'S' && directions[i+1] == 'L'){
                collisions++;
                directions[i+1] = 'S';
            }
        }

        //now convert all RS to SS
        for(int i=directions.size()-1; i>0; i--){
            if(directions[i] == 'S' && directions[i-1] == 'R'){
                collisions++;
                directions[i-1] = 'S';
            }
        }

        return collisions;
    }
};
