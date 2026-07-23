#include <stdio.h>
#include <unistd.h> //gives acess to OS 
#include<stddef.h>

typedef struct block {
    size_t size ; // how big is the memory chunk
    int is_free; // 1 =free , 0=use
    struct block *next ; //points to the next block in our chain
}block_t;
    
block_t *head = NULL;

#define BLOCK_SIZE sizeof(block_t)

//void* gives raw adress since OS gives raw memory
// void*my_malloc= function holding gives blank memory adress
// voud*memory = variable holding a blank memory adress.

void*my_malloc(size_t size){
    size_t total_size = size + BLOCK_SIZE;
        void*memory = sbrk(total_size); //sbrk (space break) is asking OS to expand the ram for that program by total size 
        if (memory == (void *)-1) {//-1 because its when memory allocation fails and os gives -1
            //(void*) is a cast to take -1 and pretend its a void* pointer
            return NULL;
            //this if statement is for safety check
            // use it to return -1 when the RAM is full
        }
            block_t *new_block = (block_t *)memory;
            //(block_t *)memory means to take raw unmarked memory adress the OS gives you and force C to treat it as block_t
            new_block->size=size;
            new_block->is_free=0;
            new_block->next=NULL ;

            new_block->next=head;
            head=new_block;

             return (void *)(new_block + 1);
            //because of pointer arithmetic , the +1 actually skips size of block_t forward
            // (void*) cast would give you blank memory , by stripping away the block_t label
            // it would give you empty space jitna you have asked



    
}

void my_free(void *ptr) {
    if (ptr == NULL) {
        return; //kuch bhi free karne ko nahi hai toh vapas chale jao
    }
    //(block_t *)ptr means ptr ko block_t type ka pointer banao
    //ptr actually uss jagah ko point kar raha hai jo block ke baad aati hai (user ka data area)
    // isliye (block_t *)ptr - 1 karo matlab ek block_t peeche chale jao, wahan header hai
    block_t *block = (block_t *)ptr - 1;
    block->is_free = 1; //ab ye block free ho gaya, dobara use kar sakte hai
}

int main() {
    
    return 0 ;
}
