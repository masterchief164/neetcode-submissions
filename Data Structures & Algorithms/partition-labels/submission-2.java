class Solution {
    public List<Integer> partitionLabels(String s) {
        Map<Character, Integer> idx = new HashMap<>();
        List<Integer> ans = new ArrayList<>();

        int size = 0;
        int end = 0;

        for(int i = 0;i<s.length();i++) {
            idx.put(s.charAt(i), i);
        }

        for(int i = 0;i<s.length();i++) {
            size++;
            end = Math.max(end, idx.get(s.charAt(i)));


            if(i==end) {
                ans.add(size);
                size = 0;
                end++;
            }
        }
        return ans;
    }
}
