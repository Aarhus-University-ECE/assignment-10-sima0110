#include "btree.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct tree_node *Insert(int x, struct tree_node *t) {
  // Insert item x into the tree t
  if (t == NULL){
  
  struct tree_node *new = malloc(sizeof(struct tree_node)); //creating a new node//
  new->left = NULL; 
  new->right = NULL; 
  new->item = x; 
  t = new;
  } 
  else if (x>t->item){ //goes to the right if x>t>item//
    t->right = Insert(x,t->right);
  } 
  else{
    t->left = Insert(x,t->left); //otherwise it goes to the left//
  }
  return t;
}

struct tree_node *Remove(int x, struct tree_node *t) {
  // Remove one item from the tree t
 if(t == NULL){ //if the tree is empty OR x is not in tree 0. cases
  return NULL; 
 }

  

  if (x == t->item)
  {
    // 1. at leaf node, just free t and return NULL to parent nodes pointer
    if (t->left == NULL && t->right == NULL)
    {
      free(t);
      return NULL;
    }
    
    // 2. if t has left AND right child, then take tmp = t->right, and go as far as you can to the left of tmp. Then swap with t->item
    // and free tmp, as it is a leaf node
  if (t->right !=NULL && t->left !=NULL)
  {
    struct tree_node* tmp = t->right;

    while (tmp->left != NULL)
    {
      tmp = tmp->left; 
    }

      t->item = tmp->item; 
      free(tmp); 
    
  }
    // 3. if t has 1 child either left or right, then node* tmp = t, free(t), return t->(either left or right)  
  if (t->left != NULL)
  {
    struct tree_node* left = t->left;
    free(t);
    return left;
  }
  else {
    struct tree_node* right = t->right;
    free(t);
    return right;
  }
  

  }
  


 else if(x < t->item){
  t->left = Remove(x,t->left);
  return t;
  }
 else if (x > t->item){
  t->right = Remove(x,t->right);
  return t;
 }

 /*
 if (t->left == NULL && t->right == NULL){
 free(t); //frees the node if it is a leaf//
 }
 else if (x == t->item) 
  {
    t = NULL;
  }



  return NULL;
  */
}


int Contains(int x, struct tree_node *t) {

  // Return true if the tree t contains item x. Return false otherwise.
  if (t == NULL){
    return false; //returns false if the element is not found//
  }
  if (t->item == x){
    return true; //returns true if the element is found//
  } 
  else if(x > t->item){
    return Contains(x,t->right); 
  }
  else if(x < t->item){
    return Contains(x,t->left);
  }
}

struct tree_node *Initialize(struct tree_node *t) {
  // Create an empty tree
  t = NULL; //creates an empty tree// 
  return t; 
}

int Empty(struct tree_node *t) {
  // Test if empty
  if(t == NULL){ //checks if the tree is empty//
    return 1; //returns true if the tree is empty//
  }
  return 0; //otherwise it returns false//
}

int Full(struct tree_node *t) {
  // Test if full
  return 0;
}


void print_btree(struct tree_node* t, int depth) {
  if (t != NULL)
  {
    for (size_t i = 0; i < depth; i++)
    {
      printf("  ");
    }
    
    printf("- %d\n", t->item);
    print_btree(t->left, depth + 1);
    print_btree(t->right, depth + 1);
  }
  
}