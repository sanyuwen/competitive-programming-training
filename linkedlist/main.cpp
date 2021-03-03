#include<cstdio>
using namespace std;

#define m 64

//values[0] as dummy head node
// node[i] = {values[i], nextn[i], nextn[i]}
// so nextn[0] is the first node while nextn[0] is the last
int values[m] = { 0 }, nextn[m] = { 0 }, prevn[m] = { 0 };

void insert_node(int i ,int x){
    //insert node at x before node at i
    nextn[x]=i;
    prevn[x] = prevn[i];
    nextn[prevn[i]] = x;
    prevn[i] = x;
}

void delete_node (int x){
    //delete node at x
    nextn[prevn[x]]=nextn[x];
    prevn[nextn[x]]=prevn[x];
}

void set_value(int i, int v){
    //set value
    values[i]=v;
}

void append(int x){
    //append node at x
    insert_node(0, x);
}

void tranverse(){
    int p=0;
    while(p=nextn[p]) printf("%d,", values[p]);
    printf("\n");
}

int main(){
    append(1);
    set_value(1, 1);
    append(2);
    set_value(2, 3);
    insert_node(2, 3);
    set_value(3, 5);
    tranverse();
	return 0;
}