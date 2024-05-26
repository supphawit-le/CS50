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
      '''
      For each door from left to right
         If 50 is behind door
            Return true
      Return false
      '''
   *example2*
      '''
      If no doors left
         Return false
      If 50 is behind middle door
         Return true
      Else if 50 < middle door
         Search left half
      Else if 50 > middle door
         Search right half
      '''
## Struct for convert array to object
   *search by array*
      '''
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
      '''

      *search by object
      '''
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

      '''
## Algorithm for merge sort
![Mertsort](https://github.com/supphawit-le/CS50/blob/main/image/merge%20sort.png)
