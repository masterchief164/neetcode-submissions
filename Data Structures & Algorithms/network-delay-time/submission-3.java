class Solution {
    public int networkDelayTime(int[][] times, int n, int k) {
        // 1. Use an Array of Lists instead of a HashMap (Faster O(1) lookups)
        List<int[]>[] adj = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) {
            adj[i] = new ArrayList<>();
        }
        for (int[] edge : times) {
            adj[edge[0]].add(new int[]{edge[1], edge[2]});
        }

        // 2. Distance array to track the shortest time to each node
        int[] dist = new int[n + 1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[k] = 0;

        PriorityQueue<int[]> q = new PriorityQueue<>((a, b) -> Integer.compare(a[0], b[0]));
        q.offer(new int[]{0, k});

        // 3. Boolean array instead of HashSet (Faster and uses less memory)
        boolean[] vis = new boolean[n + 1];
        int visitedNodes = 0;
        int ans = 0;

        while (!q.isEmpty()) {
            int[] curr = q.poll();
            int time = curr[0];
            int node = curr[1];

            if (vis[node]) continue;
            
            vis[node] = true;
            visitedNodes++;
            ans = time; // Since it's a PQ, the last successfully visited node dictates the max time

            if (visitedNodes == n) return ans;

            for (int[] ne : adj[node]) {
                int nextNode = ne[0];
                int nextTime = time + ne[1];

                // PRUNING: Only add to the queue if we found a strictly shorter path
                if (nextTime < dist[nextNode]) {
                    dist[nextNode] = nextTime;
                    q.offer(new int[]{nextTime, nextNode});
                }
            }
        }
        
        return visitedNodes == n ? ans : -1;
    }
}