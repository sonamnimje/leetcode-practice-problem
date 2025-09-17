class FoodRatings {
    struct cmp {
        bool operator()(const pair<int,string>& a, const pair<int,string>& b) const {
            if (a.first != b.first) return a.first > b.first;   // higher rating first
            return a.second < b.second;                         // lexicographically smaller first
        }
    };

    unordered_map<string, pair<string,int>> foodInfo; // food -> {cuisine, rating}
    unordered_map<string, set<pair<int,string>, cmp>> cuisineMap; // cuisine -> {rating, food}

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            foodInfo[foods[i]] = {cuisines[i], ratings[i]};
            cuisineMap[cuisines[i]].insert({ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        auto [cuisine, oldRating] = foodInfo[food];
        cuisineMap[cuisine].erase({oldRating, food});     // remove old
        cuisineMap[cuisine].insert({newRating, food});    // insert new
        foodInfo[food].second = newRating;                // update rating
    }
    
    string highestRated(string cuisine) {
        return cuisineMap[cuisine].begin()->second; // best food is at begin()
    }
};
