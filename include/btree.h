#ifndef BTREE_H
#define BTREE_H

struct tree_node {
  int item;
  struct tree_node *left;
  struct tree_node *right;
};

int Empty(struct tree_node *t);
struct tree_node *Insert(int x, struct tree_node *t);
struct tree_node *Remove(int x, struct tree_node *t);
int Contains(int x, struct tree_node *t);
struct tree_node *Initialize(struct tree_node *t);
int Full(struct tree_node *t);

void print_btree(struct tree_node* t, int depth);


#endif // BTREE_H