// https://leetcode.com/contest/weekly-contest-424/problems/make-array-elements-equal-to-zero/

class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int ans = 0;
        set<int> stt;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                stt.insert(i);
            }
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                {
                    vector<int> tmp = nums;
                    set<int> st = stt;
                    int idx = i;
                    int direct = -1;
                    while (idx >= 0 && idx < tmp.size()) {
                        if (tmp[idx] != 0) {
                            if (--tmp[idx] == 0) {
                                st.insert(idx);
                            }
                            direct *= -1;
                        }
                        idx += direct;
                    }
                    
                    if (st.size() == tmp.size()) {
                        ans++;
                    }
                }

                {
                    vector<int> tmp = nums;
                    set<int> st = stt;
                    int idx = i;
                    int direct = 1;
                    while (idx >= 0 && idx < tmp.size()) {
                        if (tmp[idx] != 0) {
                            if (--tmp[idx] == 0) {
                                st.insert(idx);
                            }
                            direct *= -1;
                        }
                        idx += direct;
                    }
                    
                    if (st.size() == tmp.size()) {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};
