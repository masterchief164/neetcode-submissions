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
    int minMeetingRooms(vector<Interval>& intervals) {
        int ans = 0;

        vector<pair<int, int>> tmp;

        for(auto x: intervals) {
            tmp.push_back({x.start, +1});
            tmp.push_back({x.end, -1});
        }

        sort(tmp.begin(), tmp.end(), [](auto& a, auto& b) {
            return a.first == b.first ? a.second < b.second : a.first < b.first;
        });

        int maxi = 0, curr = 0;
        for(auto x: tmp) {
            curr +=x.second;
            maxi = max(maxi, curr);
        }

        return maxi;
    }
};
