class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;
        
        int wordLen = words[0].length();
        int numWords = words.size();
        int totalLen = wordLen * numWords;
        int sLen = s.length();
        
        if (sLen < totalLen) return result;
        
        // Create a frequency map of all target words
        unordered_map<string, int> wordCount;
        for (const string& word : words) {
            wordCount[word]++;
        }
        
        // Try each starting offset from 0 to wordLen-1
        for (int offset = 0; offset < wordLen; offset++) {
            int left = offset;
            int right = offset;
            int count = 0; // Number of valid words in current window
            unordered_map<string, int> windowCount;
            
            // Slide the window by wordLen
            while (right + wordLen <= sLen) {
                // Extract the current word
                string word = s.substr(right, wordLen);
                right += wordLen;
                
                // If the word is in our target list
                if (wordCount.count(word)) {
                    windowCount[word]++;
                    count++;
                    
                    // If we have too many of this word, shrink from left
                    while (windowCount[word] > wordCount[word]) {
                        string leftWord = s.substr(left, wordLen);
                        windowCount[leftWord]--;
                        count--;
                        left += wordLen;
                    }
                    
                    // If we have exactly the right number of words, record the index
                    if (count == numWords) {
                        result.push_back(left);
                    }
                } else {
                    // Invalid word encountered, reset the window
                    windowCount.clear();
                    count = 0;
                    left = right;
                }
            }
        }
        
        return result;
    }
};