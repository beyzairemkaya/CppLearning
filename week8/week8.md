Dynamöic memoryy allocation

C++ supports three basic types of memory allocation, of which you’ve already seen two.

Static memory allocation happens for static and global variables. Memory for these types of variables is allocated once when your program is run and persists throughout the life of your program.
Automatic memory allocation happens for function parameters and local variables. Memory for these types of variables is allocated when the relevant block is entered, and freed when the block is exited, as many times as necessary.
Dynamic memory allocation is the topic of this article.

Note that accessing heap-allocated objects is generally slower than accessing stack-allocated objects. Because the compiler knows the address of stack-allocated objects, it can go directly to that address to get a value. Heap allocated objects are typically accessed via pointer. This requires two steps: one to get the address of the object (from the pointer), and another to get the value.

The allocation and deallocation for stack objects is done automatically. There is no need for us to deal with memory addresses -- the code the compiler writes can do this for us.

The allocation and deallocation for heap objects is not done automatically. We need to be involved. That means we need some unambiguous way to refer to a specific heap allocated object, so that we can request its destruction when we’re ready. And the way we reference such objects is via memory address.

When we use operator new, it returns a pointer containing the memory address of the newly allocated object. We generally want to store that in a pointer so we can use that address later to access the object (and eventually, request its destruction).