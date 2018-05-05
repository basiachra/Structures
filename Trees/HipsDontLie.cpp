//
// Created by Karolina on 05.05.2018.
//
//https://www.geeksforgeeks.org/remove-all-nodes-which-lie-on-a-path-having-sum-less-than-k/
//Given a binary tree, a complete path is defined as a path from root to a leaf.
//The sum of all nodes on that path is defined as the sum of that path. Given a number K, you have to
//remove (prune the tree) all nodes which don’t lie in any path with sum>=k.
//
//Note: A node can be part of multiple paths. So we have to delete it only
//in case when all paths from it have sum less than K.