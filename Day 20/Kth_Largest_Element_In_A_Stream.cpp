class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int kLarge;
    KthLargest(int k, vector<int>& nums) {
        for(auto num: nums){
            pq.push(num);
        }
        kLarge = k;
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size()>kLarge) pq.pop();
        return pq.top();
    }
};
