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
 if(t == NULL){ //if the tree is empty// 
  return t; 
 }
 else if(x < t->item){
  t->left = Remove(x,t->left);
  }
 else if (x > t->item){
  t->right = Remove(x,t->right);
 }
 if (t->left == NULL && t->right == NULL){
 free(t); //frees the node if it is a leaf//
 }
 else if (x == t->item) 
  {
    t = NULL;
  }
  return NULL;
}


int Contains(int x, struct tree_node *t) {

  // Return true if the tree t contains item x. Return false otherwise.
  if (t = NULL){
    return false; //returns false if the element is not found//
  }
  if (t->item == x){
    return true; //returns true if the element is found//
  } 
  else if(t->item > x){
    return Contains(x,t->left); 
  }
  else if(t->item <= x){
    return Contains(x,t->right);
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
