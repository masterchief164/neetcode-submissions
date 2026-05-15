/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    static bool cmp(Interval a, Interval b) {
        return a.start == b.start ? a.end > b.end : a.start > b.start;
    }
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<pair<int, int>> time;
        for(auto i: intervals){
            time.push_back({i.start, 1});
            time.push_back({i.end, -1});
        }
        sort(time.begin(), time.end(), [](auto& a, auto& b){
            return a.first == b.first ? a.second < b.second : a.first < b.first;
        });

        int ans =0, curr = 0;
        for(auto x: time){
            curr +=x.second;
            ans = max(ans, curr);
        }
        return ans;
    }
};
