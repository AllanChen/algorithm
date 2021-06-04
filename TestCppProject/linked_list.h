//
//  linked_list.hpp
//  TestCppProject
//
//  Created by Allan Chan on 2021/1/21.
//

#ifndef linked_list_h
#define linked_list_h

#include <stdio.h>
#include "commen_struct.h"

class Linked_List{
public:
    ListNode* getKthFromEnd(ListNode* head, int k);
//    void reverseLinked(ListNode &head);
    ListNode* reverseList(ListNode* head);
    
    ListNode* reverseList_test(ListNode *head);
    void traverse(ListNode* head);
};

#endif /* linked_list_hpp */
