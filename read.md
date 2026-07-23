what is this?

malloc asks for RAM memory from OS . 

it asks a chunk of memory at once and gives smaller parts of memory as per requirement using my_malloc

free will free the memory once we are done.
my_free marks the memory as free

but how much memory do we ask at once using malloc?
there is no pre-set amout , we ask per request

what is make file?
instead of typing long gcc commands everytime  you just write make

Right now, every time you change even one letter in your code, you have to type this long command in the terminal:
gcc allocator.c -o allocator


what is block for?
before passing to os for memory we first label it
-how big is this chunk
-is it currently being used or is it free?

what is struct?
Usually, variables hold just one thing (like an int holds one number). But sometimes you want to group related information together.

magine you are building a video game. You might create a struct called Player that holds:
int health;
int score;
int x_position;



typedef?
give your struct a nickname....so you dont have to type long things like struct block ; etc etc everytime 

head?
block_t *head = Null means the type of thing is block_t and * means head is a pointer (a variable that holds the adress not the actual block)

why empty? , once we get the memory from OS we will update head with the adress of that new memory block.



why we choose singly linked list for this?
we cant use array cuz we dont know  how many blocks we will need ahead of time , a linkedlist grows dynamically as the calls come in.

no pre-allocated size limit.

and operations are cheap in linked list for adding and marking new blocks o(1)...traversal is o(n). 
(look up how to make it cheaper than o(n))


malloc uses heap?
Yes. When malloc calls sbrk (or brk), it expands the program's heap segment — the memory region between the end of the data segment and the top of the allocated space.
┌─────────────┐
│   Stack     │  (grows down)
├─────────────┤
│             │
│   Free      │
│   Memory    │
│             │
├─────────────┤
│   Heap      │  ← sbrk grows this upward
├─────────────┤
│   Data      │
├─────────────┤
│   Text      │  (code)
└─────────────┘
Your my_malloc does the same thing — sbrk asks the OS to push the heap boundary up, giving you more memory. So yes, both real malloc and your mini version use the heap.