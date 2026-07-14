class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128, 0);
        for (char c : t) map[c]++;
        
        int counter = t.size(); // How many characters we still need to match
        int begin = 0, end = 0;
        int minLen = INT_MAX, head = 0;
        
        while (end < s.size()) {
            // If this character is needed (count > 0), decrement counter
            if (map[s[end++]]-- > 0) {
                counter--;
            }
            
            // When all characters are matched
            while (counter == 0) {
                if (end - begin < minLen) {
                    minLen = end - begin;
                    head = begin;
                }
                
                // Try to shrink: if removing this character breaks the requirement
                if (map[s[begin++]]++ == 0) {
                    counter++; // We now need this character again
                }
            }
        }
        
        return minLen == INT_MAX ? "" : s.substr(head, minLen);
    }
};