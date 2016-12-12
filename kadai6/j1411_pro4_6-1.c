#include <stdio.h>
#include <stdlib.h>

//�񕪖؂̍\���̐錾
typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}TREE;

TREE *root;		//���̃m�[�h���w���|�C���^

//�A�����X�g���\�z����֐�
void construct_tree(){
	TREE *p,*q;
	int n, y, i, k, noIndex[50];
	char buf[100];
	while(1){
		fprintf(stdout, "Input data: ");
		fgets(buf, sizeof(buf), stdin);
		
		if(buf[0] == '\n'){
			return;
		}
		i=0;	k=0;
		//�ŏ��ɓ��͂��ꂽ�������X�y�[�X�łȂ��ꍇ�C�z��̏ꏊ��noIndex[]�Ɋi�[
		if(buf[i] != ' '){
			noIndex[k++] = i;
		}
		//2�ڈȍ~�ɓ��͂��ꂽ�������X�y�[�X�łȂ��ꍇ�C�z��̏ꏊ��noIndex[]�Ɋi�[
		while(buf[i] != '\0'){
			i++;
			if(buf[i-1] == ' ' && buf[i] != ' ' && buf[i] != '\n'){
				noIndex[k++] = i;
			}
		}
		//���������I�[�o�[�����ꍇ
		if(buf[i-1] != '\n'){
			fprintf(stderr, "Error : Too long input data\n");
			exit(1);
		}
		
		//���͂��ꂽ�������m�[�h�Ɋi�[���Ė؂��\�z����
		for(i=0; i<k; i++){
			n = sscanf(&buf[ noIndex[i] ], "%d" , &y);
			if(n != 1){
				fprintf(stderr, "Error : non-number input data\n");
				continue;
			}
			if(i == 0){
				q = (TREE *)malloc( sizeof(TREE) );
				q -> data = y;
				q -> left = NULL;
				q -> right = NULL;
				root = q;
			}
			else{
				p = root;
				while(p != NULL){
					if( y < p->data ){
						if( p -> left != NULL )		p = p->left;
						else{
							q = (TREE *)malloc( sizeof(TREE) );
							q -> data = y;
							q -> left = NULL;
							q -> right = NULL;
							p->left = q;
							break;
						}
					}
					else{
						if( p -> right != NULL )	p = p->right;
						else{
							q = (TREE *)malloc( sizeof(TREE) );
							q -> data = y;
							q -> left = NULL;
							q -> right = NULL;
							p -> right = q;
							break;
						}
					}
					
				}
			}
		}
	}
}

//�A�����X�g���o�͂���֐�
void print_tree(int depth, TREE *p){
	int i;
	if(p == NULL)	return;
	//�؂̃f�[�^���o��
	print_tree(depth+1, p->right);
	for(i=0; i < depth; i++){
		fprintf(stdout, "   ");
	}
	fprintf(stdout, "  %4d\n", p-> data);
	print_tree(depth+1, p->left);
}

int main(){
	root = NULL;			//�񕪖؂̏�����
	construct_tree();		//�񕪖؂̍\�z
	print_tree(0, root);	//�񕪖؂̏o��
	return 0;
}