class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st;
        for (int x : nums) {
            st.push_back(x);
            while (st.size() > 1) {
                int a = st.back(), b = st[st.size()-2];
                int g = gcd(a, b);
                if (g == 1) break;   // coprime, stop merging
                long long l = 1LL * a / g * b; // compute lcm safely
                st.pop_back(); st.pop_back();
                st.push_back((int)l);
            }
        }
        return st;
    }
};