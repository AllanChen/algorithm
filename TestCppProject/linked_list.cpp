//
//  linked_list.cpp
//  TestCppProject
//
//  Created by Allan Chan on 2021/1/21.
//

#include "linked_list.h"
#include "commen_struct.h"
#include <iostream>

//递归解决反转链表
ListNode *Linked_List::reverseList(ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    ListNode *result = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
        
    return result;
}

//增加多一个变量解决,重点是理解 tmp->next = result, result = tmp;
ListNode* reverseList_a(ListNode *head) {
    ListNode *result = nullptr;
    while (head != NULL) {
        ListNode *tmp = head;
        head = head->next;
        tmp->next = result;
        result = tmp;
    }

    return result;
}

//剑指 Offer 22. 链表中倒数第k个节点
ListNode *Linked_List::getKthFromEnd(ListNode *head, int k) {
    ListNode *result = head;
    int count_node = 1;
    while (head->next != NULL) {
        head = head->next;
        count_node += 1;
    }

    if (k == count_node) {
        return result;
    }
    int point = abs(k - count_node) + 1;

    int result_couter = 1;

    while (result->next != NULL) {
        if (point == result_couter) {
            return result;
        }
        result = result->next;
        result_couter += 1;
    }

    return result;
}

void Linked_List::traverse(ListNode *head) {
    printf("You are traver %d \n", head->val);
    if (head->next == NULL) {
        return;
    }
    traverse(head->next);
}


ListNode *Linked_List::reverseList_test(ListNode *head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    
    ListNode *result = reverseList(head->next);
    head->next->next =  head;
    head->next = NULL;
    return result;
}


//迭代反转链表前 N
ListNode *Linked_List::reversListN_notReverse(ListNode *head, int n){
    if(n == 1) return head;
    ListNode *result = nullptr;
    int count = 1;
    while (head !=nullptr) {
        ListNode *temp = head;
        head = head->next;
        temp->next = result;
        result = temp;
        if(count == n) break;
        count ++;
    }
    return result;
}


ListNode *reverse1(ListNode *head){
    if(head == nullptr || head->next == nullptr)
        return head;
    return reverse1(head->next);
}

//递归反转链表前 N
ListNode *successor = nullptr;
int reverse_count = 1;
ListNode *Linked_List::reversListN_reverse(ListNode *head, int n){
    if(n == 1){
//        successor = head->next;
        return head;
    }
    
//    reverse_count ++;
    ListNode *last = reversListN_reverse(head->next, n-1);
    head->next->next = head;
    head->next = nullptr;
    
//    if(reverse_count == n){
//        successor = head;
//    }

//    reverse_count --;

    return last;
}


