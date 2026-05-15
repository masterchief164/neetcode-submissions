class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        Arrays.sort(intervals, (a,b)-> {
            if(a[0]==b[0]) return Integer.compare(a[1],b[1]);
            return Integer.compare(a[0], b[0]);
        });

        int ans = 0;
        int prevEnd = intervals[0][1];
        for(int[] interval: intervals) {
            int start = interval[0];
            int end = interval[1];
            if(start < prevEnd) {
                ans++;
                prevEnd = Math.min(prevEnd, end);
            } else {
                prevEnd = end;
            }
        }
        return ans-1;
    }
}
