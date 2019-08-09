// part2至少从index=1的地方开始，或者是len-9，因为part2/part3/part4最多只有三位，所以最多后面留9位，再多就不是有效的了，所以从1和len-9中选择最大的，确保左边和右边的部分都有效才进行判断。然后最大不能超过 开始的index+3 和 len-2 的位置，因为part3/part4至少要有1位。
// 同理，part3至少index=part2+1的地方开始，或者是len-6，因为part3/part4最多只有三位，所以最多后面留9位。
// 同理for part4。
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        int len = s.length();
        if (len == 0 || len > 12)
            return res;
        int start = max(1, len-9);
        for (int p2 = start; p2 < min(start+3, len-2); ++p2) {
            if (isValid(s.substr(0, p2))) {
                start = max(p2+1, len-6);
                for (int p3 = start; p3 < min(start+3, len-1); ++p3) {
                    if (isValid(s.substr(p2, p3-p2))) {
                        start = max(p3+1, len-3);
                        for (int p4 = start; p4 < min(start+3, len); ++p4) {
                            if (isValid(s.substr(p3, p4-p3)) && isValid(s.substr(p4, len-p4))) {
                                res.push_back(s.substr(0, p2) + "." + s.substr(p2, p3-p2) + "." + s.substr(p3, p4-p3) + "." + s.substr(p4, len-p4));
                            }
                        }
                    }
                    
                }
            }
            
        }
        return res;
    }
    
    // 如果长度为2或者3，第一位不能是0。
    bool isValid(string s) {
        return s.length()==1 || (s[0] != '0' && s.length()==2) || (s[0] != '0' && stoi(s) <= 255);
    }
};