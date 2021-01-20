#include <assert.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#include "bst.h"
#include "../../../linear-ds/adaptive-queue/headers/queue.h"

BST bst_new()
{
    BST bst = {NULL, 0};
    return bst;
}

uint32_t bst_count(const BST *tree)
{
    assert(tree != NULL);
    return tree->mass;
}

static TreeNode *_get_new_node(int32_t el)
{
    TreeNode *new_node = (TreeNode *)malloc(sizeof(TreeNode));
    new_node->data = el;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

BST* bst_add(BST* tree, int32_t element){
    assert(tree != NULL);
    TreeNode *current, *parent;
    current = parent = tree->root;
    while(current != NULL && element != current->data){
        parent = current;
        if(element < current->data){
            current = current->left;
        }else if(element > current->data){
            current = current->right;
        }
    }
    if(current == NULL){
        TreeNode* new_node = _get_new_node(element);
        if(parent == NULL){
            tree->root = new_node;
        }else if(element < parent->data){
            parent->left = new_node;
        }else if(element > parent->data){
            parent->right = new_node;
        }
        ++tree->mass;
    }
    return tree;
}

BST* bst_add_elements(BST* tree, int32_t elements[], uint32_t el_len){
    for (uint32_t i = 0; i < el_len; i++)
    {
        tree = bst_add(tree, elements[i]);
    }
    return tree;
}

uint8_t bst_lookup(const BST *tree, int32_t key){
    assert(tree != NULL);
    TreeNode *current = tree->root;

    while(current != NULL && key != current->data){
        if(key < current->data){
            current = current->left;
        }else if(key > current->data){
            current = current->right;
        }
    }
    return (current != NULL);
}

static TreeNode* _find_min_(TreeNode* node){
    if(node->left == NULL){
        return node;
    }else{
        return _find_min_(node->left);
    }
}

static TreeNode* _delete_(BST* tree, TreeNode* node, int32_t element){
    TreeNode *temp;
    if(node == NULL){
        return node;
    } else if(element < node->data){
        node->left = _delete_(tree, node->left, element);
    } else if(element > node->data){
        node->right = _delete_(tree, node->right, element);
    } else if(node->left && node->right){
        temp = _find_min_(node->right);
        node->data = temp->data;
        node->right = _delete_(tree, node->right, node->data);
    } else {
        temp = node;
        if(node->right == NULL){
            node = node->left;
        }else{
            node = node->right;
        }
        free(temp);
        --tree->mass;
    }
    return temp;
}

BST* bst_delete(BST* tree, int32_t element){
    assert(tree != NULL);
    tree->root = _delete_(tree, tree->root, element);
    return tree;
}

static void _inorder_(TreeNode* node){
    if(node){
        _inorder_(node->left);
        printf("%d\t", node->data);
        _inorder_(node->right);
    }
}

void bst_inorder(BST* tree){
    assert(tree != NULL);
    _inorder_(tree->root);
}

static void _preorder_(TreeNode* node){
    if(node){
        printf("%d\t", node->data);
        _inorder_(node->left);
        _inorder_(node->right);
    }
}

void bst_preorder(BST* tree){
    assert(tree != NULL);
    _preorder_(tree->root);
}

static void _postorder_(TreeNode* node){
    if(node){
        _inorder_(node->left);
        _inorder_(node->right);
        printf("%d\t", node->data);
    }
}

void bst_postorder(BST* tree){
    assert(tree != NULL);
    _postorder_(tree->root);
}

void bst_levelorder_traversal(BST* tree){
    assert(tree != NULL);
    Queue q1 = queue_new(tree->mass);
    Queue* q = &q1;
    QueueResult res;
    TreeNode* node = tree->root;
    queue_add(q, node, &res);
    while(!queue_empty(q)){
        queue_delete(q, &res);
        TreeNode* node = (TreeNode*)res.data;
        if(node->left){
            queue_add(q, node->left, &res);
        }
        if(node->right){
            queue_add(q, node->right, &res);
        }
        printf("%d\t", node->data);
    }
}

static uint32_t _bst_height(const TreeNode *tree){
    if(tree == NULL){
        return 0;
    }else{
        uint32_t lefth = _bst_height(tree->left);
        uint32_t righth = _bst_height(tree->right);
        return lefth > righth ? lefth + 1 : righth + 1;
    }
}

uint32_t bst_height(const BST *tree){
    assert(tree != NULL);
    return _bst_height(tree->root);
}

uint32_t _bst_count_leaves(const TreeNode *tree, uint32_t count){
    assert(tree != NULL);
    if(tree->left == NULL && tree->right == NULL){
        return count + 1;
    }else{
        count += _bst_count_leaves(tree->left, count);
        count += _bst_count_leaves(tree->right, count);
    }
    return count;
}

uint32_t bst_count_leaves(const BST *tree){
    assert(tree != NULL);
    uint32_t count = 0;
    return _bst_count_leaves(tree->root, count);
}

static int32_t _max(TreeNode* tree){
    assert(tree != NULL);
    int32_t val = tree->data;
    //Is left tree traversal needed?
    int32_t lval = _max(tree->left);
    int32_t rval = _max(tree->right);
    if(lval > val){
        val = lval;
    }else if(rval > val){
        val = rval;
    }
    return val;
}

static int32_t _min(TreeNode* tree){
    assert(tree != NULL);
    int32_t val = tree->data;
    //Is left tree traversal needed?
    int32_t lval = _min(tree->left);
    int32_t rval = _min(tree->right);
    if(lval < val){
        val = lval;
    }else if(rval < val){
        val = rval;
    }
    return val;
}

int32_t bst_max(BST* tree){
    assert(tree != NULL);
    return _max(tree->root);
}

int32_t bst_min(BST* tree){
    assert(tree != NULL);
    return _min(tree->root);
}

void bst_ascending(BST* tree){
    bst_inorder(tree);
}

static void _inorder_d(TreeNode* node){
    if(node){
        _inorder_d(node->right);
        printf("%d\t", node->data);
        _inorder_d(node->left);
    }
}

void bst_descending(BST* tree){
    assert(tree != NULL);
    _inorder_d(tree->root);
}