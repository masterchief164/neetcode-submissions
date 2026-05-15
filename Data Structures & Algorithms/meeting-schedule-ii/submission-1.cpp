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

        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a.start == b.start ? a.end < b.end : a.start < b.start;
        });

        priority_queue<int, vector<int>, greater<int>> minHeap;

        for(auto interval: intervals) {
            int currStart = interval.start;

            while(minHeap.size() && minHeap.top() <= currStart) {
                minHeap.pop();
            }
            minHeap.push(interval.end);
            ans = max(ans, (int)minHeap.size());
        }

        return ans;
    }
};
