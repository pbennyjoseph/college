#include <stdio.h>
#include <stdlib.h>

typedef struct Edge
{
    int u,v;
	int weight;
} Edge;

int comp(const void * a,const void * b){
	Edge * x = (Edge *) a;
	Edge * y = (Edge *) b;
	return (x->weight - y->weight);
}

int id[3001], sz[3001],cnt,N;

int find(int p);
void merge(int a,int b);
int connected(int a,int b);
void init(int);
void del();


int main(){
	int n,m,u,v,w;
	int mincost = 0;
	
	scanf("%d %d",&n,&m);
	init(n);
	
	Edge * edges = (Edge *) malloc(sizeof(Edge)*(m));
	
	for(int i = 0;i < m; ++i){
		scanf("%d %d %d",&edges[i].u,&edges[i].v,&edges[i].weight);
	}
	
	// Sort based on edge-weights
	qsort((void *)edges,m,sizeof(Edge),comp);
	
	for(int i = 0;i < m; ++i){
		if(!connected(edges[i].u,edges[i].v)){
			merge(edges[i].u,edges[i].v);
			mincost += edges[i].weight;
		}
		// printf("%d %d %d\n",edges[i].u,edges[i].v,edges[i].weight);
	}
	
	printf("Minimum Cost is %d\n",mincost);
	
	// De-allocate memory
	free(edges);
	// Destruct Union-Find
	// del();
	return 0;
}

void init(int n){
	int i;
	N = n+1;
	// id = (int *) malloc(sizeof(int)*N);
	// sz = (int *) malloc(sizeof(int)*N);
	for(i=1;i<=N;++i){
		id[i] = i;
		sz[i] = 1;
	}
}

void del(){
	// if(id) free(id);
	// if(sz) free(sz);
}

int find(int p){
	while(id[p]!=p){
		id[p] = id[id[p]];
		p = id[p];
	}
	return p;
}

void merge(int a,int b){
	int i = find(a);
	int j = find(b);
	if(i==j) return;
	if(sz[i] < sz[j]){
		id[i] = j;
		sz[j] += sz[i];
	}
	else{
		id[j] = i;
		sz[i] += sz[j];
	}
}

int connected(int a,int b){
	return find(a)==find(b);
}