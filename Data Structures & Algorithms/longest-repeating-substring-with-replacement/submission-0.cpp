class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;

        int left = 0;
        int Maxlen = 0;
        int maxi = 0;

        for(int right = 0; right < s.size(); right++){
            count[s[right]]++;

            maxi = max(maxi, count[s[right]]);

            while(right - left + 1 - maxi > k){
                count[s[left]]--;
                left++;
            }
            Maxlen = max(Maxlen, right - left + 1);
        }
        return Maxlen;
    }
};
