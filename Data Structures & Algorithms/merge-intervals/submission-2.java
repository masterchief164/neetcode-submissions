class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> {
            if(a[0]==b[0]) return Integer.compare(a[1],b[1]);
            return Integer.compare(a[0], b[0]);
        });

        List<int[]> ans = new ArrayList<>();
        ans.add(intervals[0]);

        int n = intervals.length;

        for(int[] interval: intervals) {
            int start = interval[0];
            int end = interval[1];

            int lastEnd = ans.get(ans.size()-1)[1];

            if(start<=lastEnd) {
                ans.get(ans.size()-1)[1] = Math.max(lastEnd, end);
            } else {
                ans.add(new int[]{start, end});
            }
        }
        return ans.toArray(new int[ans.size()][]);
    }
}
