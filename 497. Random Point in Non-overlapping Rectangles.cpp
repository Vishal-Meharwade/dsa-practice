class Solution {
    int num_pts;
    vector<int> rect_cum_count;
    vector<vector<int>> rects;
    
public:
    Solution(vector<vector<int>>& rects) {
        num_pts = 0;
        this->rects = rects;
        for(vector<int>& rect: rects){
            num_pts += (rect[2] - rect[0] + 1)*(rect[3] - rect[1] + 1);
            rect_cum_count.push_back(num_pts);
        }
    }
    
    vector<int> pick() {
        int pt_idx = rand() % num_pts;
        int l = 0, r = rects.size()-1;
        while(l < r){
            int mid = l + (r-l)/2;
            if(rect_cum_count[mid] <= pt_idx) l = mid+1;
            else r = mid;
        }

        vector<int>& rect = rects[l];
        int x_pts = rect[2] - rect[0] + 1;
        int y_pts = rect[3] - rect[1] + 1;
        int pts_in_rect = x_pts*y_pts;
        int pt_start = rect_cum_count[l] - pts_in_rect;
        int offset = pt_idx - pt_start;
        return {rect[0] + offset%x_pts, rect[1] + offset/x_pts};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
