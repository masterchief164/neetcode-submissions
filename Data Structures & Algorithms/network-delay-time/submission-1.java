class Solution {
    public int networkDelayTime(int[][] times, int n, int k) {
        Map<Integer, List<int[]>> adj = new HashMap<>();
        Set<Integer> vis = new HashSet<>();
        int ans = 0;

        for(int[] edge: times) {
            adj.computeIfAbsent(edge[0], x-> new ArrayList<>()).add(new int[]{edge[1], edge[2]});
        }
        
        PriorityQueue<int[]> q = new PriorityQueue<>((a, b)-> Integer.compare(a[0],b[0]));
        q.offer(new int[]{0, k});

        while(!q.isEmpty()) {
            int[] curr = q.poll();
            if(vis.size() == n) return ans;
            if(vis.contains(curr[1])) continue;
            ans = Math.max(ans, curr[0]);
            vis.add(curr[1]);

            if (adj.containsKey(curr[1])) {
                for(int[] ne: adj.get(curr[1])) {
                    q.offer(new int[] {curr[0]+ ne[1], ne[0]});
                }
            }
        }
        return vis.size() == n ? ans : -1;
    }
}
