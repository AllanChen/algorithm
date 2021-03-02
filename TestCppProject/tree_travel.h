//
//  tree_travel.hpp
//  TestCppProject
//
//  Created by Allan Chan on 2021/1/22.
//

#ifndef tree_travel_hpp
#define tree_travel_hpp

#include <stdio.h>
#include <string>
#include "commen_struct.h"
#include <map>
#include <vector>

class TreeTravel {
    std::vector<std::vector<int> > results;
public:
    TreeTravel();
    ~TreeTravel();
    int maxDepth(TreeNode* root);
    void traverse(TreeNode* root);
    bool isBalanced(TreeNode *root);
    
    void loopTree(TreeNode *root, int index, std::map<int, std::vector<int> > &map);
    std::vector<std::vector<int> > levelOrder(TreeNode* root);
        
    std::vector<int> preorder(Node* root, std::vector<int> &result);
    
    TreeNode* increasingBST(TreeNode* root);
    
    TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder);
    
    void printBT(const std::string& prefix, const TreeNode* node, bool isLeft);
    
};
#endif /* tree_travel_hpp */
