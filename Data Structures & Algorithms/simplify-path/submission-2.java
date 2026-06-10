class Solution {
    public String simplifyPath(String path) {
        String[] paths = path.split("/");
        Stack<String> stk = new Stack<>();
        for(String p: paths) {
            if(p.equals("..")) {
                if(stk.size()>0)
                    stk.pop();
                continue;
            } else if(p.length() == 0 || p.equals("."))
                continue;
            stk.push(p);
        }
        return "/" + String.join("/", stk);
    }
}