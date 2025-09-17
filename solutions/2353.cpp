// 2353. Design a Food Rating System
class FoodRatings {
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i=0; i<foods.size(); ++i) {
            map[cuisines[i]].insert({ratings[i], foods[i]});
            foodInfo[foods[i]]={cuisines[i], ratings[i]};
        }
    }
    
    void changeRating(string food, int newRating) {
        map[foodInfo[food].first].erase({foodInfo[food].second, food});
        map[foodInfo[food].first].insert({newRating, food});
        foodInfo[food].second=newRating;
    }
    
    string highestRated(string cuisine) {
        return map[cuisine].rbegin()->second;
    }
private:
    unordered_map<string, set<pair<int, string>, decltype([] (const pair<int, string>& lhs, const pair<int, string>& rhs) { return lhs.first<rhs.first || (lhs.first==rhs.first && lhs.second>rhs.second); })>> map;
    unordered_map<string, pair<string, int>> foodInfo;
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */