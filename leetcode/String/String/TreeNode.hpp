//
//  TreeNode.hpp
//  String
//
//  Created by 林涛 on 16/1/23.
//  Copyright © 2016年 limaofuyuanzhang. All rights reserved.
//

#ifndef TreeNode_hpp
#define TreeNode_hpp

#include <stdio.h>
#include <string>
#include <queue>
#include <vector>
#include <cstdlib>
using namespace std;


//Definition of TreeNode:
class TreeNode {
    
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
    
    void preOrder(TreeNode *node);
    void inOrder(TreeNode *node);
    void postOrder(TreeNode *node);
    static string serialize(TreeNode *root);
    static TreeNode * deserialize(string data);

};

#endif /* TreeNode_hpp */
