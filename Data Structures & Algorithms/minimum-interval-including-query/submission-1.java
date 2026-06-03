class Solution {
    public int[] minInterval(int[][] intervals, int[] queries) {
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));
        
        PriorityQueue<int[]> q = new PriorityQueue<>((a, b) -> {
            if (a[0] == b[0]) {
                return Integer.compare(a[1], b[1]);
            }
            return Integer.compare(a[0], b[0]);
        });

        Map<Integer, Integer> res = new HashMap<>();
        int i = 0;
        int intervalsLen = intervals.length;

        for (int que : Arrays.stream(queries).sorted().toArray()) {
            
            while (i < intervalsLen && intervals[i][0] <= que) {
                int l = intervals[i][0];
                int r = intervals[i][1];
                q.offer(new int[]{r - l + 1, r});
                i++;
            }

            while (!q.isEmpty() && q.peek()[1] < que) {
                q.poll();
            }

            res.put(que, q.isEmpty() ? -1 : q.peek()[0]);
        }

        int[] ans = new int[queries.length];
        for (int j = 0; j < queries.length; j++) {
            ans[j] = res.get(queries[j]);
        }

        return ans;
    }
}