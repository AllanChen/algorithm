//
//  main.cpp
//  TestCppProject
//
//  Created by Allan Chan on 2021/1/17.
//

#include "string.h"
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <string>
#include <iterator>
#include <typeinfo>
#include <set>

#include "commen_struct.h"
#include "linked_list.h"
#include "string_algorithm.h"
#include "tree_travel.h"
//void reverseString(std::vector<char>& s) {
//    int left = 0;
//    int right = (int)s.size() -1;
//    while (right >0) {
//        if(right > left){
//            char temp_r = s[right];
//            char temp_l = s[left];
//            s[left] = temp_r;
//            s[right] = temp_l;
//
//        }
//        left  +=1;
//        right -=1;
//    }
//}

int numIdenticalPairs(std::vector<int>& nums) {
    int count = 0;
    std::vector<int> store;
    for (int i=0; i<nums.size(); i++){
        for (int j=0; j<nums.size(); j++){
            if(i != j){
                int head = nums[i];
                int tail = nums[j];
                int same = head ^ tail;
                if (same == 0){
                    count +=1;
                }
            }
        }
    }
    
    printf("count - %d", count/2);
    
    return 0;
}

//char * reverse( char * s ) {
//    int count = (int)strlen(s);
//    char result[count];
//    strcpy(result, s);
//    int left = 0;
//    int right = count-1;
//    while (right>=0) {
//        char right_str = s[right];
//        result[left] = right_str;
//        right -=1;
//        left +=1;
//    }
//
//    char *end = result;
//    return end;
//}


int test(int count){
    int sum = 0;
    if (count == 1) return count;
    sum = count + test(count-1);
    return sum;
}


int maxDepth_a(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    
    int left =  maxDepth_a(root->left) +1;
    int right =  maxDepth_a(root->right) +1;
    
    return 0;
}

int main(int argc, const char * argv[]) {
    Linked_List *newList = new Linked_List();
    ListNode *head1 = new ListNode(1);
    ListNode *head2 = new ListNode(2);
    ListNode *head3 = new ListNode(3);
    ListNode *head4 = new ListNode(4);
    ListNode *head5 = new ListNode(5);
//    ListNode *head6 = new ListNode(6);
    
    head1->next = head2;
    head2->next = head3;
    head3->next = head4;
    head4->next = head5;
    head5->next = NULL;
//    head6->next = NULL;
    
//    newList->getKthFromEnd(head1, 1);
//    newList->reverseList(head1);
//    reverseList_b(head1);
//    [1,2,2,3,3,null,null,4,4]
//    [3,9,20,null,null,15,7]
//    newList->traverse(head1);
    
    TreeNode *left = new TreeNode(2);
    TreeNode *right = new TreeNode(2);
    
    TreeNode *left_l = new TreeNode(3);
    TreeNode *left_r = new TreeNode(4);
    
    TreeNode *right_l = new TreeNode(5);
    TreeNode *right_r = new TreeNode(6);
    
//    left->left = left_l;
//    right->right = right_r;
//    left_l->left = right_l;
//    right_r->right = left_r;
    
    left->left = left_l;
    left->right = left_r;
//
//    left_l->left = right_l;
//    left_l->right = right_r;

    right->left = right_l;
//    right->right = right_r;
    
//    left_l->left = right_l;
//    left_r->right = right_r;
    
    Node *root_node = new Node(1);
    
    Node *root_node_3 = new Node(3);
    Node *root_node_2 = new Node(2);
    Node *root_node_4 = new Node(4);
    Node *root_node_5 = new Node(5);
    Node *root_node_6 = new Node(6);
    
    root_node->children.push_back(root_node_3);
    root_node->children.push_back(root_node_2);
    root_node->children.push_back(root_node_4);
    
    root_node_3->children.push_back(root_node_5);
    root_node_3->children.push_back(root_node_6);
    
    
//    TreeNode *root = new TreeNode(1,left,right);
    TreeTravel *tree = new TreeTravel();
    
    std::vector<int> result = tree->preorder(root_node);
//    tree->printBT("", root, false);
     
    
//    bool isBlancedTree = tree->isBalanced(root);
//    printf("is BlancedTree -- %d \n",isBlancedTree);
    
//    std::vector<std::vector<int>> result = tree->levelOrder(root);
//    tree->preorder(root);
    

    
    
//    maxDepth_a(root);
    char str[] = "hello";
//
//    String_Algorithm *string_algorithm = new String_Algorithm();
//    printf("%s",string_algorithm->reverse(str));
    
    
//    string_algorithm->

//    std::vector<char> input({ 'h', 'e', 'l','l', 'o'});
//    reverseString(input);
    
    
    std::vector<int> input ({1,2,3});
    numIdenticalPairs(input);
        
//    printf("%p\n",a);
//    printf("%p, %p\n",&str[0], &str[1]);
//    printf("%p\n",&str);
//    printf("%p\n",str);
//
//    printf("%p\n",&str_2);
//    printf("%p , %p \n",str_2[0], str_2[1]);
            
//    reverseString(str);
    
//    printf("%s", result);
//    std::cout << "Hello, World!\n";
    
    return 0;
}
