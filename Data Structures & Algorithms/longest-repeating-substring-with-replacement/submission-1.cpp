class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> map;

        int Maxlen = 0;
        int left = 0;
        int longest = 0;

        for(int right = 0; right < s.size(); right++){
            map[s[right]]++;
            longest = max(longest, map[s[right]]);

            if(right - left + 1 - longest > k){
                map[s[left]]--;
                left++;
            }
            Maxlen = max(Maxlen, right - left + 1);
        }
        return Maxlen;
    }
};