class Solution {
public:
    vector<int> partitionLabels(string S) {
        int pos[26] = {0};
        int i = 0;
        for (i = 0; i < S.length(); ++i) {
            pos[S[i]-'a'] = i;
        }
        
        i = 0;
        int farest = pos[S[0]-'a'], start = 0;
        vector<int> res;
        while (i < S.length()) {
            while (i < farest) {
                ++i;
                farest = max(farest, pos[S[i]-'a']);
            }
            res.push_back(i-start+1);
            if (i < S.length()-1) {
                ++i;
                farest = pos[S[i]-'a'];
                start = i;
            } else {
                break;
            }
        }
        
        return res;
    }
};