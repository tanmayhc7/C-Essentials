#include <stdio.h>
#include <stdlib.h>

static const int hash_table_size=10;
static const int key_size=5;

typedef struct{
	char key[key_size];//Person Name (for this implementation)
	int data;//Person Age (for this implementation)
}hash_node;

hash_node* hash_table[hash_table_size];

int hash_code(char* s){
  int sum=0;
  for(int i=0;i<strlen(s);i++){
    sum+=s[i];
  }
  return (sum)%(hash_table_size);
}

void init_hash_table(void){
	for(int i=0;i<hash_table_size;i++){
		hash_table[i]=NULL;
	}	
}

void print_table(void){
	
	for(int i=0;i<hash_table_size;i++){
		if(!hash_table[i])printf("\t-----\t--");
		else{
			printf("\t%s\t%d",hash_table[i]->key,hash_table[i]->data);
		}
		printf("\n");
	}
}

bool insert(char* s,int age){
	
}



int main(void){
	init_hash_table();
	print_table();
	return 0;
}
