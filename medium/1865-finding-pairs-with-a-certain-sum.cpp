/**
 * @file 1865-finding-pairs-with-a-certain-sum.cpp
 * @author Perry Huang
 * @date 2025-07-06
 */

#include <vector>
#include <unordered_map>

class FindSumPairs {
   public:
    FindSumPairs(std::vector<int>& nums1, std::vector<int>& nums2) : nums1(nums1), nums2(nums2) {
        for (int i : nums2) {
            if (freqs.find(i) == freqs.end()) {
                freqs[i] = 1;
            } else {
                ++freqs[i];
            }
        }
    }

    void add(int index, int val) {
        --freqs[nums2[index]];
        nums2[index] += val;
        ++freqs[nums2[index]];
    }

    int count(int tot) {
        int res = 0;
        for (int i : nums1) {
            res += freqs[tot - i];
        }
        return res;
    }

   private:
    std::vector<int> nums1;
    std::vector<int> nums2;
    std::unordered_map<int, int> freqs; // frequencies for nums 2
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
