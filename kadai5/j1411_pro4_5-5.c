#include <stdio.h>
#include <stdlib.h>

//�A�����X�g�̍\���̐錾
typedef struct node{
	struct node *prev;
	char data;
	struct node *next;
}LISTEL;

LISTEL root;		//���X�g�̐擪�̃m�[�h���w���\���̂�錾����

//�A�����X�g���\�z����֐�
void construct_list(int argc, char **argv){
	LISTEL *p, *q;
	FILE *fp;
	int y, i, k, noIndex[100];
	char buf[200], n;
	
	for(i = 1; i < argc; i++){
		if( ( fp = fopen( argv[i],"r" ) ) == NULL){	
			fprintf(stderr, "Error : cannot open file\n");
			exit(1);	
		}
		
		while(1){
			fgets(buf, sizeof(buf), fp);
			
			if(buf[0] == '\n'){
				return;
			}
			i=0;	k=0;
			//�ŏ��ɓ��͂��ꂽ�������J���}�łȂ��ꍇ�C�z��̏ꏊ��noIndex[]�Ɋi�[
			if(buf[i] != ','){
				noIndex[k++] = i;
			}	
			//2�ڈȍ~�ɓ��͂��ꂽ�������J���}�łȂ��ꍇ�C�z��̏ꏊ��noIndex[]�Ɋi�[
			while(buf[i] != ','){
				i++;
				if(buf[i-1] == ',' && buf[i] != ',' && buf[i] != '\n'){
					noIndex[k++] = i;
				}
			}
			//���������I�[�o�[�����ꍇ
			if(buf[i-1] != ','){
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
		fclose(fp);
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

int main(int argc, char **argv){
	int i;

	root.next = &root;		//���X�g�̏�����
	root.prev = &root;
	construct_list(argc, argv);	//���X�g�̍\�z
	print_list();		//���X�g�̏o��
	return 0;
}