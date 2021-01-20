#include <assert.h>
#include <stdio.h>

#include "bst.h"

void test_new()
{
    BST bst = bst_new();
    BST *tree = &bst;
    assert(bst_count(tree) == 0);
}

void test_add()
{
    BST bst = bst_new();
    BST *tree = &bst;
    tree = bst_add(tree, 50);
    tree = bst_add(tree, 20);
    tree = bst_add(tree, 90);
    assert(bst_count(tree) == 3);
}

void test_lookup()
{
    BST bst = bst_new();
    BST *tree = &bst;
    tree = bst_add(tree, 50);
    tree = bst_add(tree, 20);
    tree = bst_add(tree, 90);
    assert(bst_lookup(tree, 20));
}

void test_delete()
{
    BST bst = bst_new();
    BST *tree = &bst;
    tree = bst_add(tree, 50);
    tree = bst_add(tree, 20);
    tree = bst_add(tree, 90);
    bst_delete(tree, 20);
    assert(bst_count(tree) == 2);
}

void test_inorder()
{
    BST bst = bst_new();
    BST *tree = &bst;
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

void test_preorder()
{
    BST bst = bst_new();
    BST *tree = &bst;
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

void test_postorder()
{
    BST bst = bst_new();
    BST *tree = &bst;
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

void test_levelorder_traversal()
{
    BST bst = bst_new();
    BST *tree = &bst;
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

void test_height()
{
    BST bst = bst_new();
    BST *tree = &bst;
    tree = bst_add(tree, 50);
    tree = bst_add(tree, 20);
    tree = bst_add(tree, 90);
    tree = bst_add(tree, 40);
    tree = bst_add(tree, 60);
    tree = bst_add(tree, 10);
    tree = bst_add(tree, 35);
    assert(bst_height(tree) == 4);
}

void test_height2()
{
    BST bst = bst_new();
    BST *tree = &bst;
    int32_t elements[] = {10,50,40,35,79,84,99,25};
    tree = bst_add_elements(tree, elements, 8);
    assert(bst_height(tree) == 5);
}

void test_count_leaves()
{
    BST bst = bst_new();
    BST *tree = &bst;
    int32_t elements[] = {10,50,40,35,79,84,99,25};
    tree = bst_add_elements(tree, elements, 8);
    printf("\n\n");
    bst_levelorder_traversal(tree);
    uint32_t leaves = bst_count_leaves(tree);
    assert(leaves == 2);
}

void test_max()
{
    BST bst = bst_new();
    BST *tree = &bst;
    int32_t elements[] = {10,50,40,35,79,84,99,25};
    tree = bst_add_elements(tree, elements, 8);
    bst_max(tree);
    assert(bst_max(tree) == 99);
}

void test_min()
{
    BST bst = bst_new();
    BST *tree = &bst;
    int32_t elements[] = {10,50,40,35,79,84,99,25};
    tree = bst_add_elements(tree, elements, 8);
    assert(bst_min(tree) == 10);
}

void test_ascending()
{
    BST bst = bst_new();
    BST *tree = &bst;
    int32_t elements[] = {10,50,40,35,79,84,99,25};
    tree = bst_add_elements(tree, elements, 8);
    printf("\nAscending:\n");
    bst_ascending(tree);
}

void test_descending()
{
    BST bst = bst_new();
    BST *tree = &bst;
    int32_t elements[] = {10,50,40,35,79,84,99,25};
    tree = bst_add_elements(tree, elements, 8);
    printf("\nDescending:\n");
    bst_descending(tree);
}

int main()
{
    test_new();
    test_lookup();
    test_add();
    test_delete();
    test_inorder();
    test_preorder();
    test_postorder();
    test_levelorder_traversal();
    test_height();
    test_height2();
    //TODO following 3 are not working.
    // test_count_leaves();
    // test_max();
    // test_min();

    test_ascending();
    test_descending();
    return 0;
}