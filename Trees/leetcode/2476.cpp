#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;

/**
  Definition for a binary tree node.
  */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
    public:
        // this approach will give O(n2) if the tree is skewed.
//        int findMin(TreeNode *root, int &target) {
//            static int greaterMin = -1;
//
//            if (!root) {
//                int temp = greaterMin;
//                greaterMin = -1;
//                return temp;
//            }
//
//            if(root->val > target) {
//                if(greaterMin != -1 && root->left && root->left->val < greaterMin) {
//                    int temp = greaterMin;
//                    greaterMin = -1;
//                    return temp;
//                }
//                return findMin(root->left, target);
//            }
//            else {
//                greaterMin = root->val;
//                return findMin(root->right, target);
//            }
//
//        }
//
//        int findMax(TreeNode *root, int &target) {
//            static int smallestMax = -1;
//
//            if (!root) {
//                int temp = smallestMax;
//                smallestMax = -1;
//                return temp;
//            }
//
//            if(root->val < target) {
//                if(smallestMax != -1 && root->right && root->right->val > smallestMax) {
//                    int temp = smallestMax;
//                    smallestMax = -1;
//                    return temp;
//                }
//                return findMax(root->right, target);
//            }
//
//            else {
//                smallestMax = root->val;
//                return findMax(root->left, target);
//            }
//        }
//
//        vector<vector<int>> closestNodes(TreeNode *root, vector<int> &queries) {
//            vector<vector<int>> result;
//            for (int query : queries) {
//                int min = findMin(root, query);
//                int max = findMax(root, query);
//                vector<int> res{min, max};
//                result.push_back(res);
//            }
//            return result;
//        }
        /**********Second Approch*********/
        void inOrder(TreeNode *root, vector<int> &sortedArray) {
            if(!root) {
                return;
            }
            inOrder(root->left, sortedArray);
            sortedArray.push_back(root->val);
            inOrder(root->right, sortedArray);
        }

        int findMin(vector<int> &sortedNodes, int start, int end, int &target) {
            static int greaterMin = -1;
            if(start > end) {
                int temp = greaterMin;
                greaterMin = -1;
                return temp;
            }

            int mid = start + (end - start) / 2;
            if(sortedNodes[mid] <= target) {
                greaterMin = max(greaterMin, sortedNodes[mid]);
                return findMin(sortedNodes, mid + 1, end, target);
            }
            else {
                return findMin(sortedNodes, start, mid - 1, target);
            }
        }
        int findMax(vector<int> &sortedNodes, int start, int end, int &target) {
            static int smallerMax = INT_MAX;
            if(start > end) {
                int temp = smallerMax;
                smallerMax = INT_MAX;
                return temp == INT_MAX ? -1 : temp;
            }

            int mid = start + (end - start) / 2;
            if(sortedNodes[mid] >= target) {
                smallerMax = min(smallerMax, sortedNodes[mid]);
                return findMax(sortedNodes, start, mid - 1, target);
            }
            else {
                return findMax(sortedNodes, mid + 1, end, target);
            }
        }


        vector<vector<int>> closestNodes(TreeNode *root, vector<int> &queries) {
            vector<int> sortedNodes;
            inOrder(root, sortedNodes);
            
            vector<vector<int>>result;
            for(auto query : queries) {
                int min = findMin(sortedNodes, 0, sortedNodes.size() - 1, query);
                int max = findMax(sortedNodes, 0, sortedNodes.size() - 1, query);
                vector<int> res{min, max};
                result.push_back(res);
            }
            return result;
        }
};
