
//�X�^�b�N��p����������ϊ�
//j1411 ���R ����

#include <stdio.h>
#include <stdlib.h>
#define stack_size 100
#define stack_type char
#define format "%c"

#include "stack.h"	//�X�^�b�N�Ɋւ���ϐ����֐��̓ǂݍ���

//���Ԃŏ������ݏ�����������s���o�[�W����
//(���_ �F ��������H��Ȃ��B�@ ���_ �F �������Ԃ������Ȃ�)
int main(){
	int ch, pch, small;
	small = 0;		//�������Ƒ啶���𔻒肷��t���O_������:1
	init_stack();
	fprintf(stdout, "Please enter English text: \n");
	pch = ' ';		//�O�ɓ��͂��ꂽ���̂��i�[����ϐ��̏����� (�������̓X�y�[�X)
	
	while( ( ch = getchar() ) != '\n' ){		//���s�����͂����܂ŏ����𑱂���
		
		if(ch != ' ' && ch != '.' && ch != ',' ){
			if(pch == ' ' || pch == '.' || pch == ','){
				if(ch >= 97 && ch <= 122){	small = 1; }	//�������̎��A�t���O�𗧂Ă�
			}
			if(small == 1){
				push(ch);						//��x�X�^�b�N����
			}
			else{
				fprintf(stdout, format, ch);	//���̂܂܏�������
			}
		}
		else{
			if(small == 1){
				while(stack_stock() > 0){
					fprintf(stdout, format, pop());	//�X�^�b�N����Ă�����̂��|�b�v���\������
				}
				small = 0;						//����������t���O��������
			}
			fprintf(stdout,format,ch);				//�󔒂̑}��
		}
		pch = ch;
	}
	while(stack_stock() > 0){					//�]���\��
		fprintf(stdout, format, pop());
	}
	fprintf(stdout, "\n---Finish---\n");
	
	return 0;
}