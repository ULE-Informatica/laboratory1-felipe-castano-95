# dps-lab-1
Laboratory 1 - Luis Felipe Castaño

1. Enumerate those Rules and Recommendation associated that are broken in the previous source code file.
2. Fix any kind of error or mistake. Add a comment explaining your approach for solving it.

Original position | Position after comments and changes | Error/Rule/Recommendation | Comments 
--- | --- | --- | --- 
18 | 11 | STR11-C: A char array does not need a null-terminated byte. |  Null-terminated byte was eliminated
 --- | --- | --- | --- 
22 - 25 | 17 | Error: C does not support Raw Strings Literals | -
 --- | --- | --- | --- 
28 - 35 | 25 - 32 | Warning: ‘return’ with a value, in function returning void | Changed == NULL to != NULL 
--- | --- | --- | --- 
37 - 44 | 38 - 50 | STR30-C. Do not attempt to modify string literals | Adding memcpy to the process and the new parameters 
--- | --- | --- | --- 
47 - 57 |58 - 68 |MSC34-C: Do not use deprecated or obsolescent functions. |TR35-C: Do not copy data from an unbounded source to a fixed-length array |fgets instad get
--- | --- | --- | --- 
68 - 73 | 79 - 80 |
STR31-C: Guarantee that storage for strings has sufficient space for character data and the null terminator | Changed strlen to wcslen and initialization  chart to wchar_t
--- | --- | --- | --- 
78 - 80 | 92 - 97 | MSC34-C: Do not use deprecated or obsolescent functions. | TR35-C: Do not copy data from an unbounded source to a fixed-length  | Changed deprecated function and adding the null-terminated byte 
--- | --- | --- | --- 
98 | 119 | STR32-C. Do not pass a non-null-terminated character sequence to a library function that expects a string |
strlen looks for the null-terminated byte and due the variable is not initialized it will not find it. In addition, the size to take into account has to be that of the receptor, that is, array4 
--- | --- | --- | --- 
101 | 122 | STR30-C. Do not attempt to modify string literals | Changed variable initialization 












