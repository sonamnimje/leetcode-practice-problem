class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
         int n = energy.size();

        // Traverse from the back (right to left)
        for (int i = n - k - 1; i >= 0; --i) {
            energy[i] += energy[i + k];
        }

        // Find the maximum possible energy
        return *max_element(energy.begin(), energy.end());
    }
};