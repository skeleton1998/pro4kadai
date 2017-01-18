#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
int d[MAX];

unsigned bits(unsigned x, int k, int j){
	return (x >> k) & ~(~0 << j);
}

void radix_sort(int n){
	int pass, order[2], i, j, b[MAX];
	for(pass = 0; pass < 32; pass++){
		for(i=0; i<2; i++){ order[i] = 0; }
		for(i=1; i<=n; i++){ order[bits(d[i],pass,1)]++; }
		order[1] += order[0];
		for(i=n; i>=1; i--){ 
			b[ order[bits(d[i],pass,1)]-- ] = d[i];
		}
		for(i=1;i<=n;i++){ d[i] = b[i]; }
	}
}
int main(){
	int n,i,seed;
	n = 0;
	fprintf(stdout, "Input random-seed: ");
	scanf("%d", &seed);
	
	fprintf(stdout, "Input the number of data: ");
	scanf("%d", &n);

	if(n > MAX){
		fprintf(stderr, "N is too large!\n");
	}
	srand(seed);
	for(i=1; i<=n; i++){
		d[i] = rand() % 100000;
	}
	fprintf(stdout, "\nInput data:\n");
	for(i=1; i<=n; i++){
		fprintf(stdout, "d[%3d]: data = %7d\n ",i, d[i]);
	}
	radix_sort(n);
	fprintf(stdout, "\nOutput data:\n");
	for(i=1;i<=n;i++){
		fprintf(stdout, "d[%3d]: data = %7d\n ",i, d[i]);
	}
	return 0;
}

