class Solution {
    public record Flight(int cost, int k, int src) {}

    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int maxK) {
        PriorityQueue<Flight> q = new PriorityQueue<>((a, b) -> Integer.compare(a.cost, b.cost));
        Map<Integer, List<int[]>> adj = new HashMap<>();

        for(int[] flight: flights) {
            adj.computeIfAbsent(flight[0], t -> new ArrayList<>()).add(new int[] {flight[1], flight[2]});
        }

        int[] minStops = new int[n];
        Arrays.fill(minStops, Integer.MAX_VALUE);

        q.offer(new Flight(0, 0, src));
        
        while(!q.isEmpty()) {
            Flight f = q.poll();
            
            if(f.src == dst) return f.cost;
            
            if (minStops[f.src] <= f.k) {
                continue;
            }
            minStops[f.src] = f.k;
            
            if(adj.containsKey(f.src)) {
                for(int[] next: adj.get(f.src)) {
                    if(f.k > maxK) {
                        continue;
                    }
                    q.offer(new Flight(f.cost + next[1], f.k + 1, next[0]));
                }
            }
        }
        
        return -1;
    }
}