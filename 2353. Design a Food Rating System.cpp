#include <vector>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;
class Obj
{
public:
    string food;
    string cuisine;
    int rate;

    Obj(string food, string cuisine, int rating) : food{std::move(food)}, cuisine{std::move(cuisine)}, rate{rating} {}

    bool operator<(const Obj &second) const
    {
        if (rate == second.rate)
            return food > second.food;
        return rate < second.rate;
    }
};

struct ObjComp
{
    bool operator()(const Obj *l, const Obj *r) const
    {
        return (*l) < (*r);
    }
};

class FoodRatings
{
public:
    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings)
    {
        for (int i = 0; i < foods.size(); i++)
        {
            Obj *obj = new Obj(foods[i], cuisines[i], ratings[i]);
            fmap[obj->food] = obj;
            cmap[obj->cuisine].insert(obj);
        }
    }

    void changeRating(const string &food, int newRating)
    {
        auto tmp = fmap[food];
        cmap[tmp->cuisine].erase(tmp);
        tmp->rate = newRating;
        cmap[tmp->cuisine].insert(tmp);
    }

    string highestRated(const string &cuisine)
    {
        return (*(cmap[cuisine].rbegin()))->food;
    }
    ~FoodRatings()
    {
        for (auto &[k, v] : fmap)
        {
            delete v;
        }
    }

private:
    // food -> {food,cusine,rating}
    unordered_map<string, Obj *> fmap;
    // cuisine -> set{food,cusine,rating}
    unordered_map<string, set<Obj *, ObjComp>> cmap;
};