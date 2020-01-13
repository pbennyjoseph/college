/*
Name: P Benny Joseph
Date: 13 Jan 2020
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct PQ{
	int * a;
	int mode;
	int N;
	int size;
} PQ;

void swap(int * a ,int * b){
	int t=*a;*a=*b;*b=t;
}

void debugarr(PQ * pq){
	int i;
	printf("%d %d\n",pq->size,pq->N);
	for(i=1;i <= pq->N;++i){
		printf("%d ",pq->a[i]);
	}
	printf("\n");
}

// To resize arrays dynamically
void resize(PQ * pq,int k){
	int i;
	int * temp = (int * ) malloc(sizeof(int)*k);
	if(temp){
		for(i=1;i <= pq->size;++i){
			temp[i] = pq->a[i];
		}
		free(pq->a);
		pq->a = temp;
		pq->N = k;
	}
	else return;
}

// returns true if it is appropriate PQ;
bool comp(PQ * pq,int parent, int child){
	if(pq->mode){
		return pq->a[child] < pq->a[parent];
	}
	else{
		return pq->a[child] > pq->a[parent];
	}
}

// after insertion fix heap property from leaf
void swim(PQ * pq, int k){
	while(k > 1 && !comp(pq,k/2,k)){
		swap(pq->a + k,pq->a + k/2);
		k /= 2;
	}
}

// fix heap property at root as k;
void sink(PQ * pq,int k){
	while (2*k <= pq->size) {
		int j = 2*k;
		if (j < pq->size && comp(pq,j+1,j) ) j++;
		if (comp(pq,k, j)) break;
		swap(pq->a + k, pq->a + j);
		k = j;
	}
}

// insert element into pq;
void insert(PQ * pq,int elem){
	
	if(pq->size == pq->N-1){
		resize(pq,2*(pq->N));
	}
	pq->a[++pq->size] = elem;
	swim(pq,pq->size);
	// debugarr(pq);
}

// peek top element at PQ;
int top(PQ * pq){
	if(pq->size == 0){
		printf("\n Empty PQ \n");
		return -1;
	}
	return pq->a[1];
}

// delete top element at PQ;
void del(PQ *pq){
	if(pq->size == 0){
		printf("\n Empty PQ \n");
		return;
	};
	int elem = pq->a[pq->size];
	swap(pq->a + 1,pq->a + pq->size-- );
	sink(pq,1);
	int n=pq->size;
	if((n>0) && n == (pq->N - 1)/4)
		resize(pq,pq->N/2);
	// debugarr(pq);
}

int main(){
    int mode,mxsz,currentSize,q,i,elem;
	PQ pq;
	printf("Enter 0 for minPQ and 1 for maxPQ\n");
	if(!scanf("%d",&mode)) return 0;
	
	pq.N = 2;
	pq.a = (int *) malloc(sizeof(int)*pq.N);
	pq.size = 0;
	pq.mode = mode;
	
	printf("Enter queries of type '1 push' or '2' to top Min/Max\n'3' to delete\n");
	printf("EOF to quit\n");
	while(scanf("%d",&q)){
		switch(q){
			case EOF: return 0;
			case 1:
					if(!scanf("%d" , &elem)) return 0;
					insert(&pq,elem);
					break;
			case 2:
					printf("Top element is %d\n",top(&pq));
					break;
			case 3:
					del(&pq);
					break;
			default:
				printf("Enter correct query\n");
		}
		// debugarr(&pq);
	}
	free(pq.a);
    return 0;
}