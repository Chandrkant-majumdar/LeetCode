class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        vector<string> v1;
        vector<string> v2;
        
        stringstream ss1(s1);
        string word;
        while (ss1 >> word) {
            v1.push_back(word);
        }
        
        stringstream ss2(s2);
        while (ss2 >> word) {
            v2.push_back(word);
        }
        
        if (v2.size() > v1.size()) {
            swap(v1, v2);
        }
        
        int e1 = 0;
        int e2 = 0;
        
        while (e1 < v2.size() && v1[e1] == v2[e1]) e1++;
        
        while (e2 < v2.size() - e1 && v1[v1.size() - e2 - 1] == v2[v2.size() - e2 - 1]) e2++;
        
        return e1 + e2 >= v2.size();
    }
};