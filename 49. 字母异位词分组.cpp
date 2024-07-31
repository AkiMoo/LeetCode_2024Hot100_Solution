vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string,vector<string>> hash;
    int n = strs.size();
    for(int i = 0;i<n;i++){
        string temp = strs[i];
        sort(temp,temp.length());
        hash[temp].push_back(strs[i]);
    }
    vector<vector<string>> ans;
    for(auto it = hash.begin();it!=hash.end();it++){
        ans.push_back(it->second);
    }
    return ans;
}
