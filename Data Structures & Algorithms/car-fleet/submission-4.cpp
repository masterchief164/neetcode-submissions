class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> cars;

        for(int i = 0;i<n;i++) {
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.begin(), cars.end(), greater());

        double prev = (1.0)*(target - cars[0].first) / cars[0].second;
        int ans = 1;

        for(int i = 1; i<n; i++)  {
            double time = (1.0)*(target - cars[i].first) / cars[i].second;
            if(time > prev) {
                prev = time;
                ans++;
            }
        }
        return ans;
    }
};
 