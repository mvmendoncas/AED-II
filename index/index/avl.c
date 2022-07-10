#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avl.h"

void initialize(tree *root) {
	*root = NULL;
}

int table_initialize(table *tab){
	initialize(&tab->index);	
	tab->data_files = fopen("datas.dat", "a+"); //w ->apaga o arquivo existente
	tab->index = upload_files("index.dat", tab->index);
	if(tab->data_files != NULL)
		return 1;
	else
		return 0;
}

void table_finish(table *tab){
	fclose(tab->data_files);
	save_files("index.dat", tab->index);
}

void addBook(table *tab, data *book, int *controlFB){
	if(tab->data_files != NULL) {
			data_type *new = (data_type *) malloc(sizeof(data_type));
			new->key = book->key;

			fseek(tab->data_files, 0L, SEEK_END);
			
			new->index = ftell(tab->data_files);

            char *books_datas = "%d:%s:%s:%d\n";
            fprintf(tab->data_files, books_datas,  book->key, book->title, book->author, book->year);
            tab->index = add(new, tab->index, controlFB);
	}
}

tree add(data_type *value, tree root, int *increase){
	if(root == NULL) {
		tree new = (tree) malloc(sizeof(struct no_avl));
		new->data = value;
		new->left = NULL;
		new->right = NULL;
		new->fb = 0;
	   *increase = 1; 
		return new;
	}

	if(value->key > root->data->key) {
		root->right = add(value, root->right, increase);
        if(*increase) {
			switch(root->fb) {
				case 0:
					root->fb = 1;
                    *increase = 1;
					break;
			    case -1:
					root->fb = 0;
					*increase = 0;
					break;
				case 1:
					*increase = 0;
					return rotate(root);
			}
		}

	}else {
		root->left = add(value, root->left, increase);
		if(*increase){
			switch(root->fb){
				case 0:
					root->fb = -1;
					*increase = 1;
					break;
				case -1:
					*increase = 0;
					return rotate(root);
				case 1:
					root->fb = 0;
					*increase = 0;
					break;
					
			}
		}
	}
	return root;
}

data *get_book(table *tab, int key){
    if(tab->data_files != NULL) {
    tree temp;
    temp = tab->index;

    while(temp!=NULL){

        if(temp->data->key == key) {

            data *book_found = (data*) malloc(sizeof(data));
			char *buffer = (char*) malloc(512 * sizeof(char));
            char *sub_str;

            fseek(tab->data_files, temp->data->index, SEEK_SET);
			fgets(buffer, 512, tab->data_files);

			sub_str = strtok(buffer, ":");
			book_found->key = atoi(sub_str);
			printf("%d", book_found->key);

			sub_str = strtok(NULL, ":");
			book_found->title = strdup(sub_str);

			sub_str = strtok(NULL, ":");
			book_found->author = strdup(sub_str);

			sub_str = strtok(NULL, ":");
			book_found->year = atoi(sub_str);

			free(buffer);
			//free(sub_str);

			return book_found;
        } else {
            if(key > temp->data->key)
                temp = temp->right;
            else
                temp = temp->left;                
        }
    }
    }
    return NULL;
}

int biggest(int a, int b){
	if(a > b)
		return a;
	else
		return b;
}

data_type *biggest_element(tree root) {
	if(root == NULL)
			return NULL;
	if(root->right == NULL)
			return root->data;
	else
			return biggest_element(root->right);
}

data_type *smallest_element(tree root) {
	if(root == NULL)
			return NULL;
	if(root->left == NULL)
			return root->data;
	else
			return biggest_element(root->left);
}

void pre_order(tree root, table *tab) {
	if(root != NULL) {


		print_element(root, tab);
		pre_order(root->left, tab);
		pre_order(root->right, tab);
	}
}

void pos_order(tree root, table *tab) {
	if(root != NULL) {
		pos_order(root->left, tab);
		pos_order(root->right, tab);
		print_element(root, tab);
	}
}

void in_order(tree root, table *tab) {
	if(root != NULL) {
		in_order(root->left, tab);
		print_element(root, tab);
		in_order(root->right, tab);
	}
}

void print_element(tree root, table *tab) {
	data * temp = (data *) malloc (sizeof(data));
	fseek(tab->data_files, root->data->index, SEEK_SET);
	fread(temp, sizeof(data), 1, tab->data_files);
	printf("[%d, %s, %s, %d ]\n", root->data->key, temp->title, temp->author, temp->year);
	free(temp);
}

data *get_books_information(){
	data *new = (data *) malloc(sizeof(data));
	char * buffer = (char *) malloc(256 * sizeof(char));

	getchar();
	printf("Codigo: ");
	scanf("%d", &new->key);

	//__fpurge(stdin);
	getchar();
	printf("Titulo: ");
	fgets(buffer, 255,  stdin);
	remove_enter(buffer);
	/*	novo->titulo = (char *) malloc ((strlen(buffer) + 1) * sizeof(char));
	strcpy(novo->titulo, buffer);*/
	new->title = strdup(buffer);


	printf("Autor: ");
	fgets(buffer, 255,  stdin);
	remove_enter(buffer);
	new->author = strdup(buffer);

	printf("Ano de Lançamento: ");
	scanf("%d", &new->year);
	free(buffer);

	
	return new;
}

void remove_enter(char *string){
	string[strlen(string) -1] = '\0';
}

void save_files(char *name, tree a) {
	FILE *file;
	file = fopen(name, "wb");
	if(file != NULL) {
		save_helper(a, file);
		fclose(file);
	}
}

void save_helper(tree root, FILE *file){
	if(root != NULL) {
		fwrite(root->data, sizeof(data_type), 1, file);
		save_helper(root->left, file);
		save_helper(root->right, file);
	}
}

tree upload_files(char *name, tree a){
	FILE *file;
	file = fopen(name, "rb");
	data_type * temp;
	int controlFB;
	if(file != NULL) {
		temp = (data_type *) malloc(sizeof(data_type));
		while(fread(temp, sizeof(data_type), 1, file)) {
			
			a = add(temp, a, &controlFB);			
			temp = (data_type *) malloc(sizeof(data_type));

		}
		fclose(file);

	}
	return a;
}

tree rotate(tree root){
	if(root->fb > 0) {
		switch(root->right->fb) {
			case 0:
			case 1:
				return simple_left_rotation(root);
			case -1:
				return left_double_rotation(root);					
			} 
	}else {
		switch(root->left->fb){
			case 0:
			case -1:
				return simple_right_rotation(root);
			case 1:
				return right_double_rotation(root);
		}
	}
}

int height(tree root){
	 if (root == NULL) {
        return 0;
    }
    return 1 + biggest(height(root->right), height(root->left));

}
tree delete(data_type *value, tree root, int *decreased){
	if(root == NULL){
		*decreased = 0;
		return NULL;
	}
	if(root->data == value) {
		*decreased = 1;
			//zero child
        	if(root->left == NULL && root->right == NULL){
        		free(root);
        		return NULL;
        	}
			//1 left child
        	if(root->left != NULL && root->right == NULL){
        		tree left = root->left;
        		free(root);
        		return left;
        	}
        	//1 right child
        	if(root->left == NULL && root->right != NULL){
        		tree right = root->right;
        		free(root);
        		return right;
        	}
        	//two children
        	if(root->left == NULL && root->right != NULL){
			root->data = biggest_element(root->left); 
			root->left = delete(root->data, root->left, decreased);
			*decreased = 1;
			return root;
        	}
        
	}
	if(value->key > root->data->key){
		root->right = delete(value, root->right, decreased);
		if(*decreased){
			switch(root->fb){
				case 0:
					root->fb = -1;
					*decreased = 0;
					break;
				case 1:
					root->fb = 0;
					*decreased = 1;
					break;
				case -1:
					if(root->left->fb != 0){
						*decreased = 0;
					} 
					*decreased = 1;
					return rotate(root);
					
					
			}
		}
	}else {
		root->left = delete(value, root->left, decreased);
		//
		if(*decreased){
			switch(root->fb){
				case 0:
					root->fb = 1;
					*decreased = 0;
					break;
				case -1:
					root->fb = 0;
					*decreased = 1;
					break;
				case 1:
					if(root->right->fb != 0){
						*decreased = 1;
					} 
					*decreased = 0;
					return rotate(root);	
			}
		}
	}
	return root;


} 

tree simple_left_rotation(tree root){
	tree p, u, t1, t2, t3;

	p = root;
	u = p->right;
    t1 = p->left;
    t2 = u->left;
    t3 = u->right;

	u->left = p;
	p->right = t2;
    
	if(u->fb == 1) {
		p->fb = 0;
		u->fb = 0;
	} else {
		p->fb = 1;
		u->fb = -1;
	}	
	return u;

}
tree simple_right_rotation(tree root){
	tree p, u, t1, t2, t3;

	p = root;
	u = p->left;
    t1 = u->left;
    t2 = u->right;
    t3 = p->right;

	u->right = p;
	p->left = t2;
    
	if(u->fb == -1) {
		p->fb = 0;
		u->fb = 0;
	} else {
		p->fb = -1;
		u->fb = 1;
	}	
	return u;
}


tree left_double_rotation(tree root){
	tree p, u, v, t1, t2, t3, t4;

	p = root;
	u = p->right;
	v = u->left;
	t1 = p->left;
	t2 = v->left;
	t3 = v->right;
	t4 = u->right;
	
	//Update pointers
	p->right = v;
	v->right = u;
	u->left = t3;
	
	//Update balance factors according to u's fb
	//These values ​​came from the calculations demonstrated in the class
	v->left = p;
	p->right = t2;
	
	switch(v->fb){
		case 0:
			p->fb = 0;
			u->fb = 0;
			v->fb = 0;
			break;
		case -1:
			p->fb = 0;
			u->fb = 1;
			v->fb = 0;
			break;
		case 1:
			p->fb = -1;
			u->fb = 0;
			v->fb = 0;
			break;
	
	}
	return v;
	
}

tree right_double_rotation(tree root){
	tree p, u, v, t1, t2, t3, t4;

	p = root;
	u = p->left;  
	v = u->right;      
	t1 = u->left;	
	t2 = v->left;
	t3 = v->right;
	t4 = p->right;
	
	//Update pointers
	p->left = v;
	v->left = u;
	u->right = t2;

	//Update balance factors according to u's fb
	//These values ​​came from the calculations demonstrated in the class
	v->right = p;
	p->left = t3;
	
	switch(v->fb){
		case 0:
			p->fb = 0;
			u->fb = 0;
			v->fb = 0;
			break;
		case 1:
			p->fb = 0;
			u->fb = -1;
			v->fb = 0;
			break;
		case -1:
			p->fb = 1;
			u->fb = 0;
			v->fb = 0;
			break;
	
	}
	return v;
}