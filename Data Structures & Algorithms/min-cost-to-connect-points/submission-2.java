class Solution {
    public int minCostConnectPoints(int[][] points) {
        int cost = 0, curr = 0, n = points.length;
        boolean[] vis = new boolean[n];
        int[] dis = new int[n];
        Arrays.fill(dis, (int)1e7);
        int cnt = 0;

        while(cnt < n - 1) {
            vis[curr] = true;
            int next = -1;
            for(int i = 0;i<n;i++) {
                if(vis[i]) continue;

                int disC = Math.abs(points[i][0]-points[curr][0]) + Math.abs(points[i][1] - points[curr][1]);
                dis[i] = Math.min(dis[i], disC);

                if(next == -1 || dis[i] < dis[next]) {
                    next = i;
                }
            }
            cost+=dis[next];
            curr = next;
            cnt++;
        }
        return cost;
    }
}
