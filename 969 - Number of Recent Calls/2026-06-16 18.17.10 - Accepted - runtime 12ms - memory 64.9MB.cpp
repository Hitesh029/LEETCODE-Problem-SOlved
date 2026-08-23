class RecentCounter {
public:
    vector<int> times;

    RecentCounter() {}

    int ping(int t)
    {
        times.push_back(t);

        int idx =
            lower_bound(
                times.begin(),
                times.end(),
                t - 3000
            ) - times.begin();

        return times.size() - idx;
    }
};