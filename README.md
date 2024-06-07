# Lecture1_C

## manual
https://manual.cs50.io/ \
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

## Algorithm for merge sort
![Mertsort](https://github.com/supphawit-le/CS50/blob/main/image/merge%20sort.png)


# Lecture4_Memory
## Base-16
   * 00 = 0
   * FF = 255
## Pointer Operator
   * __&__ to find the address of memory that the variable stored

         #include <stdio.h>

         int main(void)
         {
            int n =50;
            printf("%p\n",&n);
         }

   * __*__ to identify the address in memory (POINTER)

         #include <stdio.h>

         int main(void)
         {
            int n =50;
            int *p = &n;
            printf("%p\n",p);
         }
      * *p is the pointer parameter that store the number of address of n
      * *p (address of n) --> n --> 50

![Mertsort](https://github.com/supphawit-le/CS50/blob/main/image/POINTER.png)

![Mertsort](https://github.com/supphawit-le/CS50/blob/main/image/POINTER_string.png)
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
   * Example1

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

