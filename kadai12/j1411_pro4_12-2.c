#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
int d[MAX];

void downheap(int j, int k){
	int i,v;
	v = d[j];
	while(j <= k/2){
		i= 2*j;
		if(i<k && d[i] > d[i+1]){
			i++;
		}
		if(v <= d[i] || i>k){
			break;
		}
		d[j] = d[i]; 	d[i] = v;
		j = i;
	}
}

void heap_sort(int n){
	int i,j,k,t;
	for(j = n/2; j >= 1; j--){
		downheap(j,n);
	}
	k = n;
	while(k > 1){
		t = d[1];
		d[1] = d[k];
		d[k] = t;
		downheap(1,--k);
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
		fprintf(stdout, "N is too large!");
	}
	srand(seed);
	for(i=1; i<=n; i++){
		d[i] = (rand()*rand()/1000) % 100;
	}
	fprintf(stdout, "\nInput data:\n");
	for(i=1; i<=n; i++){
		fprintf(stdout, "d[%3d]: data = %5d\n ",i, d[i]);
	}
	heap_sort(n);
	fprintf(stdout, "\nOutput data:\n");
	for(i=1;i<=n;i++){
		fprintf(stdout, "d[%3d]: data = %5d\n ",i, d[i]);
	}
	return 0;
}

