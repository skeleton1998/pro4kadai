#include <stdio.h>
#include <stdlib.h>

//�A�����X�g�̍\���̐錾
typedef struct node{
	struct node *prev;
	int data;
	struct node *next;
}LISTEL;

LISTEL root;		//���X�g�̐擪�̃m�[�h���w���\���̂�錾����

//�A�����X�g���\�z����֐�
void construct_list(){
	LISTEL *p, *q;
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
		
		//���͂��ꂽ���������X�g�Ɋi�[����
		for(i=0; i<k; i++){
			n = sscanf(&buf[ noIndex[i] ], "%d" , &y);
			if(n != 1){
				fprintf(stderr, "Error : non-number input data\n");
				continue;
			}
			p = (LISTEL *)malloc( sizeof(LISTEL) );
			q = (LISTEL *)malloc( sizeof(LISTEL) );
			
			q = root.next;		//�擪�̃m�[�h�̃A�h���X���i�[
			
			p -> data = y;		//�ǉ�����m�[�h�ɓ��͂��ꂽ�������i�[
			p -> next = q;		//�ǉ�����m�[�h���w���C���̃m�[�h��擪�m�[�h�ɂ���	
			p -> prev = &root;	//�ǉ�����m�[�h���w���C�O�̃m�[�h��擪���w���m�[�h�ɂ���
			root.next = p;		//�擪���w���m�[�h���C�ǉ�����m�[�h���w���悤�ɂ���
			q -> prev = p;		//�ǉ��O�̐擪�m�[�h���C�w���O�̃m�[�h��ǉ�����m�[�h�ɂ���
		}
	}
}

//�A�����X�g���o�͂���֐�
void print_list(){
	LISTEL *p, *q;
	p = (LISTEL *)malloc( sizeof(LISTEL) );
	q = (LISTEL *)malloc( sizeof(LISTEL) );
	p = root.next;
	q = root.prev;
	
	if(p == &root || q == &root){	//���X�g����łȂ������m�F
		fprintf(stderr, "There is no data!");
		return;
	}
	//���X�g���̃f�[�^��擪����o��
	fprintf(stdout, "List data(From Last): ");
	while(p != &root){
		fprintf(stdout," %2d", p -> data);
		p = p -> next;
	}
	fprintf(stdout, "\n");
	
	//���X�g���̃f�[�^�𖖔�����o��
	fprintf(stdout, "List data(From First): ");
	while(q != &root){
		fprintf(stdout," %2d", q -> data);
		q = q -> prev;
	}
	fprintf(stdout, "\n");
}

//�m�[�h���w�肳�ꂽ�ʒu�ɑ}������
void insert_node(int k, int y){
	int i;
	LISTEL *p, *q;
	if(k <= 0){
		fprintf(stderr,"Error : Target node is not found!\n");
		return;
	}
	p = (LISTEL *)malloc( sizeof(LISTEL) );
	p = root.next;
	for(i=1; i<k ; i++){
		if(p == &root){
			fprintf(stderr,"Error : Target node is not found!\n");
			return;
		}
		p = p -> next;
	}
	q = (LISTEL *)malloc( sizeof(LISTEL) );
	q -> data = y;
	q -> next = p;
	q -> prev = p -> prev;
	p -> prev -> next = q;
	p -> prev = q;
}

//�w�肳�ꂽ�m�[�h���폜����
void delete_node(int k){
	int i;
	LISTEL *p;
	p = (LISTEL *)malloc( sizeof(LISTEL) );
	p = root.next;
	if(p == &root || k <= 0){
		fprintf(stderr,"Error : Target node is not found!\n");
		return;
	}
	if(k == 0){
		root.next = &root;
		root.prev = &root;
		return;
	}
	
	for(i=1; i<k ; i++){
		if(p == &root){
			fprintf(stderr,"Error : Target node is not found!\n");
			return;
		}
		p = p->next;
	}
	
	p -> prev -> next = p -> next;
	p -> next -> prev = p -> prev;
	
}

int main(){
	int k,y;
	root.next = &root;		//���X�g�̏�����
	root.prev = &root;
	construct_list();	//���X�g�̍\�z
	print_list();		//���X�g�̏o��
	
	//�f�[�^�̑}��
	fprintf(stdout, "*******Insert*******\n");
	fprintf(stdout, "Input insert-location: ");
	scanf("%d", &k);
	fprintf(stdout, "Input insert data: ");
	scanf("%d", &y);
	insert_node(k, y);
	print_list();		//���X�g�̏o��
	
	//�f�[�^�̍폜
	fprintf(stdout, "*******Delete*******\n");
	fprintf(stdout, "Input delete-location: ");
	scanf("%d", &k);
	delete_node(k);
	print_list();		//���X�g�̏o��
	
	return 0;
}