#include<iostream>
#include<climits>
using namespace std;

void swap(int *a,int *b);

class MinHeap{
	int capacity;
	int *harr;
	int heapSize;

public:
	MinHeap(int capacity);

	void insertKey(int i);

	void deleteKey(int i);

	int getMin(){
		return harr[0];
	}

	int extractMin();

	void decreaseKey(int i,int newVal);

	void heapify(int );

	int parent(int i){
		return (i-1)/2;
	}

	int left(int i){
		return (2*i+1);
	}

	int right(int i){
		return (2*i+2);
	}


};

MinHeap::MinHeap(int cap){
	capacity=cap;
	heapSize=0;
	harr=new int[cap];

}



void MinHeap::insertKey(int k){
	if(heapSize==capacity)
	{
		cout<<"Overflow\n";
		return;
	}
	heapSize++;
	int i=heapSize-1;
	harr[i]=k;
	while(i!=0 && harr[parent(i)]>harr[i])
	{
		swap(&harr[parent(i)],&harr[i]);
		i=parent(i);
	}
}

void MinHeap::decreaseKey(int i,int newVal){
	harr[i]=newVal;
	while(i!=0 && harr[parent(i)]>harr[i])
	{
		swap(&harr[parent(i)],&harr[i]);
		i=parent(i);
	}


}

void MinHeap::deleteKey(int i){
	decreaseKey(i,INT_MIN);
	extractMin();
}

int MinHeap::extractMin(){
	if(heapSize<0)
	{
		return INT_MAX;
	}
	if(heapSize==0){
		heapSize--;
		return harr[0];
	}
	int root=harr[0];
	harr[0]=harr[heapSize-1];
	heapSize--;
	heapify(0);

	return root;
}

void MinHeap::heapify(int i){
	int l=left(i);
	int r=right(i);
	int smallest=i;
	if(l<heapSize && harr[l]<harr[i])
		smallest=l;
	if(r<heapSize && harr[r]<harr[smallest])
		smallest=r;
	if(smallest!=i)
	{
		swap(&harr[smallest],&harr[i]);
		heapify(smallest);
	}
}

void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

int main(){
	

	}
    

