class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int n = words.size();
        int i = 0; // Pointer to the start of the current line's words
        
        while (i < n) {
            int j = i;
            int lineLen = 0;
            
            // Phase 1: Greedily find how many words fit in the current line
            // (j - i) represents the minimum 1 space needed between the words we've picked so far
            while (j < n && lineLen + words[j].length() + (j - i) <= maxWidth) {
                lineLen += words[j].length();
                j++;
            }
            
            int numWords = j - i;
            int totalSpaces = maxWidth - lineLen;
            string line = "";
            
            // Phase 2: Format the line
            // Case A: Last line OR a line with only one word (Left-Justified)
            if (j == n || numWords == 1) {
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k != j - 1) line += " "; // Single space between words
                }
                // Pad the rest of the line with spaces
                line += string(maxWidth - line.length(), ' ');
            } 
            // Case B: Normal line (Fully Justified)
            else {
                int gaps = numWords - 1;
                int spacesPerGap = totalSpaces / gaps;
                int extraSpaces = totalSpaces % gaps;
                
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k != j - 1) { // Don't add spaces after the very last word
                        int spacesToApply = spacesPerGap + (extraSpaces > 0 ? 1 : 0);
                        line += string(spacesToApply, ' ');
                        extraSpaces--; // Distribute extra spaces to the leftmost gaps first
                    }
                }
            }
            
            res.push_back(line);
            i = j; // Move to the next batch of words
        }
        
        return res;
    }
};