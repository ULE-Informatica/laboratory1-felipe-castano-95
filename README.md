# dps-lab-1
Laboratory 1 - Luis Felipe Castaño

1. Enumerate those Rules and Recommendation associated that are broken in the previous source code file.
2. Fix any kind of error or mistake. Add a comment explaining your approach for solving it.

Original position | Position after comments and changes | Error/Rule/Recommendation | Comments 
:-----:  | :-----:  | :-----: | :-----:  
18 | 11 | STR11-C: A char array does not need a null-terminated byte. |  Null-terminated byte was eliminated
22 - 25 | 17 | Error: C does not support Raw Strings Literals 
28 - 35 | 25 - 32 | Warning: ‘return’ with a value, in function returning void | Changed == NULL to != NULL 
37 - 44 | 38 - 50 | STR30-C. Do not attempt to modify string literals | Adding memcpy to the process and the new parameters 
47 - 57 |58 - 68 |MSC34-C: Do not use deprecated or obsolescent functions. |TR35-C: Do not copy data from an unbounded source to a fixed-length array |fgets instad get 
68 - 73 | 79 - 80 | STR31-C: Guarantee that storage for strings has sufficient space for character data and the null terminator | Changed strlen to wcslen and initialization  chart to wchar_t
78 - 80 | 92 - 97 | MSC34-C: Do not use deprecated or obsolescent functions. | TR35-C: Do not copy data from an unbounded source to a fixed-length  | Changed deprecated function and adding the null-terminated byte 
98 | 119 | STR32-C. Do not pass a non-null-terminated character sequence to a library function that expects a string | strlen looks for the null-terminated byte and due the variable is not initialized it will not find it. In addition, the size to take into account has to be that of the receptor, that is, array4 
101 | 122 | STR30-C. Do not attempt to modify string literals | Changed variable initialization 




3. Compile the file using a software tool for managing the build process using a compiler-independent method (Cmake, scons, etc)

    1. Adapt the process for using different compilation tools and parameters (gcc vs g++), -Wall, standards (-std=c99 and -std=c11) 

    The source code was compiled with standards 99 and 11, following the commands below:
    * gcc -std=c99 -Wall -g3 -o exampleStringsc99 exampleStrings.c  2> logsc99.txt
    * gcc -std=c11 -Wall -g3 -o exampleStringsc11 exampleStrings.c  2> logsc11.txt

    2. Compare between different two standards 

    All insecure  funcitons where deprecated with the C11 standard.

    For example, for lines 92 - 97 using the strcpy_s and strcat_s functions, it is not necessary to add the null-terminated byte. however, GCC does not include the entire standard and therefore it was not possible to add these functions









