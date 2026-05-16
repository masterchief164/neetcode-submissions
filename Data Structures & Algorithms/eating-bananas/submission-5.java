class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int r = Arrays.stream(piles).max().getAsInt(), l = 0, ans= Integer.MAX_VALUE;

        while(l<=r) {
            int k = l + (r-l)/2;
            int time = checkTime(piles, k);

            if(time > h) {
                l = k +1;
            } else {
                ans = Math.min(k, ans);
                r = k -1;
            }
        }
        return ans;
    }

    int checkTime(int []piles, int rate) {
        int time = 0;
        for(int pile: piles) {
            time+=Math.ceil(pile*1.0/rate);
        }
        return time;
    }
}
