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
#include <stack>
#include "commen_struct.h"
#include "linked_list.h"
#include "string_algorithm.h"
#include "tree_travel.h"
#include "tress.h"
#include "Tress_test.h"

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


//vector<int> res;
//       if (root == nullptr) {
//           return res;
//       }
//
//       stack<TreeNode*> stk;
//       TreeNode* node = root;
//       while (!stk.empty() || node != nullptr) {
//           while (node != nullptr) {
//               res.emplace_back(node->val);
//               stk.emplace(node);
//               node = node->left;
//           }
//           node = stk.top();
//           stk.pop();
//           node = node->right;
//       }
//       return res;
//   }



std::vector<int> treeTravel(TreeNode *root){
    std::vector<int> res;
    if(root == nullptr){
        return res;
    }
    std::stack<TreeNode*> stk;
    
    TreeNode *node = root;
    
    while (!stk.empty() || node != nullptr) {
        while (node != nullptr) {
//            res.emplace_back(node->val);
            stk.emplace(node);
            node = node->left;
        }
        node = stk.top();
        stk.pop();
        res.emplace_back(node->val);
        node = node->right;
        
    }
    return res;
}


std::vector<int> test_t(TreeNode *treeNode,std::vector<int> &result){
    
    if(treeNode == nullptr) return result;
        
    test_t(treeNode->left,result);
    test_t(treeNode->right,result);
    result.push_back(treeNode->val);
    return result;
}

std::vector<int> test_left(TreeNode *treeNode,std::vector<int> &result){
    
    if(treeNode == nullptr) return result;
        
    test_left(treeNode->left,result);
    test_left(treeNode->right,result);
    result.push_back(treeNode->val);
    return result;
}

//if not L or not R or L.val != R.val: return False

bool loop_trees_second(TreeNode *left_treeNode,TreeNode *right_treeNode){
//    def recur(L, R):
//                if not L and not R: return True
//                if not L or not R or L.val != R.val: return False
//                return recur(L.left, R.right) and recur(L.right, R.left)
//
//            return recur(root.left, root.right) if root else True

    
//    if(treeNode == nullptr) return 0;
    if(left_treeNode == nullptr && right_treeNode == nullptr) return true;
    if(left_treeNode == nullptr || right_treeNode == nullptr || (left_treeNode->val != right_treeNode->val))
    {
        return false;
    }
    
    return loop_trees_second(left_treeNode->left, right_treeNode->right) && loop_trees_second(right_treeNode->right, left_treeNode->left);
}


int loop_trees(TreeNode *treeNode,bool left,std::vector<int> &result, std::vector<int> &count_result){
    
    if(treeNode == nullptr) return 0;
    
    if(left){
        int l_left_count = loop_trees(treeNode->left,left,result,count_result) + 1;
        int l_right_count = loop_trees(treeNode->right,left,result,count_result) + 1;
        result.push_back(treeNode->val);
        int sum = std::max(l_left_count, l_right_count);
        count_result.at(0) = l_left_count;
        count_result.at(1) = l_right_count;
        return sum;
    }else{
        int l_left_count = loop_trees(treeNode->right,left,result,count_result) + 1;
        int l_right_count = loop_trees(treeNode->left,left,result,count_result) + 1;
        result.push_back(treeNode->val);
        int sum = std::max(l_left_count, l_right_count);
        count_result.at(2) = l_right_count;
        count_result.at(3) = l_left_count;
        return sum;
    }
    

    return 0;
}

int sumNumberLeft(TreeNode* root, std::vector<int> &result){
      if(root == nullptr) return 0;
//      return sumNumberLeft(root->left)+root->val;
    int left = sumNumberLeft(root->left,result)+root->val;
    int right = sumNumberLeft(root->right,result)+root->val;
    
    result.at(0) = left;
    result.at(1) = right;
    
    return left;
}

//int sumNumberRight(TreeNode *root){
//      if(root == nullptr) return 0;
//      return sumNumberLeft(root->right)+root->val;
//}



//TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
//    if(preorder.size() == 0) {
//        return nullptr;
//    }
//
//    if(preorder.size() == 1) {
//        TreeNode* res = new TreeNode(preorder[0]);
//        return res;
//    }
//
//    //implied preorder.size() >= 2
//    TreeNode* res = new TreeNode(preorder[0]);
//    int left_size = 0;
//    int curr_inorder = inorder[left_size];
//    while(curr_inorder != preorder[0]) {
//        left_size += 1;
//        curr_inorder = inorder[left_size];
//    }
//    std::vector<int> preorder_left = std::vector<int>(preorder.begin()+1, preorder.begin()+1+left_size);
//    std::vector<int> preorder_right = std::vector<int>(preorder.begin()+1+left_size, preorder.end());
//    std::vector<int> inorder_left = std::vector<int>(inorder.begin(), inorder.begin()+left_size);
//    std::vector<int> inorder_right = std::vector<int>(inorder.begin()+left_size+1, inorder.end());
//
//    TreeNode* left = buildTree(preorder_left, inorder_left);
//    TreeNode* right = buildTree(preorder_right, inorder_right);
//    res->left = left;
//    res->right = right;
//
//    return res;
//};


TreeNode* newNode(int data)
{
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = data;
    node->left = node->right = NULL;
    return (node);
}
  
// Function to insert nodes in level order
TreeNode* insertLevelOrder(int arr[], TreeNode* root,
                       int i, int n){
    // Base case for recursion
    if (i < n)
    {
        if(arr[i] != 0){
            TreeNode* temp = newNode(arr[i]);
            root = temp;
      
            // insert left child
            root->left = insertLevelOrder(arr,
                       root->left, 2 * i + 1, n);
      
            // insert right child
            root->right = insertLevelOrder(arr,
                      root->right, 2 * i + 2, n);
        }
    }
    return root;
}

//int main(int argc, const char * argv[]) {
//    Tress_test *a = new Tress_test();
//    a->a();
//}


//remove duplicates elements from sorted array
int removeDuplicates(std::vector<int>& input) {
    if(input.size() == 0) return 0;
    
    int i = 0;
    int j = 0;
    while (j < input.size()) {
        int i_val = (int)input[i];
        int j_val = (int)input[j];
        if(i != j && (i_val != j_val)){
            i++;
            input[i] = input[j];
        }
        j ++ ;
    }
    return i+1;
}

int maxArea(std::vector<int>& height) {
 
    
}

int main(int argc, const char * argv[]) {
    //{0,0,1,1,1,2,2,3,3,4}
    //{1,2,2,3,4,5,5};
//    {1,1,2}
    std::vector<int> inputArray = {1,1,2};
    removeDuplicates(inputArray);
    
    return 0;
}


//int main(int argc, const char * argv[]) {
//    Linked_List *newList = new Linked_List();
//    ListNode *head1 = new ListNode(1);
//    ListNode *head2 = new ListNode(2);
//    ListNode *head3 = new ListNode(3);
//    ListNode *head4 = new ListNode(4);
//    ListNode *head5 = new ListNode(5);
////    ListNode *head6 = new ListNode(6);
//
//    head1->next = head2;
//    head2->next = head3;
//    head3->next = head4;
//    head4->next = head5;
//    head5->next = NULL;
////    head6->next = NULL;
//
////    newList->getKthFromEnd(head1, 1);
////    newList->reverseList(head1);
////    reverseList_b(head1);
////    [1,2,2,3,3,null,null,4,4]
////    [3,9,20,null,null,15,7]
////    [2,3,3,4,5,5,4,6,null,8,9,9,8,6]
////    newList->traverse(head1);
//
//    TreeNode *left = new TreeNode(2);
//    TreeNode *right = new TreeNode(2);
//
////    TreeNode *left_l = new TreeNode(2);
//    TreeNode *left_r = new TreeNode(3);
//
//    TreeNode *left_l_l = new TreeNode(1);
//
//    TreeNode *right_l = new TreeNode(4);
//    TreeNode *right_l_l = new TreeNode(7);
//    TreeNode *right_l_r = new TreeNode(3);
//
////    left->left = left_l;
////    right->right = right_r;
////    left_l->left = right_l;
////    right_r->right = left_r;
//
//    left->left = left_r;
//    left->right = right_l;
////    left_l->left = left_l_l;
////
////    left_l->left = right_l;
////    left_l->right = right_r;
//
//    right->left = left_r;
//    right->right = right_l;
////    right_l->left = right_l_l;
////    right_l->right = right_l_r;
//
////    left_l->left = right_l;
////    left_r->right = right_r;
//
//    Node *root_node = new Node(1);
//
//    Node *root_node_3 = new Node(3);
//    Node *root_node_2 = new Node(2);
//    Node *root_node_4 = new Node(4);
//    Node *root_node_5 = new Node(5);
//    Node *root_node_6 = new Node(6);
////
//    root_node->children.push_back(root_node_3);
//    root_node->children.push_back(root_node_2);
//    root_node->children.push_back(root_node_4);
//
//    root_node_3->children.push_back(root_node_5);
//    root_node_3->children.push_back(root_node_6);
//
//
//    TreeNode *root = new TreeNode(1,left,right);
//    TreeTravel *tree = new TreeTravel();
//
////    tree->maxDepth(root);
////    std::vector<int> result = tree->preorder(root_node);
////    tree->increasingBST(root);
//
////    中序遍历 inorder = [9,3,15,20,7]
////    后序遍历 postorder = [9,15,7,20,3]
//
//    std::vector<int> inorderss = {9,3,15,20,7};
//    std::vector<int> postorder = {9,15,7,20,3};
//
////    [2,3,3,4,5,5,4,6,null,8,9,9,8,6]
////    [1,2,2,3,4,4,3]
//    int arr[] = { 1,3,2,3,4,4,3,5,6,5,6,5,6,5,6 };
////    [2,3,3,4,5,0,4]
//    int n = sizeof(arr)/sizeof(arr[0]);
//    TreeNode* root_s = insertLevelOrder(arr, root_s, 0, n);
//
//
//
//
//
//
////    tree->buildTree(inorder, postorder);
//    tree->printBT("", root_s, false);
//
//    std::vector<int> result_sum = {0,0,0,0};
//    sumNumberLeft(root_s->left, result_sum);
//    std::vector<int> res;
//
//    bool result = false;
//
//    if(root_s == nullptr || (root_s->left == nullptr && root_s->right == nullptr)) result = true;
//    if(root_s->left == nullptr || root_s->right == nullptr) result = false;
//
//
//    result = loop_trees_second(root_s->left, root_s->right);
//
//
////    std::vector<int> result = test_t(root,res);
////    std::vector<int> result = treeTravel(root);
//
//    std::vector<int> left_result;
//    std::vector<int> right_result;
//    std::vector<int> count_res = {0,0,0,0};
//
//    std::vector<int> count_left_result;
//    std::vector<int> count_right_result;
//
//
//
//
////    loop_trees(root_s->left, true, left_result,count_res);
////    loop_trees(root_s->right, false, right_result,count_res);
////    count_treenumber(root_s->left,true,count_res,count_left_result, count_right_result);
////    count_treenumber(root_s->right,false,count_res, count_left_result, count_right_result);
//    bool equal_vector = false;
//
//    equal_vector = left_result.size()!=right_result.size()?false:true;
//    for(int i=0; i<left_result.size(); i++){
////        equal_vector = left_result[i] == right_result[i]?true:false;
//        if(left_result[i] != right_result[i]){
//            equal_vector = false;
//            break;
//        }
//    }
//
//    if(count_res[0]==count_res[2] && count_res[1]==count_res[3] && equal_vector == true) result = true;
//
//
//    for(int i=0; i < res.size(); i++)
//       std::cout << res.at(i) << ' ';
//
//
////    bool isBlancedTree = tree->isBalanced(root);
////    printf("is BlancedTree -- %d \n",isBlancedTree);
//
////    std::vector<std::vector<int>> result = tree->levelOrder(root);
////    tree->preorder(root);
//
//
////    maxDepth_a(root);
//    char str[] = "hello";
//
//
//    std::vector<int> input ({1,2,3});
//    numIdenticalPairs(input);
//
////    printf("%p\n",a);
////    printf("%p, %p\n",&str[0], &str[1]);
////    printf("%p\n",&str);
////    printf("%p\n",str);
////
////    printf("%p\n",&str_2);
////    printf("%p , %p \n",str_2[0], str_2[1]);
//
////    reverseString(str);
//
//    return 0;
//}
