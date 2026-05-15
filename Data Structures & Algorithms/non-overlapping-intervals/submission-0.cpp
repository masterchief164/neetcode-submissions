class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int prevEnd = intervals[0][1];
        int ans = 0;
        int n = intervals.size();
        for(int i = 1;i<n;i++){
            int s = intervals[i][0];
            int e = intervals[i][1];

            if(prevEnd > s) {
                ans++;
                prevEnd = min(e, prevEnd);
            } else {
                prevEnd = e;
            }
        }
        return ans;
    }
};
