class Solution {
    public boolean isNStraightHand(int[] hand, int groupSize) {
        if(hand.length %groupSize != 0) return false;
        Arrays.sort(hand);

        Map<Integer, Integer> freq = new HashMap<>();

        for(int n: hand) {
            freq.put(n, freq.getOrDefault(n,0)+1);
        }

        for(int n: hand) {
            if(freq.get(n) > 0) {
                for(int i = n;i<n+groupSize;i++) {
                    if(freq.getOrDefault(i, 0) == 0) return false;
                    freq.put(i, freq.get(i)-1);
                }
            }
        }
        return true;
    }
}
