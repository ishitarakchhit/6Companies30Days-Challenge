class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if(n== 1) return 1;
        else return 0.5;

      // if 1 gets his own seat 1/n + if 1 gets 2's seat  then 2 will get either your or 1's seat 1/n*1/2*1 ........
      //when n =2: if 1 gets his own seat 1/2 else 0 

    }
};
