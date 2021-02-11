//
//  tree_travel.cpp
//  TestCppProject
//
//  Created by Allan Chan on 2021/1/22.
//

#include "tree_travel.h"
#include <iostream>


void loopTree_back(Node *root, int index, std::vector<int> &result);

TreeTravel::TreeTravel(){
    
}

TreeTravel::~TreeTravel(){
    
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


// 遍历二叉树
void TreeTravel::traverse(TreeNode* root){
    if(root !=nullptr){
        traverse(root->left);
        traverse(root->right);
    }
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
    if(root != nullptr){
        int index = 0;
        this->loopTree(root->left,index);
        this->loopTree(root->right,index);
        this->m[index].push_back(root->val);
        for(int i=0; i<this->m.size(); i++){
            result.push_back(this->m[i]);
        }
    }
    
    return result;
}

void TreeTravel::loopTree(TreeNode *root, int index){
    if(root != nullptr){
        index++;
        this->m[index].push_back(root->val);
        loopTree(root->left,index);
        loopTree(root->right,index);
    }
}

void loopTree_back(std::vector<Node *>children, int index, std::vector<int> &result){
    if(children.size() > 0){
        for(int i=0; i<children.size(); i++){
            result.push_back(children[i]->val);
            if(children[i]->children.size()>0)
                loopTree_back(children[index]->children,index,result);
        }
        
        index ++;
    }
}
std::vector<int> result;
std::vector<int> TreeTravel::preorder(Node* root) {
    if(root !=nullptr){
        if(result.size() == 0)
            result.push_back(root->val);
        
        if(root->children.size() > 0){
            for(int i=0; i<root->children.size(); i++){
                result.push_back(root->children[i]->val);
                if(root->children[i]->children.size()>0)
                    preorder(root->children[i]);
            }
        }
        return result;
    }
    return result;
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

