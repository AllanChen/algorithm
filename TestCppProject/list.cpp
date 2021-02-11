//
//  List.cpp
//  TestCppProject
//
//  Created by Allan Chan on 2021/1/21.
//

#include "commen_struct.h"
#include "list.h"
#include <iostream>

//剑指 Offer 22. 链表中倒数第k个节点
ListNode* getKthFromEnd(ListNode* head, int k) {

    ListNode *result = head;
    int count_node = 1;
    while (head->next != NULL) {
        head = head->next;
        count_node +=1;
    }
    
    if (k == count_node){
        return  result;
    }
    int point = abs(k - count_node) + 1;
    
    int result_couter = 1;
    
    while (result->next != NULL) {
        if (point == result_couter){
            return result;
        }
        result = result->next;
        result_couter +=1;
    }
    
    return result;
}
