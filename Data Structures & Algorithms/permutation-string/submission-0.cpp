class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if(s1.size() > s2.size()) return false;

        unordered_map<char, int> map1;
        unordered_map<char, int> map2;

        for(int i = 0; i < s1.size(); i++){
            map1[s1[i]]++; //a:1, b:1
            map2[s2[i]]++; //e:1, i:1
        }
        if(map1 == map2) return true;

        int left = 0;

        for(int right = s1.size(); right < s2.size(); right++){
            map2[s2[right]]++;
            map2[s2[left]]--;

            if(map2[s2[left]] == 0){
                map2.erase(s2[left]);
            }
            left++;

            if(map2 == map1) return true;
        }
        return false;
    }
};