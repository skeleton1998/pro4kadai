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
	//�؂���łȂ������m�F
	if(p == NULL)	return;
	//�؂̃f�[�^���o��
	print_tree(depth+1, p->right);
	for(i=0; i < depth; i++){
		fprintf(stdout, "   ");
	}
	fprintf(stdout, "  %4d\n", p-> data);
	print_tree(depth+1, p->left);
}

//�V�����m�[�h(�f�[�^: y)��}������֐�
void insert_node(int y, TREE *p) {
	TREE *q;
	//�؂���łȂ������m�F
	if( root == NULL ){
		fprintf(stderr, "Error : There is no data!");
		return;
	}
	q = (TREE *)malloc( sizeof(TREE) );
	q -> data = y;
	q -> left = NULL;
	q -> right = NULL;
	
	if( y < p->data ){
		if( p -> left != NULL )		insert_node(y,p->left);
		else{
			p -> left = q;
			return;
		}
	}
	else{
		if( p -> right != NULL )	insert_node(y,p->right);
		else{
			p -> right = q;
			return;
		}
	}	
}

//�w�肳�ꂽ�f�[�^�����m�[�h���폜����֐�
int delete_node(int y){
	TREE *n, *p_n, *l_b;
	int d;
	n = root;
	p_n = NULL;
	d = 0;
	//�؂���łȂ������m�F
	if( root == NULL ){
		fprintf(stderr, "Error : There is no data!");
		return -1;
	}
	//�폜�Ώۂ̃f�[�^��������
	while(n != NULL && n->data != y){
		if(n->data > y){
			p_n = n;
			n = n -> left;
			d = -1;
		}
		else{
			p_n = n;
			n = n -> right;
			d = 1;
		}
	}
	if(n == NULL){
		fprintf(stderr,"Error : Search data not found!\n");
		return 0;
	}
	//�f�[�^�̍폜
	if(n -> left == NULL){
		if(n -> right == NULL){	
			if(d == 1)	p_n -> right = NULL;
			else	p_n -> left = NULL;
			return 1;
		}
		else{
			if(d == 1)		p_n -> right = n -> right;
			else	p_n -> left = n -> right;
			return 1;
		}
	}
	else{
		if(n -> right == NULL){
			if(d == 1)		p_n -> right = n -> left;
			else	p_n -> left = n -> left;
			return 1;
		}
		l_b = n -> left;
		while(l_b -> right != NULL){
			n = l_b;
			l_b = l_b -> right;
		}
		n -> right = NULL;
		if(d == 1){
			l_b -> right = p_n -> right -> right;
			l_b -> left = p_n -> right -> left;
			p_n -> right = l_b;
		}
		else{
			l_b -> right = p_n -> left -> right;
			l_b -> left = p_n -> left -> left;
			p_n -> left = l_b;
		}
	}
	return 1;
}


int main(){
	int y;
	root = NULL;			//�񕪖؂̏�����
	construct_tree();		//�񕪖؂̍\�z
	print_tree(0, root);	//�񕪖؂̏o��
	
	//�f�[�^�̑}��
	fprintf(stdout, "*******insert_node*******\n" );
	fprintf(stdout, "Input insert data:");
	scanf("%d", &y);
	insert_node(y,root);
	print_tree(0,root);
	
	//�f�[�^�̍폜
	fprintf(stdout, "*******Delete*******\n" );
	fprintf(stdout, "Input delete data:");
	scanf("%d", &y);
	delete_node(y);
	print_tree(0,root);
	
	return 0;
}