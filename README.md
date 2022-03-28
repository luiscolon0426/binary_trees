0x1D. C - Binary trees
======================

-   By Luis Colon

#### In a nutshell...


Resources
---------

**Read or watch**:

-   [Binary tree](https://alx-intranet.hbtn.io/rltoken/1F2x42-8vUbOmU4L1C1KMg "Binary tree") (*note the first line: `Not to be confused with B-tree.`*)
-   [Data Structure and Algorithms - Tree](https://alx-intranet.hbtn.io/rltoken/QmcTMCkQyrgMjrqoWxYdhw "Data Structure and Algorithms - Tree")
-   [Tree Traversal](https://alx-intranet.hbtn.io/rltoken/nMxoYQdZR_guroan8JeqBQ "Tree Traversal")
-   [Binary Search Tree](https://alx-intranet.hbtn.io/rltoken/qO5dBlMnYJzbaWG3xVpcnQ "Binary Search Tree")
-   [Data structures: Binary Tree](https://alx-intranet.hbtn.io/rltoken/BeyJ2gjlE7_djwRiDyeHig "Data structures: Binary Tree")

Learning Objectives
-------------------

At the end of this project, you are expected to be able to [explain to anyone](https://alx-intranet.hbtn.io/rltoken/rDjGcLNoVZsZG1Br0UbX6A "explain to anyone"), **without the help of Google**:

### General

-   What is a binary tree
-   What is the difference between a binary tree and a Binary Search Tree
-   What is the possible gain in terms of time complexity compared to linked lists
-   What are the depth, the height, the size of a binary tree
-   What are the different traversal methods to go through a binary tree
-   What is a complete, a full, a perfect, a balanced binary tree

Requirements
------------

### General

-   Allowed editors: `vi`, `vim`, `emacs`
-   All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
-   All your files should end with a new line
-   A `README.md` file, at the root of the folder of the project, is mandatory
-   Your code should use the `Betty` style. It will be checked using [betty-style.pl](https://github.com/holbertonschool/Betty/blob/master/betty-style.pl "betty-style.pl") and [betty-doc.pl](https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl "betty-doc.pl")
-   You are not allowed to use global variables
-   No more than 5 functions per file
-   You are allowed to use the standard library
-   In the following examples, the `main.c` files are shown as examples. You can use them to test your functions, but you don't have to push them to your repo (if you do we won't take them into account). We will use our own `main.c` files at compilation. Our `main.c` files might be different from the one shown in the examples
-   The prototypes of all your functions should be included in your header file called `binary_trees.h`
-   Don't forget to push your header file
-   All your header files should be include guarded

### GitHub

**There should be one project repository per group. If you clone/fork/whatever a project repository with the same name before the second deadline, you risk a 0% score.**

More Info
---------

### Data structures

Please use the following data structures and types for binary trees. Don't forget to include them in your header file.

#### Basic Binary Tree

```
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;

```

#### Binary Search Tree

```
typedef struct binary_tree_s bst_t;

```

#### AVL Tree

```
typedef struct binary_tree_s avl_t;

```

#### Max Binary Heap

```
typedef struct binary_tree_s heap_t;

```

**Note:** For tasks 0 to 23 (included), you have to deal with simple binary trees. They are not BSTs, thus they don't follow any kind of rule.

### Print function

To match the examples in the tasks, you are given [this function](https://github.com/holbertonschool/0x1C.c "this function")

This function is used only for visualization purposes. You don't have to push it to your repo. It may not be used during the correction

Tasks
-----

### 0\.New node

mandatory


Write a function that creates a binary tree node

-   Prototype: `binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);`
-   Where `parent` is a pointer to the parent node of the node to create
-   And `value` is the value to put in the new node
-   When created, a node does not have any child
-   Your function must return a pointer to the new node, or `NULL` on failure

```
RB13@/tmp/binary_trees$ cat 0-main.c
#include <stdlib.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);

    root->left = binary_tree_node(root, 12);
    root->left->left = binary_tree_node(root->left, 6);
    root->left->right = binary_tree_node(root->left, 16);

    root->right = binary_tree_node(root, 402);
    root->right->left = binary_tree_node(root->right, 256);
    root->right->right = binary_tree_node(root->right, 512);

    binary_tree_print(root);
    return (0);
}
RB13@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 0-main.c 0-binary_tree_node.c -o 0-node
RB13@/tmp/binary_trees$ ./0-node
       .-------(098)-------.
  .--(012)--.         .--(402)--.
(006)     (016)     (256)     (512)
RB13@/tmp/binary_trees$

```

**Repo:**

-   GitHub repository: `binary_trees`
-   File: `0-binary_tree_node.c`

### 1\. Insert left

mandatory


Write a function that inserts a node as the left-child of another node

-   Prototype: `binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);`
-   Where `parent` is a pointer to the node to insert the left-child in
-   And `value` is the value to store in the new node
-   Your function must return a pointer to the created node, or `NULL` on failure or if `parent` is `NULL`
-   If `parent` already has a left-child, the new node must take its place, and the old left-child must be set as the left-child of the new node.

```
RB13@/tmp/binary_trees$ cat 1-main.c
#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    binary_tree_print(root);
    printf("\n");
    binary_tree_insert_left(root->right, 128);
    binary_tree_insert_left(root, 54);
    binary_tree_print(root);
    return (0);
}
RB13@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 1-main.c 1-binary_tree_insert_left.c 0-binary_tree_node.c -o 1-left
RB13@/tmp/binary_trees$ ./1-left
  .--(098)--.
(012)     (402)

       .--(098)-------.
  .--(054)       .--(402)
(012)          (128)
RB13@/tmp/binary_trees$

```

**Repo:**

-   GitHub repository: `binary_trees`
-   File: `1-binary_tree_insert_left.c`

### 2\. Insert right

mandatory


Write a function that inserts a node as the right-child of another node

-   Prototype: `binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);`
-   Where `parent` is a pointer to the node to insert the right-child in
-   And `value` is the value to store in the new node
-   Your function must return a pointer to the created node, or `NULL` on failure or if `parent` is `NULL`
-   If `parent` already has a right-child, the new node must take its place, and the old right-child must be set as the right-child of the new node.

```
RB13@/tmp/binary_trees$ cat 2-main.c
#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    binary_tree_print(root);
    printf("\n");
    binary_tree_insert_right(root->left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_print(root);
    return (0);
}
RB13@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 2-main.c 2-binary_tree_insert_right.c 0-binary_tree_node.c -o 2-right
RB13@/tmp/binary_trees$ ./2-right
  .--(098)--.
(012)     (402)

  .-------(098)--.
(012)--.       (128)--.
     (054)          (402)
RB13@/tmp/binary_trees$

```

**Repo:**

-   GitHub repository: `binary_trees`
-   File: `2-binary_tree_insert_right.c`

### 3\. Delete

mandatory


Write a function that deletes an entire binary tree

-   Prototype: `void binary_tree_delete(binary_tree_t *tree);`
-   Where `tree` is a pointer to the root node of the tree to delete
-   If `tree` is `NULL`, do nothing

```
RB13@/tmp/binary_trees$ cat 3-main.c
#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    binary_tree_insert_right(root->left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_print(root);
    binary_tree_delete(root);
    return (0);
}
RB13@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 3-main.c 3-binary_tree_delete.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 3-del
RB13@/tmp/binary_trees$ valgrind ./3-del
==13264== Memcheck, a memory error detector
==13264== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.
==13264== Using Valgrind-3.10.1 and LibVEX; rerun with -h for copyright info
==13264== Command: ./3-del
==13264==
  .-------(098)--.
(012)--.       (128)--.
     (054)          (402)
==13264==
==13264== HEAP SUMMARY:
==13264==     in use at exit: 0 bytes in 0 blocks
==13264==   total heap usage: 9 allocs, 9 frees, 949 bytes allocated
==13264==
==13264== All heap blocks were freed -- no leaks are possible
==13264==
==13264== For counts of detected and suppressed errors, rerun with: -v
==13264== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
RB13@/tmp/binary_trees$

```

**Repo:**

-   GitHub repository: `binary_trees`
-   File: `3-binary_tree_delete.c`

### 4\. Is leaf

mandatory


Write a function that checks if a node is a leaf

-   Prototype: `int binary_tree_is_leaf(const binary_tree_t *node);`
-   Where `node` is a pointer to the node to check
-   Your function must return `1` if `node` is a leaf, otherwise `0`
-   If `node` is `NULL`, return `0`

```
RB13@/tmp/binary_trees$ cat 4-main.c
#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    int ret;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    binary_tree_insert_right(root->left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_print(root);

    ret = binary_tree_is_leaf(root);
    printf("Is %d a leaf: %d\n", root->n, ret);
    ret = binary_tree_is_leaf(root->right);
    printf("Is %d a leaf: %d\n", root->right->n, ret);
    ret = binary_tree_is_leaf(root->right->right);
    printf("Is %d a leaf: %d\n", root->right->right->n, ret);
    return (0);
}
RB13@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 4-binary_tree_is_leaf.c 4-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 4-leaf
RB13@/tmp/binary_trees$ ./4-leaf
  .-------(098)--.
(012)--.       (128)--.
     (054)          (402)
Is 98 a leaf: 0
Is 128 a leaf: 0
Is 402 a leaf: 1
RB13@/tmp/binary_trees$

```

**Repo:**

-   GitHub repository: `binary_trees`
-   File: `4-binary_tree_is_leaf.c`

### 5\. Is root

mandatory


Write a function that checks if a given node is a root

-   Prototype: `int binary_tree_is_root(const binary_tree_t *node);`
-   Where `node` is a pointer to the node to check
-   Your function must return `1` if `node` is a root, otherwise `0`
-   If `node` is `NULL`, return `0`

```
RB13@/tmp/binary_trees$ cat 5-main.c
#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    int ret;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    binary_tree_insert_right(root->left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_print(root);

    ret = binary_tree_is_root(root);
    printf("Is %d a root: %d\n", root->n, ret);
    ret = binary_tree_is_root(root->right);
    printf("Is %d a root: %d\n", root->right->n, ret);
    ret = binary_tree_is_root(root->right->right);
    printf("Is %d a root: %d\n", root->right->right->n, ret);
    return (0);
}
RB13@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 5-binary_tree_is_root.c 5-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 5-root
RB13@/tmp/binary_trees$ ./5-root
  .-------(098)--.
(012)--.       (128)--.
     (054)          (402)
Is 98 a root: 1
Is 128 a root: 0
Is 402 a root: 0
RB13@/tmp/binary_trees$

```

**Repo:**

-   GitHub repository: `binary_trees`
-   File: `5-binary_tree_is_root.c`

### 6\. Pre-order traversal

mandatory


Write a function that goes through a binary tree using pre-order traversal

-   Prototype: `void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));`
-   Where `tree` is a pointer to the root node of the tree to traverse
-   And `func` is a pointer to a function to call for each node. The value in the node must be passed as a parameter to this function.
-   If `tree` or `func` is `NULL`, do nothing

```
RB13@/tmp/binary_trees$ cat 6-main.c
#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * print_num - Prints a number
 *
 * @n: Number to be printed
 */
void print_num(int n)
{
    printf("%d\n", n);
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    root->left->left = binary_tree_node(root->left, 6);
    root->left->right = binary_tree_node(root->left, 56);
    root->right->left = binary_tree_node(root->right, 256);
    root->right->right = binary_tree_node(root->right, 512);

    binary_tree_print(root);
    binary_tree_preorder(root, &print_num);
    return (0);
}
RB13@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 6-main.c 6-binary_tree_preorder.c 0-binary_tree_node.c -o 6-pre
RB13@/tmp/binary_trees$ ./6-pre
       .-------(098)-------.
  .--(012)--.         .--(402)--.
(006)     (056)     (256)     (512)
98
12
6
56
402
256
512
RB13@/tmp/binary_trees$

```

**Repo:**

-   GitHub repository: `binary_trees`
-   File: `6-binary_tree_preorder.c`

### 7\. In-order traversal

mandatory


Write a function that goes through a binary tree using in-order traversal

-   Prototype: `void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));`
-   Where `tree` is a pointer to the root node of the tree to traverse
-   And `func` is a pointer to a function to call for each node. The value in the node must be passed as a parameter to this function.
-   If `tree` or `func` is `NULL`, do nothing

```
RB13@/tmp/binary_trees$ cat 7-main.c
#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * print_num - Prints a number
 *
 * @n: Number to be printed
 */
void print_num(int n)
{
    printf("%d\n", n);
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    root->left->left = binary_tree_node(root->left, 6);
    root->left->right = binary_tree_node(root->left, 56);
    root->right->left = binary_tree_node(root->right, 256);
    root->right->right = binary_tree_node(root->right, 512);

    binary_tree_print(root);
    binary_tree_inorder(root, &print_num);
    return (0);
}
RB13@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 7-main.c 7-binary_tree_inorder.c 0-binary_tree_node.c -o 7-in
RB13@/tmp/binary_trees$ ./7-in
       .-------(098)-------.
  .--(012)--.         .--(402)--.
(006)     (056)     (256)     (512)
6
12
56
98
256
402
512
RB13@/tmp/binary_trees$

```

**Repo:**

-   GitHub repository: `binary_trees`
-   File: `7-binary_tree_inorder.c`

### 8\. Post-order traversal

mandatory


Write a function that goes through a binary tree using post-order traversal

-   Prototype: `void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));`
-   Where `tree` is a pointer to the root node of the tree to traverse
-   And `func` is a pointer to a function to call for each node. The value in the node must be passed as a parameter to this function.
-   If `tree` or `func` is `NULL`, do nothing

```
RB13@/tmp/binary_trees$ cat 8-main.c
#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * print_num - Prints a number
 *
 * @n: Number to be printed
 */
void print_num(int n)
{
    printf("%d\n", n);
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    root->left->left = binary_tree_node(root->left, 6);
    root->left->right = binary_tree_node(root->left, 56);
    root->right->left = binary_tree_node(root->right, 256);
    root->right->right = binary_tree_node(root->right, 512);

    binary_tree_print(root);
    binary_tree_postorder(root, &print_num);
    return (0);
}
RB13@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 8-main.c 8-binary_tree_postorder.c 0-binary_tree_node.c -o 8-post
RB13@/tmp/binary_trees$ ./8-post
       .-------(098)-------.
  .--(012)--.         .--(402)--.
(006)     (056)     (256)     (512)
6
56
12
256
512
402
98
RB13@/tmp/binary_trees$

```

**Repo:**

-   GitHub repository: `binary_trees`
-   File: `8-binary_tree_postorder.c`

### 9\. Height

mandatory


Write a function that measures the height of a binary tree

-   Prototype: `size_t binary_tree_height(const binary_tree_t *tree);`
-   Where `tree` is a pointer to the root node of the tree to measure the height.
-   If `tree` is `NULL`, your function must return `0`

```
RB13@/tmp/binary_trees$ cat 9-main.c
#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    size_t height;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    binary_tree_insert_right(root->left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_print(root);

    height = binary_tree_height(root);
    printf("Height from %d: %lu\n", root->n, height);
    height = binary_tree_height(root->right);
    printf("Height from %d: %lu\n", root->right->n, height);
    height = binary_tree_height(root->left->right);
    printf("Height from %d: %lu\n", root->left->right->n, height);
    return (0);
}
RB13@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 9-binary_tree_height.c 9-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 9-height
RB13@/tmp/binary_trees$ ./9-height
  .-------(098)--.
(012)--.       (128)--.
     (054)          (402)
Height from 98: 2
Height from 128: 1
Height from 54: 0
RB13@/tmp/binary_trees$

```

**Repo:**

-   GitHub repository: `binary_trees`
-   File: `9-binary_tree_height.c`

### 10\. Depth

mandatory


Write a function that measures the depth of a node in a binary tree

-   Prototype: `size_t binary_tree_depth(const binary_tree_t *tree);`
-   Where `tree` is a pointer to the node to measure the depth
-   If `tree` is `NULL`, your function must return `0`

```
RB13@/tmp/binary_trees$ cat 10-main.c
#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    size_t depth;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    binary_tree_insert_right(root->left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_print(root);

    depth = binary_tree_depth(root);
    printf("Depth of %d: %lu\n", root->n, depth);
    depth = binary_tree_depth(root->right);
    printf("Depth of %d: %lu\n", root->right->n, depth);
    depth = binary_tree_depth(root->left->right);
    printf("Depth of %d: %lu\n", root->left->right->n, depth);
    return (0);
}
RB13@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 10-binary_tree_depth.c 10-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 10-depth
RB13@/tmp/binary_trees$ ./10-depth
  .-------(098)--.
(012)--.       (128)--.
     (054)          (402)
Depth of 98: 0
Depth of 128: 1
Depth of 54: 2
RB13@/tmp/binary_trees$

```

**Repo:**

-   GitHub repository: `binary_trees`
-   File: `10-binary_tree_depth.c`

### 11\. Size

mandatory


Write a function that measures the size of a binary tree

-   Prototype: `size_t binary_tree_size(const binary_tree_t *tree);`
-   Where `tree` is a pointer to the root node of the tree to measure the size
-   If `tree` is `NULL`, the function must return 0

```
RB13@/tmp/binary_trees$ cat 11-main.c
#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    size_t size;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    binary_tree_insert_right(root->left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_print(root);

    size = binary_tree_size(root);
    printf("Size of %d: %lu\n", root->n, size);
    size = binary_tree_size(root->right);
    printf("Size of %d: %lu\n", root->right->n, size);
    size = binary_tree_size(root->left->right);
    printf("Size of %d: %lu\n", root->left->right->n, size);
    return (0);
}
RB13@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 11-binary_tree_size.c 11-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 11-size
RB13@/tmp/binary_trees$ ./11-size
  .-------(098)--.
(012)--.       (128)--.
     (054)          (402)
Size of 98: 5
Size of 128: 2
Size of 54: 1
RB13@/tmp/binary_trees$

```

**Repo:**

-   GitHub repository: `binary_trees`
-   File: `11-binary_tree_size.c`

### 12\. Leaves

mandatory


Write a function that counts the leaves in a binary tree

-   Prototype: `size_t binary_tree_leaves(const binary_tree_t *tree);`
-   Where `tree` is a pointer to the root node of the tree to count the number of leaves
-   If `tree` is `NULL`, the function must return 0
-   A `NULL` pointer is not a leaf

```
RB13@/tmp/binary_trees$ cat 12-main.c
#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    size_t leaves;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    binary_tree_insert_right(root->left, 54);
    binary_tree_insert_right(root, 128);
    binary_tree_print(root);

    leaves = binary_tree_leaves(root);
    printf("Leaves in %d: %lu\n", root->n, leaves);
    leaves = binary_tree_leaves(root->right);
    printf("Leaves in %d: %lu\n", root->right->n, leaves);
    leaves = binary_tree_leaves(root->left->right);
    printf("Leaves in %d: %lu\n", root->left->right->n, leaves);
    return (0);
}
RB13@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 12-binary_tree_leaves.c 12-main.c 0-binary_tree_node.c 2-binary_tree_insert_right.c -o 12-leaves
RB13@/tmp/binary_trees$ ./12-leaves
  .-------(098)--.
(012)--.       (128)--.
     (054)          (402)
Leaves in 98: 2
Leaves in 128: 1
Leaves in 54: 1
RB13@/tmp/binary_trees$

```

**Repo:**

-   GitHub repository: `binary_trees`
-   File: `12-binary_tree_leaves.c`


