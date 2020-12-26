
/*
Utku Berkalp ÜNALAN
2025336 
CENG301 HW-2

input: 5 10 7 2 4 6 8
preorder_Traverse(): 5 2 4 10 7 6 8
postorder_Traverse(): 4 2 6 8 7 10 5

input: 2 5 10 9 4 1 
preorder_Traverse(): 2 1 5 4 10 9
postorder_Traverse(): 1 4 9 10 5 2

*/
#include<stdio.h>
#include<stdlib.h>

typedef struct TNode TNode;
struct TNode{
	int data;
	struct TNode *left; 
	struct TNode *right; 
};

typedef struct TNode *TNodePtr;

void insert(TNodePtr *tp, int val){

	if(*tp == NULL){
		*tp = (TNode*)malloc(sizeof(TNode));

		if(*tp != NULL){

		(*tp) -> data = val;
		(*tp) -> right = NULL;
		(*tp) -> left = NULL;
		}
	}

	else{
		if(val  < (*tp) -> data){
			insert(&((*tp) -> left),val); 
		}

		else if(val >= (*tp) -> data){
			insert(&((*tp) -> right),val);
		}
	}

}


void inorder_Traverse(TNodePtr tp){

	if(tp == NULL)
		return;
	inorder_Traverse(tp -> left);
	printf("%d ",tp -> data);
	inorder_Traverse(tp -> right);
	
}

void postorder_Traverse(TNodePtr tp){
	if(tp == NULL)
		return;
	postorder_Traverse(tp -> left);
	postorder_Traverse(tp -> right);
	printf(	"%d ",tp -> data);
}

void preorder_Traverse(TNodePtr tp){
	if(tp == NULL)
		return;
	printf("%d ",tp -> data);
	preorder_Traverse(tp -> left);
	preorder_Traverse(tp -> right);
}



int main(int argc, char* argv[]){

	TNodePtr root = NULL;

	for(int i = 1;  i < argc ; i++ ){
		printf("%d ",atoi(argv[i]));
		insert(&root, atoi(argv[i]));
}

printf("\n");
printf("preorder_Traverse: ");
preorder_Traverse(root);

printf("\n");
printf("postorder_Traverse: ");
postorder_Traverse(root);

/*
printf("\n");
printf("inorder_Traverse: ");
inorder_Traverse(root);
*/



return 0;

}