/**
 * @file 1233-remove-sub-folders-from-the-filesystem.cpp
 * @author Perry Huang
 * @date 2025-07-18
 * 1233. Remove Sub-Folders from the Filesystem
 * Given a list of folders folder, return the folders after removing all sub-folders in those folders. You may return
 * the answer in any order. If a folder[i] is located within another folder[j], it is called a sub-folder of it. A
 * sub-folder of folder[j] must start with folder[j], followed by a "/". For example, "/a/b" is a sub-folder of "/a",
 * but "/b" is not a sub-folder of "/a/b/c". The format of a path is one or more concatenated strings of the form: '/'
 * followed by one or more lowercase English letters. For example, "/leetcode" and "/leetcode/problems" are valid paths
 * while an empty string and "/" are not.
 */

#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

std::vector<std::string> removeSubfolders(std::vector<std::string>& folder) {
    auto comp = [](const std::string& a, const std::string& b) {
        return a.size() < b.size();
    };
    std::sort(folder.begin(), folder.end(), comp);
    std::unordered_set<std::string> directories;
    std::vector<std::string> res;
    for (const std::string& path : folder) {
        std::string currPath = "";
        for (char c : path) {
            if (c == '/') {
                if (directories.find(currPath) != directories.end()) {
                    break;
                }
            }
            currPath += c;
        }
        if (directories.find(currPath) == directories.end()) {
            directories.insert(currPath);
            res.push_back(currPath);
        }
    }
    return res;
}
