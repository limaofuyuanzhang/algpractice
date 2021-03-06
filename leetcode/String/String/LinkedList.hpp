//
//  LinkedList.hpp
//  String
//
//  Created by bmob-LT on 16/3/19.
//  Copyright © 2016年 limaofuyuanzhang. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include "ListNode.hpp"
#include "TreeNode.hpp"
using namespace std;

class LinkedList{
public:
    static ListNode *removeNthFromEnd(ListNode *head, int n);
    static ListNode *mergeTwoLists(ListNode *l1, ListNode *l2);
    static ListNode *deleteDuplicates(ListNode *head);
    static ListNode *partition(ListNode *head, int x);
    static ListNode *rotateRight(ListNode *head, int k);
    static RandomListNode *copyRandomList(RandomListNode *head);
    static bool hasCycle(ListNode *head);
    static void reorderList(ListNode *head);
    static ListNode *sortList(ListNode *head);
    static TreeNode *sortedListToBST(ListNode *head);
};

#endif /* LinkedList_hpp */
