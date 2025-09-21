class MovieRentingSystem {
    // price lookup
    unordered_map<long long, int> priceMap; // (shop, movie) -> price
    // unrented pool per movie
    unordered_map<int, set<pair<int,int>>> unrented; // movie -> {(price, shop)}
    // rented pool
    set<tuple<int,int,int>> rented; // {(price, shop, movie)}
    long long encode(int shop, int movie) {
        return ((long long)shop << 20) | movie; // pack into long long
    }
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &e : entries) {
            int shop = e[0], movie = e[1], price = e[2];
            priceMap[encode(shop, movie)] = price;
            unrented[movie].insert({price, shop});
        }
    }
    vector<int> search(int movie) {
        vector<int> res;
        if (unrented.count(movie)) {
            auto &s = unrented[movie];
            for (auto it = s.begin(); it != s.end() && res.size() < 5; ++it) {
                res.push_back(it->second); // shop
            }
        }
        return res;
    }
    void rent(int shop, int movie) {
        int price = priceMap[encode(shop, movie)];
        unrented[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }
    void drop(int shop, int movie) {
        int price = priceMap[encode(shop, movie)];
        rented.erase({price, shop, movie});
        unrented[movie].insert({price, shop});
    }
    vector<vector<int>> report() {
        vector<vector<int>> res;
        for (auto it = rented.begin(); it != rented.end() && res.size() < 5; ++it) {
            auto [price, shop, movie] = *it;
            res.push_back({shop, movie});
        }
        return res;
    }
};