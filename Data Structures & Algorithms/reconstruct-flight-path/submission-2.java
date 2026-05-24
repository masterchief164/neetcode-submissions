class Solution {
    public List<String> findItinerary(List<List<String>> tickets) {
        List<String> ans = new ArrayList<>();
        Map<String, PriorityQueue<String>> mp = new HashMap<>();

        for(List<String> ticket: tickets) {
            mp.computeIfAbsent(ticket.get(0), k -> new PriorityQueue<>()).offer(ticket.get(1));
        }

        dfs(mp, "JFK", ans);

        Collections.reverse(ans);

        return ans;
    }

    private void dfs(Map<String, PriorityQueue<String>> adj, String curr, List<String> ans) {
        PriorityQueue<String> q = adj.get(curr);
        
        while(q != null && !q.isEmpty()) {
            String next = q.poll();
            dfs(adj, next, ans);
        }
        
        ans.add(curr);
    }
}