class Solution {
public:
    vector<vector<int>> rects;
    vector<int> points;
    long long total = 0;

    Solution(vector<vector<int>>& rects) {
        this->rects = rects;
        
        //tracking number of points of each rectangle
        for(int i=0; i<rects.size(); i++){
            int x = abs(rects[i][0]-rects[i][2]);
            int y = abs(rects[i][1]-rects[i][3]);
            int area = (x+1)*(y+1);
            total += area;
            points.push_back(total);
        }
    }
    vector<int> pick() {
        long long point = rand()%total;

        int l = 0, h = rects.size()-1;
        while(l<h){
            int mid = l + (h-l)/2;

            if(points[mid]<=point){
                l = mid+1;
            }
            else h = mid;
        }

        //now calculate hte area
        auto rect = rects[l];
        int x = (rect[2] - rect[0] + 1);
        int y = (rect[3] - rect[1] + 1);
        int area = x*y;
        
        int pt = points[l] - area;
        int offset = point - pt;

        return {rect[0] + offset%x, rect[1] + offset/x};


    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
