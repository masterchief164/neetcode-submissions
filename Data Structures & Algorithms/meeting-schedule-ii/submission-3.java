/**
 * Definition of Interval:
 * public class Interval {
 *     public int start, end;
 *     public Interval(int start, int end) {
 *         this.start = start;
 *         this.end = end;
 *     }
 * }
 */

class Solution {
    public int minMeetingRooms(List<Interval> intervals) {
        TreeMap<Integer, Integer> vals = new TreeMap<>();
        for(Interval i: intervals) {
            vals.put(i.start,vals.getOrDefault(i.start, 0)+ 1);
            vals.put(i.end, vals.getOrDefault(i.end, 0)-1);
        }

        int ans = 0, curr = 0;

        for(int key: vals.keySet()) {
            curr+=vals.get(key);
            ans = Math.max(curr, ans);
        }

        return ans;
    }
}
