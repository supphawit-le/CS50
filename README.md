# Lecture1_C

## manual
https://manual.cs50.io/ \
https://manual.cs50.io/#stdio.h \
https://manual.cs50.io/#cs50.h \
https://clang.llvm.org/

## Complie
***sorce code --> COMPLIE --> machine code***

|source code|Complier|machine code|
|-----------|--------|------------|
|C,C++,python|make,clang,...|1100100101..|

## command-line with vs code
    code hello.c    #to open source code with vscode
    make hello      #to comply source code to mechine code
    ./hello         #to run the C code hello

# Lecture2_Array

## other complier tools in linux?
    clang hello.c   #to comply source code to mechinecode (output file = a.out -> run -> ./a.out)
    clang -o hello hello.c  #output file = hello -> run -> ./hello
    clang -o hello hello.c -lcs50 #output file = hello and add library cs50.h (l => link)
## step of make command (complie)
1. Preprocessing \
   ***To get include file from ...(/usr/include)***
   1. #include <cs50.h> *<-- string get_string(string prompt);*
   2. #include <stdio.h> *<-- int printf(string format,...);*
   ***Q/A : if the .h file have all function the machine code will have many many byte. (Separating .h file related to performance)***
2. Compiling \
   ***To convert C to assembly code***\
   ![assemblycode](https://github.com/supphawit-le/CS50/blob/172d81ad6f5e4d2b88de5eca1f923bfdce8b5f57/image/assemblycode.jpg)
3. Assembling \
   ***To convert assembly code to machine code (11001..)***
4. Linking \
   ***To combine machine code from hello.c ,cs50.c,stdio.c to the one***

_Decomplie = revert engineer (it's possible but not 100%, for example: for loop and while loop, the machine code cannot decomplie to which loop)_

## Debugging
1. prinf
2. Debugger
   1. in VS code mark the red dot in front of number line = mark stop point
   2. cmd : debug50 ./hello
   3. there are tools like video player in above
   4. click the tools to run step by step

## Memory and Type
![Memory](https://github.com/supphawit-le/CS50/blob/1d0355e6179f80ae5d0ea01937542310b81c44b9/image/IMG_1143.jpeg)

|Type|Memory|
|-----|------|
|bool|1 byte|
|int|4 byte|
|long|8 byte|
|float|4 byte|
|double|8 byte|
|char|1byte|
|string|? bytes|

### Memory allocation
![Memoryint](https://github.com/supphawit-le/CS50/blob/1d0355e6179f80ae5d0ea01937542310b81c44b9/image/IMG_1141.jpeg)
#### Actual logic in memory
![Memorybit](https://github.com/supphawit-le/CS50/blob/1d0355e6179f80ae5d0ea01937542310b81c44b9/image/IMG_1142.jpeg)

## String
string HI! = |H|I|!|\0| (the end of string is char '\0')
for print char in string (indevidual) = printf ("%c %c" ,name[0],name[1])
![Memorystring](https://github.com/supphawit-le/CS50/blob/1d0355e6179f80ae5d0ea01937542310b81c44b9/image/IMG_1144.jpeg)


## exit status
- error code : 1420
- status code :404
- look code in status.c (arg in function main)
  - if ./status => Missing command-line argument
  - and then use "echo $?" => 1 (follow return in main) like statuscode
  - if ./status supphawit => hello supphawit
  - and then use "echo $?" => 0

## encryption
* input --> | encryption | --> output
* plaintext + key --> | cipher | --> ciphertext
  * HI! + {key : 1} --> | encryption | --> IJ!
  * "UIJT XBT DT50" + {key : -1} --> | decryption | --> THIS IS CS50

# Lecture3_Algorithms
## Search algorithms
  - [No] search name each page from first to end
  - [Yes] Search from half book page and cut follow alphabet
## Sudo code
   *example1*

      For each door from left to right
         If 50 is behind door
            Return true
      Return false

   *example2*

      If no doors left
         Return false
      If 50 is behind middle door
         Return true
      Else if 50 < middle door
         Search left half
      Else if 50 > middle door
         Search right half

## Struct for convert array to object
   *search by array*


      #include <cs50.h>
      #include <stdio.h>
      #include <string.h>

      int main(void)
      {

         string names[] = {"Carter", "David"};
         string numbers[] = {"08222222222", "08333333333"};

         string name = get_string("Name : ");
         for (int i=0 ; i< 2 ;i++)
         {
            if(strcmp(names[i],name) == 0 ){
                  printf ("Found %s\n",numbers[i]);
                  return 0;
            }
         }
         printf("Not Found\n");
         return 1;
      }

   *search by object*

         #include <cs50.h>
         #include <stdio.h>
         #include <string.h>

         typedef struct
         {
            string name;
            string number;
         }
         person;


         int main(void)
         {
            person people[2];

            people[0].name = "Carter";
            people[0].number = "0822222222";

            people[1].name = "David";
            people[1].number = "0833333333";

            string name = get_string("Name : ");
            for (int i=0 ; i< 2 ;i++)
            {
               if(strcmp(people[i].name,name) == 0 ){
                     printf ("Found %s\n",people[i].number);
                     return 0;
               }
            }

            printf("Not Found\n");
            return 1;
         } 
         
## Key Topics

- Algorithms
  - Thinking algorithmically: mapping real-world problems to code solutions.
  - Divide and conquer strategy.
- Data Structures
  - Arrays: contiguous memory blocks for storing data.
- Searching Algorithms
  - Linear search: checking elements sequentially.
  - Binary search: dividing sorted data to locate elements.
- Efficiency Analysis
  - Big-O notation: characterizing algorithm performance.
  - Omega notation: best-case performance.
  - Theta notation: performance bounds.
- Sorting
  - The concept of sorting: transforming unsorted data into ordered data.

## Examples & Concepts

### Example: Phone Book Algorithm
1. **Linear Search**: Checking page by page (O(n)).
2. **Binary Search**: Dividing the phone book in half (O(log n)).

### Group Activity
- Counting attendees using various algorithms: demonstrating efficiency differences.

### Data Structures in Practice
- `Array`: indexed collection of items.
- Simulating phone book functionality using arrays.

### Implementing Search Algorithms in C
1. Using arrays to store data.
2. Comparing strings using `strcmp` from `<string.h>`.
3. Structuring code for clarity.

### Sorting Activity
- Volunteers physically sorting themselves to demonstrate sorting algorithms.

## Big-O Notation Examples
1. **Linear Search**: O(n) - checks each element.
2. **Binary Search**: O(log n) - halves data each iteration.

### Pseudocode Examples

#### Linear Search
```
for i from 0 to n-1:
    if array[i] == target:
        return true
return false
```

#### Binary Search
```
if target == middle_element:
    return true
elif target < middle_element:
    search left half
else:
    search right half
```

## Concepts in C

### Code Examples
- Implementing algorithms in C using `for` loops and arrays.
- Handling strings with `strcmp` for accurate comparisons.

### Introduction to Structs
- Defining custom data types to group related data.

```c
typedef struct {
    string name;
    string number;
} person;
```

### Optimization & Best Practices
- Using constants for scalability.
- Emphasizing clarity in pseudocode and implementation.


## Sorting Algorithms

Sorting is the process of organizing data in a specified order. Different algorithms have different efficiencies.

### Examples of Sorting Algorithms

1. **Bubble Sort**
   - Description: Repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order.
   - Pseudocode:
   ```
   for i from 0 to n-1:
       for j from 0 to n-i-1:
           if array[j] > array[j+1]:
               swap(array[j], array[j+1])
   ```
   - Efficiency: O(n^2) in the worst and average case, O(n) in the best case (if already sorted).

2. **Selection Sort**
   - Description: Divides the list into a sorted and unsorted section, repeatedly selects the smallest (or largest) element from the unsorted section and moves it to the sorted section.
   - Pseudocode:
   ```
   for i from 0 to n-1:
       min_index = i
       for j from i+1 to n-1:
           if array[j] < array[min_index]:
               min_index = j
       swap(array[i], array[min_index])
   ```
   - Efficiency: O(n^2) in all cases.

3. **Insertion Sort**
   - Description: Builds the sorted list one item at a time by repeatedly picking the next element and inserting it into its proper position.
   - Pseudocode:
   ```
   for i from 1 to n-1:
       key = array[i]
       j = i-1
       while j >= 0 and array[j] > key:
           array[j+1] = array[j]
           j = j-1
       array[j+1] = key
   ```
   - Efficiency: O(n^2) in the worst and average case, O(n) in the best case (if already sorted).

4. **Merge Sort**
   - Description: Divides the array into halves, sorts each half, and then merges them together.
   - Pseudocode:
   ```
   if size of array > 1:
       split array into two halves
       recursively sort both halves
       merge the sorted halves
   ```
   - Efficiency: O(n log n) in all cases.

5. **Quick Sort**
   - Description: Picks a pivot, partitions the array such that elements smaller than the pivot are on the left and larger on the right, then recursively sorts the partitions.
   - Pseudocode:
   ```
   if size of array > 1:
       choose pivot
       partition array into left (smaller), pivot, and right (larger)
       recursively sort left and right
   ```
   - Efficiency: O(n log n) in the best and average case, O(n^2) in the worst case (poor pivot selection).
  

### Comparison of Sorting Algorithms with Omega Notation

| Algorithm      | **Best Case (Ω)** | **Average Case (O)** | **Worst Case (O)** | **Notes**                                |
|----------------|--------------------|-----------------------|---------------------|------------------------------------------|
| Bubble Sort    | Ω(n)              | O(n^2)               | O(n^2)             | Inefficient, rarely used in practice.    |
| Selection Sort | Ω(n^2)            | O(n^2)               | O(n^2)             | Simple but always performs O(n^2) work. |
| Insertion Sort | Ω(n)              | O(n^2)               | O(n^2)             | Good for nearly sorted data.             |
| Merge Sort     | Ω(n log n)        | O(n log n)           | O(n log n)         | Requires extra memory for merging.       |
| Quick Sort     | Ω(n log n)        | O(n log n)           | O(n^2)             | Highly efficient with good pivot choice. |

#### Explanation
1. **Best Case (Ω)**:
   - Indicates the minimum time the algorithm will take (best performance).
   - Example: For Bubble Sort, when the array is already sorted, it takes Ω(n) because it only performs one pass.

2. **Average Case (O)**:
   - Represents the time complexity in a general scenario.
   - Example: For Quick Sort, on average, it takes O(n log n) due to its divide-and-conquer strategy.

3. **Worst Case (O)**:
   - Describes the maximum time the algorithm might take (worst performance).
   - Example: For Quick Sort, in the worst case (poor pivot choice), it takes O(n^2).

### Comparison of Big-O (O) and Omega (Ω)

Big-O and Omega are used to analyze the performance of algorithms. Here's a comparison between them:

| **Aspect**          | **Big-O (O)**                       | **Omega (Ω)**                      |
|----------------------|-------------------------------------|------------------------------------|
| **Definition**       | Represents the upper bound of the algorithm's runtime. | Represents the lower bound of the algorithm's runtime. |
| **Purpose**          | To describe the worst-case scenario. | To describe the best-case scenario. |
| **Indicates**        | The maximum time/resources an algorithm might need. | The minimum time/resources an algorithm will need. |
| **Use Case**         | When analyzing how bad the performance can get. | When analyzing how good the performance can be. |
| **Examples**         | Linear Search: O(n) - check all elements in the worst case. | Linear Search: Ω(1) - find the element at the first position in the best case. |
| **Viewpoint**        | Focuses on the ceiling of performance. | Focuses on the floor of performance. |

#### Summary
- **Big-O** is concerned with the maximum growth rate (upper bound) of the algorithm.
- **Omega** is concerned with the minimum growth rate (lower bound) of the algorithm.

### Conclusion

- **Fastest in General**: Quick Sort, with an average time complexity of O(n log n).
- **Most Stable**: Merge Sort, as it maintains the relative order of equal elements.
- **Easiest to Implement**: Bubble Sort or Insertion Sort for small or simple datasets.

## Algorithm for merge sort
![Mertsort](https://github.com/supphawit-le/CS50/blob/main/image/merge%20sort.png)


# Lecture4_Memory
## Base-16
   * 00 = 0
   * FF = 255
   * In Base-16 (hexadecimal) notation, the prefix 0x is used to indicate that the number following it is in hexadecimal format
        - 0x1A3F = 1 × 16^3 + 10 × 16^2 + 3 × 16^1 + 15 × 16^0 = Equivalent to 6703 in decimal.
## Pointer Operator
   * __&__ to find the address of memory that the variable stored

         #include <stdio.h>

         int main(void)
         {
            int n =50;
            printf("%p\n",&n); //0x7ffec645a19c
         }

   * __*__ to identify the address in memory (POINTER)

         #include <stdio.h>

         int main(void)
         {
            int n =50;
            int *p = &n;
            printf("%p\n",p);  //0x7ffcbcf09a7c
         }
      * *p is the pointer parameter that store the number of address of n
      * *p (address of n) --> n --> 50

![Mertsort](https://github.com/supphawit-le/CS50/blob/main/image/POINTER.png)

* p =  0x123
* *p = 50

![Mertsort](https://github.com/supphawit-le/CS50/blob/main/image/POINTER_string.png)

* s =  0x123
* *s = "HI!"

   * for the string, the point identify only the first character and the end of string is normally "\0"
   * string s = "HI!";  (in normally)
   * char *s = "HI!";   (the C stored the address of first char) (without CS50.h)
   * for print the variable of pointer

         #include <stdio.h>

         int main(void)
         {
            int n =50;
            int *p = &n;
            printf("%p\n",p);   //output : 0x7ffcbdc4402c
            printf("%i\n",*p);  //output : 50
         }
   * for print string without CS50.h (use pointer)

         #include <stdio.h>

         int main(void)
         {
            char *s = "HI!";
            printf("%p\n",s);           //output : 0x59599f756004
            printf("%p\n", &s[0]);      //output : 0x59599f756004
            printf("%p\n", &s[1]);      //output : 0x59599f756005
            printf("%p\n", &s[2]);      //output : 0x59599f756006
            printf("%p\n", &s[3]);      //output : 0x59599f756007

            //print string without CS50.h
            printf("%s\n",s);           //output : HI!
         }

   * Example 1

         #include <stdio.h>

         int main(void)
         {
            char *s = "HI!";
            printf("%s\n", s);      //output : HI!
            printf("%s\n", (s+1));  //output : I!
            printf("%s\n", (s+2));  //output : !
         }


## Point Arithmetic
   * for Print the char with array and pointer in string

         #include <stdio.h>

         int main(void)
         {
            char *s = "HI!";
            //use array
            printf("%c\n", s[0]);  //output : H
            printf("%c\n", s[1]);  //output : I
            printf("%c\n", s[2]);  //output : !

            //use pointer
            printf("%c\n", *s);      //output : H
            printf("%c\n", *(s+1));  //output : I
            printf("%c\n", *(s+2));  //output : !
         }
   * for string comparation

         #include <cs50.h>
         #include <stdio.h>
         #include <string.h>

         int main(void)
         {

            string s = get_string("s: ");
            string t = get_string("t: ");

            if (strcmp(s ,t) == 0)
            {
               printf("Same\n");
            }
            else
            {
               printf("Different\n");
            }
         }
      * if (*s == *t) --> Check only first char in string
      * if (*s == *t && *(s+1) == *(t+1) ....) --> you can use it

   * for copy string to another varible

         #include <stdio.h>
         #include <cs50.h>
         #include <string.h>
         #include <ctype.h>

         int main(void)
         {
            char *s = get_string("s: ");     // input : hi!
            char *t = s;

            if (strlen(t) >0)
            {
               t[0] = toupper(t[0]);
            }
            printf("s : %s\n", s);           // output : Hi! (it is not changed to uppercase)
            printf("t : %s\n", t);           // output : Hi!
         }

      ![Mertsort](https://github.com/supphawit-le/CS50/blob/main/image/copy_string.png)

### function for memory management (include <stdlib.h>)
   * __malloc__  (memory allocation)
   * __free__
   * Example1: malloc

         #include <stdio.h>
         #include <cs50.h>
         #include <stdlib.h> //for call malloc
         #include <ctype.h>
         #include <string.h>

         int main(void)
         {
            char *s = get_string("s: ");     // input : hi!
            char *t = malloc(strlen(s)+1);   // allocate t in the memory

            for (int i = 0; i < strlen(s) + 1; i++)
            {
               t[i] = s[i];                  //copy s to t each char to t's memory
            }

            if (strlen(t) > 0)
            {
               t[0] = toupper(t[0]);
            }
            printf("s : %s\n", s);           // output : hi!
            printf("t : %s\n", t);           // output : Hi!
         }

      ![Mertsort](https://github.com/supphawit-le/CS50/blob/main/image/copy_string2.png)

      * Example2 : free

            #include <stdio.h>
            #include <cs50.h>
            #include <stdlib.h>
            #include <ctype.h>
            #include <string.h>

            int main(void)
            {
               char *s = get_string("s: ");  // input : hi!

               if (s == NULL)
               {
                  return 1;
               }

               char *t = malloc(strlen(s)+1);
               strcpy(t,s);
               if (s == NULL)
               {
                  return 1;
               }


               if (strlen(t) > 0)
               {
                  t[0] = toupper(t[0]);
               }
               printf("s : %s\n", s);      // output : hi!
               printf("t : %s\n", t);      // output : Hi!

               free(t);                    // return memory space to system
               return 0;
            }

         In the C programming language, if you do not use the free() function to release the memory that you have allocated (such as using malloc(), calloc(), or realloc()), that memory will not be returned to the system during the program’s execution. This can lead to memory leaks, causing the program to consume more and more memory over time.

         However, when the program terminates, the operating system will automatically reclaim all the memory that the program had allocated. Therefore, in the case where the program has finished running, all the allocated memory will be returned to the operating system.

         Even though the operating system handles memory reclamation when the program ends, it is still good practice to use the free() function correctly to avoid memory leaks in programs that need to run for extended periods or that use a lot of memory.

### Valgrind (software for check bug in c code)
   * Example1 wrong index in array (but completed complied and run)

         #include <stdio.h>
         #include <stdlib.h>

         int main(void)
         {
            int *x = malloc(3 * sizeof(int));
            x[1] = 72;  //should be x[0]
            x[2] = 73;  //should be x[1]
            x[3] = 34;  //should be x[2]
         }
   * Using valgrind to verify

         $ valgrind ./memory
         ==43881== Memcheck, a memory error detector
         ==43881== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
         ==43881== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
         ==43881== Command: ./memory
         ==43881==
         ==43881== Invalid write of size 4
         ==43881==    at 0x109170: main (memory.c:9)
         ==43881==  Address 0x4bb404c is 0 bytes after a block of size 12 alloc'd
         ==43881==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
         ==43881==    by 0x109151: main (memory.c:6)
         ==43881==
         ==43881==
         ==43881== HEAP SUMMARY:
         ==43881==     in use at exit: 12 bytes in 1 blocks
         ==43881==   total heap usage: 1 allocs, 0 frees, 12 bytes allocated
         ==43881==
         ==43881== 12 bytes in 1 blocks are definitely lost in loss record 1 of 1
         ==43881==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
         ==43881==    by 0x109151: main (memory.c:6)
         ==43881==
         ==43881== LEAK SUMMARY:
         ==43881==    definitely lost: 12 bytes in 1 blocks
         ==43881==    indirectly lost: 0 bytes in 0 blocks
         ==43881==      possibly lost: 0 bytes in 0 blocks
         ==43881==    still reachable: 0 bytes in 0 blocks
         ==43881==         suppressed: 0 bytes in 0 blocks
         ==43881==
         ==43881== For lists of detected and suppressed errors, rerun with: -s
         ==43881== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)

   * __Example2__ correct code

         #include <stdio.h>
         #include <stdlib.h>

         int main(void)
         {
            int *x = malloc(3 * sizeof(int));
            if (x == NULL)
            {
               return 1;
            }
            x[0] = 72;
            x[1] = 73;
            x[2] = 34;
            free(x);
            return 0;
         }

   * Using __valgrind__ to verify

         $ valgrind ./memory
         ==46801== Memcheck, a memory error detector
         ==46801== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
         ==46801== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
         ==46801== Command: ./memory
         ==46801==
         ==46801==
         ==46801== HEAP SUMMARY:
         ==46801==     in use at exit: 0 bytes in 0 blocks
         ==46801==   total heap usage: 1 allocs, 1 frees, 12 bytes allocated
         ==46801==
         ==46801== All heap blocks were freed -- no leaks are possible
         ==46801==
         ==46801== For lists of detected and suppressed errors, rerun with: -s
         ==46801== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
### Garbage value
   * __Example1__ : def variable but not input the value
      * code

            #include <stdio.h>
            #include <stdlib.h>

            int main(void)
            {
               int scores[1024];
               for(int i = 0 ; i < 1024; i++)
               {
                  printf ("%i\n",scores[i]);
               }
            }

      * output (there are many initial value)

            ...
            0
            0
            0
            408660876
            32007
            408822496
            32007
            408572272
            32007
            408573568
            32007
            408574848
            32007
            408576128
            32007
            408820464
            32007
            ...

   * __Example2__ : Swap
      * code (wrong)

            #include <stdio.h>
            #include <stdlib.h>

            void swap(int a, int b);

            int main(void)
            {
               int x = 1;
               int y = 2;

               printf ("x is %i, y is %i\n",x,y);
               swap (x,y);
               printf ("x is %i, y is %i\n",x,y);
            }

            void swap (int a, int b)
            {
               int temp = a;
               a = b;
               b = temp;
            }

      * output

            x is 1, y is 2
            x is 1, y is 2
      * code (correct)

            #include <stdio.h>
            #include <stdlib.h>

            void swap(int *a, int *b);

            int main(void)
            {
               int x = 1;
               int y = 2;

               printf ("x is %i, y is %i\n",x,y);
               swap (&x,&y);
               printf ("x is %i, y is %i\n",x,y);
            }

            void swap (int *a, int *b)
            {
               int temp = *a;
               *a = *b;
               *b = temp;
            }

      * output

            x is 1, y is 2
            x is 2, y is 1
      * In this case, The memory

         ![Mertsort](https://github.com/supphawit-le/CS50/blob/main/image/memory_swap1.png)

      1.	Machine Code - This section contains the executable code of the program.
      2.	Globals - This section holds global variables that are accessible throughout the program.
      3.	Heap - This section is used for dynamic memory allocation, growing downward.
      4.	Stack - This section is used for local variables and function calls, growing upward.

      ___Heap overflow___ occurs when the heap grows too large, exceeding its allocated boundaries. This can overwrite other memory regions, potentially causing program crashes or security vulnerabilities, as unintended memory areas may be modified.

      ___Stack overflow___ happens when the stack exceeds its allocated limit, often due to deep or infinite recursion, or excessive local variable allocation. This can overwrite other memory regions and lead to program crashes or unpredictable behavior.


      ___Buffer overflow___ occurs when more data is written to a buffer (a contiguous block of memory) than it can hold. This can overwrite adjacent memory, potentially causing crashes, corruption of data, or security vulnerabilities by allowing the execution of arbitrary code.

      * Using swap value (in the end stack of swap is distroyed)

         ![Mertsort](https://github.com/supphawit-le/CS50/blob/main/image/memory_swap2.png)

      * Using point to swap

         ![Mertsort](https://github.com/supphawit-le/CS50/blob/main/image/memory_swap3.png)

### Get string without cs50.h
   * __Example1__ : with array

         #include <stdio.h>

         int main(void)
         {
            char s[4];              //s[40] or s[400] or ....
            printf("s: ");
            scanf("%s", s);
            printf("s: %s\n",s);
         }

### Write CSV file
   * __Example1__

         // Save names and numbers to a CSV file

         #include <cs50.h>
         #include <stdio.h>
         #include <string.h>

         int main(void)
         {
            FILE *file = fopen("phonebook.csv", "a"); // a = append mode

            string name = get_string("Name: ");
            string number = get_string("Number: ");

            fprintf (file, "%s,%s\n",name,number);

            fclose(file);
         }
