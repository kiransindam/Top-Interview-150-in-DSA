class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_tank = 0;      // Tracks the global sum of (gas - cost)
        int current_tank = 0;    // Tracks the gas in the tank for the current potential start
        int starting_station = 0; // Our candidate for the unique starting point
        
        for (int i = 0; i < gas.size(); i++) {
            int net_gas = gas[i] - cost[i];
            
            total_tank += net_gas;
            current_tank += net_gas;
            
            // If we run out of gas before reaching the next station
            if (current_tank < 0) {
                // The current starting_station is invalid.
                // Any station between starting_station and i is also invalid.
                // So, the next possible candidate is i + 1.
                starting_station = i + 1;
                current_tank = 0; // Reset the tank for the new candidate
            }
        }
        
        // If the total gas is enough to cover the total cost, a solution exists.
        // Because the problem guarantees a unique solution, the starting_station we found is the answer.
        return total_tank >= 0 ? starting_station : -1;
    }
};