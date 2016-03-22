//
//  LinkedList.cpp
//  String
//
//  Created by bmob-LT on 16/3/19.
//  Copyright © 2016年 limaofuyuanzhang. All rights reserved.
//

#include "LinkedList.hpp"

/**
 * @param head: The first node of linked list.
 * @param n: An integer.
 * @return: The head of linked list.
 */
ListNode * LinkedList::removeNthFromEnd(ListNode *head, int n) {
    // write your code here
    if (head == NULL || n <= 0) {
        return head;
    }
    
    ListNode *index = head;
    int count = 0;
    while (index != NULL) {
        count++;
        index = index -> next;
    }
    
    int targetIndex = count - n;
    if (targetIndex < 0) {
        return NULL;
    } else if( targetIndex == 0){
        //特殊情况，删除头节点
        ListNode *node = head -> next;
        free(head);
        return node;
    }
    
    index = head;
    for (int i = 1; i < targetIndex; i++) {
        index = index -> next;
    }
    
    ListNode *tmp = index -> next;
    index -> next = tmp -> next;
    free(tmp);
    
    return head;
}

/**
 * @param ListNode l1 is the head of the linked list
 * @param ListNode l2 is the head of the linked list
 * @return: ListNode head of linked list
 */
ListNode *LinkedList::mergeTwoLists(ListNode *l1, ListNode *l2) {
    // write your code here
    if (l1 == NULL ) {
        return l2;
    } else if (l2 == NULL) {
        return l1;
    }
    
    ListNode *l3;
    ListNode *head;
    if (l1->val < l2->val) {
        head = l3 = l1;
        l1 = l1->next;
    } else {
        head = l3 = l2;
        l2 = l2->next;
    }
    
    while (l1 != NULL && l2 != NULL) {
        while (l1!= NULL && l2 != NULL && l1->val < l2->val) {
            l3->next = l1;
            l3 = l3->next;
            l1 = l1->next;
        }
        
        while (l1 != NULL && l2 != NULL && l1->val >= l2->val) {
            l3->next = l2;
            l3 = l3->next;
            l2 = l2->next;
        }
    }
    
    if (l1 != NULL) {
        l3->next = l1;
    } else if(l2 != NULL){
        l3->next = l2;
    }
    return head;
}

/**
 * @param head: The first node of linked list.
 * @return: head node
 */
ListNode *LinkedList::deleteDuplicates(ListNode *head) {
    // write your code here
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    ListNode *i1 = head;
    ListNode *i2 = head->next;
    while (i2 != NULL) {
        if (i1->val == i2->val) {
            ListNode *tmp = i2;
            i2 = i2->next;
            i1->next = i2;
            free(tmp);
        } else {
            i1 = i2;
            i2 = i2->next;
        }
    }
    return head;
}

/**
 * @param head: The first node of linked list.
 * @param x: an integer
 * @return: a ListNode
 */
ListNode *LinkedList::partition(ListNode *head, int x) {
    // write your code here
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    ListNode *index; //遍历链表
    ListNode *p; //在第一个>=x的节点之前
    //找到头节点
    if (head->val < x) {
        //头节点小于x的情况
        ListNode *tmp = head;
        while (tmp->next != NULL && tmp->next->val < x) {
            tmp = tmp->next;
        }
        
        if (tmp ->next == NULL) {
            return head;
        } else {
            p = tmp;
            index = p->next;
        }
        
    } else {
        //头节点>=x的情况，需要找到头节点
        ListNode *tmp = head;
        while (tmp->next != NULL && tmp->next->val >= x) {
            tmp = tmp->next;
        }
        
        if (tmp->next == NULL) {
            //所有节点都大于等于x
            return head;
        } else {
            //找到第一个小于x的节点，取代当前头节点
            index = tmp;
            tmp = tmp->next;
            index->next = tmp->next;
            tmp->next = head;
            p = head = tmp;
        }
    }
    
    //遍历，找到所有小于x的节点并放在正确的位置
    while (index->next != NULL) {
        if (index->next->val < x) {
            ListNode *tmp = index->next;
            index->next = tmp->next;
            tmp->next = p->next;
            p->next = tmp;
            p = p->next;
        } else {
            index = index->next;
        }
    }
    
    return head;
}

