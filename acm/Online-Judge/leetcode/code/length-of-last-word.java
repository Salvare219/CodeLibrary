class Solution {
    Solution(){}
    public int lengthOfLastWord(String s) {
        String c=s.trim();
        return c.length()-c.lastIndexOf(' ')-1;
    }
}