#include <stdio.h>
#include <stdlib.h>

//�A�����X�g�̍\���̐錾
typedef struct node{
	int data;
	struct node *next;
}LISTEL;

LISTEL root;		//���X�g�̍ŏ��̃m�[�h���w���|�C���^

//�A�����X�g���\�z����֐�
void construct_list(){
	LISTEL *p;
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
		
		//���͂��ꂽ�������z���X�g�Ɋi�[����
		for(i=0; i<k; i++){
			n = sscanf(&buf[ noIndex[i] ], "%d" , &y);
			if(n != 1){
				fprintf(stderr, "Error : non-number input data\n");
				continue;
			}
			//�ǉ�����m�[�h���w���|�C���^�̃������𓮓I�Ɋm�ۂ���
			p = (LISTEL *)malloc( sizeof(LISTEL) );
			//�ǉ�����m�[�h�ɓ��͂��ꂽ�������i�[
			p -> data = y;
			//�V���ɍ\�z����m�[�h�̃|�C���^�ɁC�擪�m�[�h�̃A�h���X��������
			p -> next = root.next;
			//�擪�m�[�h���w���|�C���^�ɁC�ǉ������m�[�h�̃A�h���X��������
			root.next = p;	
		}
	}
}

//�A�����X�g���o�͂���֐�
void print_list(){
	LISTEL *p;
	p = (LISTEL *)malloc( sizeof(LISTEL) );
	//���X�g�̐擪�m�[�h�̃A�h���X��p�ɑ������
	p = root.next;
	if(p == &root){
		fprintf(stderr, "There is no data!");
		return;
	}
	fprintf(stdout, "List data: ");
	while(p != &root){
		fprintf(stdout," %4d", p -> data);
		p = p -> next;
	}
	fprintf(stdout, "\n");
}

int main(){
	root.next = &root;	//���X�g�̏�����
	construct_list();	//���X�g�̍\�z
	print_list();		//���X�g�̏o��
	return 0;
}