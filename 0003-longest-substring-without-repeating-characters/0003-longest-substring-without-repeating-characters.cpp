#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> last_seen;
        int max_len = 0;
        int left = 0;
        
        for (int right = 0; right < s.length(); right++) {
            char c = s[right];
            // If character seen and is within current window, move left pointer
            if (last_seen.count(c) && last_seen[c] >= left) {
                left = last_seen[c] + 1;
            }
            last_seen[c] = right;
            max_len = max(max_len, right - left + 1);
        }
        
        return max_len;
    }
};