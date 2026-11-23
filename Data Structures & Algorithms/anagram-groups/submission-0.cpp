class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (const string& s : strs) {
            mp[strSort(s)].push_back(s);
        }
        
        vector<vector<string>> anagrams;
        anagrams.reserve(mp.size());
        for (auto& p : mp) { 
            anagrams.push_back(move(p.second));
        }
        return anagrams;
    }

private:
    string strSort(const string& s) {
        int counter[26] = {0};
        for (char c : s) {
            counter[c - 'a']++;
        }
        string t;
        t.reserve(s.size());
        for (int c = 0; c < 26; c++) {
            t.append(counter[c], c + 'a');
        }
        return t;
    }
};