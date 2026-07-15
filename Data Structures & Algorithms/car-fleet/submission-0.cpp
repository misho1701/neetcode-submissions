class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> cars;

        int n = position.size();

        for (int i = 0; i < n; i++) {

            double time = (double)(target - position[i]) / speed[i];

            cars.push_back({position[i], time});
        }

        sort(cars.begin(), cars.end(),
             [](pair<int,double>& a, pair<int,double>& b) {
                 return a.first > b.first;
             });


        vector<double> fleets;

        for (auto& car : cars) {

            double time = car.second;

            if (fleets.empty() || time > fleets.back()) {
                fleets.push_back(time);
            }
        }


        return fleets.size();
    }
};
