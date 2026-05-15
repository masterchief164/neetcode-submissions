class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int maxF = 0;
        char maxC = 'a';
        unordered_map<char, int> freq;

        for(auto x: tasks) {
            freq[x]++;
            if(maxF < freq[x])  {
                maxF = max(maxF, freq[x]);
                maxC  = x;
            }
        }

        int idle = (maxF - 1) * n;
        freq.erase(maxC);

        for(auto x: freq) {
            idle -= min(maxF - 1, x.second);
        }

        return max(0, idle) + tasks.size();
    }
};
