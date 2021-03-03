//
//  tree_travel.cpp
//  TestCppProject
//
//  Created by Allan Chan on 2021/1/22.
//

#include "tree_travel.h"
#include <iostream>
#include <stack>

void loopTree_back(Node *root, int index, std::vector<int> &result);

void loopBT(Node *root, TreeNode *treeNode);

void loopBTree_LR(TreeNode *treeNode, std::vector<int> &mark);

// 遍历二叉树 -- 递归
void TreeTravel::traverse(TreeNode* root){
    if(root !=nullptr){
        traverse(root->left);
        traverse(root->right);
    }
}

// 遍历二叉树 -- 迭代写法
std::vector<int> traverses(TreeNode *root){
    std::vector<int> res;
    if(root == nullptr){
        return res;
    }
    std::stack<TreeNode*> stk;

    TreeNode *node = root;

    while (!stk.empty() || node != nullptr) {
        while (node != nullptr) {
            res.emplace_back(node->val);
            stk.emplace(node);
            node = node->left;
        }
        node = stk.top();
        stk.pop();
        node = node->right;
    }
    return res;
}



//最深二叉树
int TreeTravel::maxDepth(TreeNode* root){
    if(root == nullptr){
        return 0;
    }
    int left = maxDepth(root->left) + 1;
    int right = maxDepth(root->right) + 1;
    int result = std::max(left, right);
    return result;
}



// 判断是否是高度平衡二叉树
// Question :
// 1 :why need the condition of isBalanced ??
// 2 :what is the Balanced Binary Tree ??

bool TreeTravel::isBalanced(TreeNode *root){
    int leftMaxDepth = this->maxDepth(root->left);
    int rightMaxDepth = this->maxDepth(root->right);
    bool result = abs(leftMaxDepth - rightMaxDepth) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    return result;
}

//从上到下打印二叉树
std::vector<std::vector<int>> TreeTravel::levelOrder(TreeNode *root){
    std::vector<std::vector<int>> result;
    std::map<int, std::vector<int>> layer_map;
    if(root != nullptr){
        int index = 0;
        this->loopTree(root,index, layer_map);
        for(int i=0; i< layer_map.size(); i++){
            result.push_back(layer_map[i]);
        }
    }

    return result;
}

void TreeTravel::loopTree(TreeNode *root, int index, std::map<int, std::vector<int>> &map){
    if(root != nullptr){
        map[index].push_back(root->val);
        index++;
        loopTree(root->left,index, map);
        loopTree(root->right,index, map);

    }
}


//N叉树的前序遍历
std::vector<int> TreeTravel::preorder(Node* root, std::vector<int> &result) {
    if(root !=nullptr){
        result.push_back(root->val);
        for(int i=0; i < root->children.size(); i++){
            preorder(root->children[i],result);
        }
        return result;
    }
    return  result;
}


//递增顺序查找树
/*
 Input:
           5
         /   \
        3     7
       / \   / \
      2   4 6   8

 Output: 2 3 4 5 6 7 8
 **/
TreeNode* TreeTravel::increasingBST(TreeNode* root){

    std::vector<int> result;
    loopBTree_LR(root, result);
    std::vector<TreeNode *>treeNodeVector;
    int index = 0;
    int mark = int (result.size());
    while (mark>0) {
        TreeNode *newRoot = new TreeNode();
        newRoot->val = result[index];
        if(index>0){
            treeNodeVector[index-1]->right = newRoot;
        }
        treeNodeVector.push_back(newRoot);
        mark --;
        index ++ ;
    }
    return treeNodeVector[0];
}

void loopBTree_LR(TreeNode *treeNode, std::vector<int> &result){
    if(treeNode != nullptr){
        loopBTree_LR(treeNode->left, result);
        result.push_back(treeNode->val);
        loopBTree_LR(treeNode->right, result);
    }
}

TreeNode* TreeTravel::buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {

    int root = postorder[postorder.size()-1];

    std::vector<int>::iterator it_inorder = std::find(inorder.begin(), inorder.end(), root);
    int root_position = int (it_inorder - inorder.begin());

    std::vector<int>left_inorder, right_inorder;
    for(int i=0; i< root_position; i++){
        left_inorder.push_back(inorder[i]);
    }
    for(int i = root_position + 1; i<inorder.size(); i++){
        right_inorder.push_back(inorder[i]);
    }

    std::vector<int>left_postorder, right_postorder;
    for(int i=0; i< root_position; i++){
        left_postorder.push_back(postorder[i]);
    }
    for(int i = root_position; i<inorder.size()-1; i++){
        right_postorder.push_back(postorder[i]);
    }

    TreeNode *root_node = new TreeNode(root);


    for (int i= int(right_postorder.size()); i==0; i--){
//        root_node->right->val = right_inorder[i];
    }

    return new TreeNode();
}


//打印二叉树
void TreeTravel::printBT(const std::string& prefix, const TreeNode* node, bool isLeft)
{
    if( node != nullptr )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        std::cout << node->val << std::endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
        printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}

