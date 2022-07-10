#ifndef AVL_H
#define AVL_H
#include <stdio.h>


typedef struct book {
	char *title;
	char *author;
	int year;
	int key;
} data;

typedef struct index {
    int key;
    long index;
} data_type;

typedef struct no_avl {
	data_type *data;
	int fb;
	struct no_avl *left, *right;
} no_avl;

typedef no_avl *tree;

typedef struct table {
    FILE *data_files;
    tree index;
} table;


int table_initialize(table *tab);
void table_finish(table *tab);
void addBook(table *tab, data *book, int *controlFB);

void initialize(tree *root);
tree add(data_type *value, tree root, int *increase);

data *get_book(table *tab, int key); //search for book
tree delete(data_type *value, tree root, int *decreased); //leave it
int height(tree root);
int biggest(int a, int b);
data_type *biggest_element(tree root);
data_type *smallest_element(tree raiz); 
void print(tree root);
void print_element(tree root, table *tab);
tree make_node(int value, tree parent);
void fix_tree(tree root);
tree balance(tree root);
tree rotate(tree root);
tree simple_left_rotation(tree root);
tree simple_right_rotation(tree root);
tree left_double_rotation(tree root);
tree right_double_rotation(tree root);

void pre_order(tree root, table *tab);
void pos_order(tree root, table *tab);
void in_order(tree root, table *tab);


data *get_books_information(); //ler os dados
void remove_enter(char *string);
data *search_book(table *tab, int key);

void save_helper(tree root, FILE *file); //salvar auxiliar
tree upload_files(char *name, tree a);
void save_files(char *name, tree a);



#endif