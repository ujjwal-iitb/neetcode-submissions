class Solution {
public:

    bool validSubstring(unordered_map<char, int>& s_map,
                        unordered_map<char, int>& t_map) {
        for (auto i : t_map) {
            if (s_map[i.first] < t_map[i.first]) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        int start = 0, end = -1, curr = -1;
        int v_start = 0, v_end = s.length() - 1;

        unordered_map<char, int> s_map, t_map;

        // Build t frequency map
        for (char c : t) {
            t_map[c]++;
        }

        // Initial feasibility check
        for (char c : s) {
            s_map[c]++;
        }

        if (validSubstring(s_map, t_map)) {
            curr = s.length();
        } else {
            return "";
        }

        s_map.clear();

        // Sliding window
        while (end < (int)s.length()) {
            cout << "Start -> " << start << ", End -> " << end << endl;

            if (validSubstring(s_map, t_map)) {
                cout << "valid substr found" << endl;

                if (end - start + 1 < curr) {
                    v_start = start;
                    v_end = end;
                    curr = end - start + 1;
                }

                s_map[s[start]]--;
                start++;
            } else {
                end++;
                if (end < (int)s.length()) {
                    s_map[s[end]]++;
                }
            }
        }

        return s.substr(v_start, v_end - v_start + 1);
    }
};
