class Solution {
public:
    vector<string> spellchecker(vector<string>& W, vector<string>& Q) {
        auto low=[](string s){for(char &c:s)c=tolower(c);return s;};
        auto dev=[](string s){for(char &c:s) if(string("aeiou").find(c)!=string::npos) c='*';return s;};
        
        unordered_set<string> exact(W.begin(),W.end());
        unordered_map<string,string> caseMap,vowelMap;
        for(string w:W){ string l=low(w), d=dev(l); caseMap.insert({l,w}); vowelMap.insert({d,w}); }
        
        vector<string> ans;
        for(string q:Q){
            if(exact.count(q)) ans.push_back(q);
            else if(caseMap.count(low(q))) ans.push_back(caseMap[low(q)]);
            else if(vowelMap.count(dev(low(q)))) ans.push_back(vowelMap[dev(low(q))]);
            else ans.push_back("");
        }
        return ans;
    }
};