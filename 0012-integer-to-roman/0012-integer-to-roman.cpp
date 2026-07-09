class Solution {
public:
    string intToRoman(int num) {
        // We list all the possible Roman numeral values in descending order,
        // including the special subtractive cases (900, 400, 90, 40, 9, 4).
        vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        string result = "";
        
        // Iterate through the values from largest to smallest
        for (int i = 0; i < values.size() && num > 0; i++) {
            // While the current number is greater than or equal to the value
            while (num >= values[i]) {
                num -= values[i];         // Subtract the value
                result += symbols[i];     // Append the corresponding symbol
            }
        }
        
        return result;
    }
};