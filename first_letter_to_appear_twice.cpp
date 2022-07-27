class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int> m(26, 0);
        for (int i = 0; i < s.size(); i++) 
            if (++m[s[i]-'a'] == 2) return s[i];
        return ' ';
    }
};