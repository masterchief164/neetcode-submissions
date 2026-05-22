class Solution {
    private static final String[] KEYPAD = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    public List<String> letterCombinations(String digits) {
        // LinkedList operates as our Queue and our final return List
        LinkedList<String> queue = new LinkedList<>();
        
        if (digits == null || digits.isEmpty()) {
            return queue;
        }
        
        // Seed the queue with an empty string to start the process
        queue.add("");
        
        for (int i = 0; i < digits.length(); i++) {
            int digit = digits.charAt(i) - '0';
            String letters = KEYPAD[digit];
            
            // Process only the strings built from the PREVIOUS digits
            while (queue.peek().length() == i) {
                String prefix = queue.remove(); // Dequeue the prefix
                
                for (char c : letters.toCharArray()) {
                    queue.add(prefix + c);      // Enqueue the new combinations
                }
            }
        }
        
        return queue;
    }
}