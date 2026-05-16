class Solution {
    public int carFleet(int target, int[] position, int[] speed) {
        int ans=1, n = position.length;
        double[][] times = new double[n][2];

        for(int i = 0;i<n;i++) {
            times[i][0] = position[i];
            times[i][1] = (target - position[i]) * 1.0/speed[i];
        }

        Arrays.sort(times, (a, b) -> {
            if(a[0] == b[0]) return Double.compare(b[1], a[1]);
            return Double.compare(b[0], a[0]);
        });
        double prevTime = times[0][1];

        for(int i = 1;i<n;i++) {
            double[] time = times[i];
            if(time[1] > prevTime) {
                ans++;
                prevTime = time[1];
            }
        }

        return ans;
    }
}
