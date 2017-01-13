#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
int d[MAX];

void downheap(int j, int k){
	int i,v;
	v = d[j];
	while(j <= k/2){
		i= 2*j;
		if(i<k && d[i] < d[i+1]){
			i++;
		}
		if(v >= d[i] || i>k){
			break;
		}
		d[j] = d[i]; 	d[i] = v;
		j = i;
	}
}

void print_heap(int n){
	int i,j,k;
    int s,t;
	int l,m;
	int flag,first;

	l=0; m=1;
	i = n; s = 0;
	while(i >= 1){
	   i /= 2;
	   l++;
	}
	for(i=0;i<l;i++){
		m *= 2;
	}
	
	for(i=0;i<m;i++){
		fprintf(stdout, "==");
	}
	fprintf(stdout,"\n\n");
	
	for(i=1;i<=l;i++){
		t=1;
		for(j=0;j<i;j++){
			t *= 2;
		}
		
		for(j=0;j<i;j++){
            for(k=0;k<m/t-1;k++){
				fprintf(stdout,"  ");
            }
            if(s < n){
                fprintf(stdout,"%d",d[s]);
                if(d[s++] < 0 ) fprintf(stdout," ");
            }
            for(k=0;k<m/t;k++){
				fprintf(stdout,"  ");
            }

		}
		fprintf(stdout,"\n");
	}
	fprintf(stdout,"\n\n");
}

void heap_sort(int n){
	int i,j,k,t;
	fprintf(stdout, "****** heap down ******\n");
	for(j = n/2; j >= 1; j--){
		downheap(j,n);
		print_heap(n);
	}
	k = n;
	fprintf(stdout, "****** sorting ******\n");
	while(k > 1){
		t = d[1];
		d[1] = d[k];
		d[k] = t;
		downheap(1,--k);
		print_heap(n);
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
        d[i] = (d[i]+100) % 100;
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

