#include <assert.h>
#include <stdio.h>

#include "bst.h"

void test_new(){
    BST bst = bst_new();
    BST* tree = &bst;
    assert(bst_count(tree) == 0);
}

void test_add(){
    BST bst = bst_new();
    BST* tree = &bst;
    tree = bst_add(tree, 50);
    tree = bst_add(tree, 20);
    tree = bst_add(tree, 90); 
    assert(bst_count(tree) == 3);
}

void test_inorder(){
    BST bst = bst_new();
    BST* tree = &bst;
    tree = bst_add(tree, 50);
    tree = bst_add(tree, 20);
    tree = bst_add(tree, 90);
    tree = bst_add(tree, 40);
    tree = bst_add(tree, 60);
    tree = bst_add(tree, 10);
    tree = bst_add(tree, 35); 
    printf("\ninorder:\n");
    bst_inorder(tree);
}

void test_preorder(){
    BST bst = bst_new();
    BST* tree = &bst;
    tree = bst_add(tree, 50);
    tree = bst_add(tree, 20);
    tree = bst_add(tree, 90);
    tree = bst_add(tree, 40);
    tree = bst_add(tree, 60);
    tree = bst_add(tree, 10);
    tree = bst_add(tree, 35); 
    printf("\npreorder:\n");
    bst_preorder(tree);
}

void test_postorder(){
    BST bst = bst_new();
    BST* tree = &bst;
    tree = bst_add(tree, 50);
    tree = bst_add(tree, 20);
    tree = bst_add(tree, 90);
    tree = bst_add(tree, 40);
    tree = bst_add(tree, 60);
    tree = bst_add(tree, 10);
    tree = bst_add(tree, 35); 
    printf("\npostorder:\n");
    bst_postorder(tree);
}

void test_levelorder_traversal(){
    BST bst = bst_new();
    BST* tree = &bst;
    tree = bst_add(tree, 50);
    tree = bst_add(tree, 20);
    tree = bst_add(tree, 90);
    tree = bst_add(tree, 40);
    tree = bst_add(tree, 60);
    tree = bst_add(tree, 10);
    tree = bst_add(tree, 35);
    printf("\nlevelorder:\n");
    bst_levelorder_traversal(tree);
}

void test_height(){
    BST bst = bst_new();
    BST* tree = &bst;
    tree = bst_add(tree, 50);
    tree = bst_add(tree, 20);
    tree = bst_add(tree, 90);
    tree = bst_add(tree, 40);
    tree = bst_add(tree, 60);
    tree = bst_add(tree, 10);
    tree = bst_add(tree, 35);
    assert(bst_height(tree) == 4);
}

int main(){
    test_new();
    test_add();
    test_inorder();
    test_preorder();
    test_postorder();
    test_levelorder_traversal();
    test_height();
    return 0;
}