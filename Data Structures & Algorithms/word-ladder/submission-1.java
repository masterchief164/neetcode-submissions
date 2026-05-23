class Solution {
    public int ladderLength(String startWord, String endWord, List<String> wordList) {
        Set<String> words = new HashSet<String>(wordList);
        if(!words.contains(endWord)) {
            return 0;
        }

        int ans = 0;
        Queue<String> q = new LinkedList<>();
        q.offer(startWord);
        words.remove(startWord);

        while(!q.isEmpty()) {
            ans++;
            int s = q.size();
            for(int j = 0;j<s;j++){
                String curr = q.poll();
                if(curr.equals(endWord)) return ans;
                for(int i = 0;i<curr.length();i++) {
                    for(char c = 'a'; c<='z';c++) {
                        String newWord = curr.substring(0, i) + c + curr.substring(i+1);
                        if(words.contains(newWord)) {
                            q.offer(newWord);
                            words.remove(newWord);
                        }
                    }
                }
            }
        }
        return 0;
    }
}
