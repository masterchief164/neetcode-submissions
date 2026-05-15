class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) 
            swap(nums1, nums2);

        int l = 0, r = nums1.size();
        int half = (nums1.size() + nums2.size() + 1)/2;
        while(l<=r) {
            int i = (l+r)/2;
            int j = half - i;

            int la = i > 0?nums1[i-1]:INT_MIN;
            int lb = j > 0?nums2[j-1]:INT_MIN;
            int ra = i < nums1.size()? nums1[i]: INT_MAX;
            int rb = j < nums2.size()? nums2[j]: INT_MAX;

            if(la <= rb && lb <=ra) {
                if((nums1.size() + nums2.size())%2 == 0) return (max(la, lb) + min(ra, rb)) / 2.0;
                return max(la, lb);
            } else if(la > rb) {
                r = i -1;
            } else {
                l = i + 1;
            }
        }
        return -1;
    }
};
