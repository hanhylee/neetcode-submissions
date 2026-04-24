class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, vector<string>> anagrams;

        for (const auto& word: strs) {

            string sorted_word(word);
            sort(sorted_word.begin(), sorted_word.end());
            if (anagrams.find(sorted_word) == anagrams.end()) {
                anagrams[sorted_word] = {word};
            } else {
                anagrams[sorted_word].push_back(word);
            }
        }

        vector<vector<string>> ret;
        for (const auto& kv: anagrams) {
            vector<string> anagram_set = kv.second;
            ret.push_back(anagram_set);
        }

        return ret;
    }
};
