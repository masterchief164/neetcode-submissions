class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        
        sort(hand.begin(), hand.end());
        unordered_map<int, int> freq;

        for(auto x: hand) {
            freq[x]++;
        }

        for(int x: hand) {
            if(freq[x] >0) {
                for(int i = x;i<x+groupSize; i++){
                    if(freq[i] == 0) return 0;
                    freq[i]--;
                }
            }
        }
        return 1;
    }
};
