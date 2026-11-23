class Solution {
public:
    string encode(const vector<string>& strs) {
        string encoded;
        for (const string& s : strs) {
            encoded += to_string(s.size()) + "#" + s;
        }
        return encoded;
    }

    vector<string> decode(const string& s) {
        vector<string> decoded;
        size_t i = 0;
        
        while (i < s.size()) {
            size_t j = s.find('#', i);
            int length = stoi(s.substr(i, j - i));
            size_t start = j + 1;
            
            decoded.push_back(s.substr(start, length));
            i = start + length;
        }
        return decoded;
    }
};
