/**
 * @file 1865-finding-pairs-with-a-certain-sum.cpp
 * @author Perry Huang
 * @date 2025-07-06
 */

#include <unordered_map>
#include <vector>

class FindSumPairs {
   public:
    FindSumPairs(std::vector<int>& nums1, std::vector<int>& nums2) : nums1(nums1), nums2(nums2) {
        for (int i : nums1) {
            if (freqs1.find(i) == freqs1.end()) {
                freqs1[i] = 1;
            } else {
                ++freqs1[i];
            }
        }
        for (int i : nums2) {
            if (freqs2.find(i) == freqs2.end()) {
                freqs2[i] = 1;
            } else {
                ++freqs2[i];
            }
        }
    }

    void add(int index, int val) {
        --freqs2[nums2[index]];
        nums2[index] += val;
        ++freqs2[nums2[index]];
    }

    int count(int tot) {
        int res = 0;
        for (const std::pair<int, int>& p : freqs1) {
            if (freqs2.find(tot - p.first) != freqs2.end()) {
                res += p.second * freqs2[tot - p.first];
            }
        }
        return res;
    }

   private:
    std::vector<int> nums1;
    std::vector<int> nums2;
    std::unordered_map<int, int> freqs1;
    std::unordered_map<int, int> freqs2;
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
