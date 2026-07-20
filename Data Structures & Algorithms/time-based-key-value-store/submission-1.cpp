class TimeMap {
   public:
    unordered_map<string, map<int,string>> tMap;
    TimeMap() {}

    void set(string key, string value, int timestamp) { 
        tMap[key][timestamp] = value; 
    }

    string get(string key, int timestamp) { 
        auto it = tMap[key].upper_bound(timestamp);
        if (it == tMap[key].begin()) return "";
        it--;
        return  it->second;
    }
};
