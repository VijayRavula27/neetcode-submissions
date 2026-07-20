class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int, char> smap;
        unordered_map<int, char> tmap;

        if(s.size() != t.size()) return false;

        for(int i = 0; i < s.size(); i++){
            smap[s[i]]++;
        }
        for(int i = 0; i < t.size(); i++){
            tmap[t[i]]++;
        }
        return smap == tmap;
    }
};
