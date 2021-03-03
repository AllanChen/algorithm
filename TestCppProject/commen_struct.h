//
//  commen_struct.h
//  TestCppProject
//
//  Created by Allan Chan on 2021/1/21.
//

#ifndef commen_struct_h
#define commen_struct_h
#include <vector>
#include <stdio.h>
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),right(right) {}
};

struct ListNode_Pre {
    ListNode *pre;
    ListNode *next;
};


struct Node{
    int val;
    std::vector<Node *>children;
    Node() {}
    Node(int _val) { val = _val; }
    Node(int _val, std::vector<Node*> _children) { val = _val; children = _children;}
};


#endif /* commen_struct_h */
