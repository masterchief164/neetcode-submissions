class CountSquares {

    private List<int[]> pnts;
    private Map<String, Integer> pntFreq;

    public CountSquares() {
        pnts = new ArrayList<>();
        pntFreq = new HashMap<>();
    }
    
    // Helper method to generate standard string keys
    private String getKey(int x, int y) {
        return x + "," + y;
    }
    
    public void add(int[] point) {
        pnts.add(point);
        String key = getKey(point[0], point[1]);
        pntFreq.put(key, pntFreq.getOrDefault(key, 0) + 1);
    }
    
    public int count(int[] point) {
        int ans = 0;
        int x = point[0];
        int y = point[1];
        
        for (int[] pnt : pnts) {
            int px = pnt[0];
            int py = pnt[1];

            // A valid diagonal means the x-distance equals the y-distance.
            // We also ensure x != px to avoid counting points with zero area.
            if (Math.abs(px - x) == Math.abs(py - y) && x != px) {
                
                String corner1 = getKey(x, py);
                String corner2 = getKey(px, y);
                
                // Multiply the frequencies of the other two required corners
                ans += pntFreq.getOrDefault(corner1, 0) * pntFreq.getOrDefault(corner2, 0);
            }
        }
        return ans;
    }
}