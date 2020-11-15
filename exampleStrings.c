#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <wchar.h>

char array1[] = "Foo" "bar";
/**
* STR11-C: A char array does not need a null-terminated byte. Null-terminated byte was eliminated
*/
char array2[] = { 'F', 'o', 'o', 'b', 'a', 'r' };
 
enum { BUFFER_MAX_SIZE = 1024 };
/*
* Error: C does not support Raw Strings Literals
*/
const char* s1 = "\nHello\nWorld\n";
const char* s2 = "\nHello\nWorld\n";

/*
* Waring: ‘return’ with a value, in function returning void 
* Changed == NULL to != NULL
* 
*/
void gets_example_func(void) {
  char buf[BUFFER_MAX_SIZE];
 
  if (fgets(buf, sizeof(buf), stdin) != NULL) {
    buf[strlen(buf) - 1] = '\0';
    printf("%s", buf);
  }
}

/*
* STR30-C. Do not attempt to modify string literals
* Adding memcpy to the process and the new parameters
*/
char *get_dirname(const char *pathname, char *dirname, size_t size) {
  const char *slash;
  slash = strrchr(pathname, '/');
  if (slash) {
    ptrdiff_t slash_idx = slash - pathname;
    if ((size_t)slash_idx < size) {
      memcpy(dirname, pathname, slash_idx);
      dirname[slash_idx] = '\0';  
      return dirname;
    }
  }
  return 0;
}
 

/*
* MSC34-C: Do not use deprecated or obsolescent functions.
* TR35-C: Do not copy data from an unbounded source to a fixed lengt harray
* fgets instad get
*/
void get_y_or_n(void) {  
	char response[8];

	printf("Continue? [y] n: ");
  fgets(response, sizeof(response), stdin);

	if (response[0] == 'n') 
		exit(0);  

	return;
}

 
int main(int argc, char *argv[])
{
    char key[24];
    char response[8];
    char array3[16];
    char array4[16];
    char array5 []  = "01234567890123456";
    char ptr_char[]  = "new string literal";
    int size_array1 = wcslen(L"аналитик"); // Changed strlen to wslen
    wchar_t analitic1[]  = L"аналитик";
    printf("%i\n", size_array1);
    wprintf (L"You entered %u characters.\n",wcslen(analitic1));

    char dirname[260];
    if (get_dirname(__FILE__, dirname, sizeof(dirname))) {
      puts(dirname);
    }

    /*
    * Changed deprecated function and adding Null-terminated byte
    */
    strncpy(key, argv[1], sizeof(key));  
    key[sizeof(key)-1]='\0';
    strncat(key, " = ", 2);
    key[sizeof(key)-1]='\0';
    strncat(key, argv[2], sizeof(key));
    key[sizeof(key)-1]='\0';


    fgets(response,sizeof(response),stdin);
    
    get_y_or_n();

    printf ("%s",array1);
    printf ("\n");
    printf ("%s",array2);
    printf ("\n");
 
    puts (s1);
    printf ("\n");
    puts (s2);
    printf ("\n");
    
    strncpy(array3, array5, sizeof(array3));
    /*
    * strlen looks for the null-terminated byte and due the variable is not initialized it will not find it
    * In addition, the size to take into account has to be that of the recepter, that is, array4
    */  
    strncpy(array4, array3, sizeof(array4));
    
    array5 [0] = 'M';
    ptr_char [0] = 'N'; // Changed variable initialization
    printf("%s\n", ptr_char);
    
    array3[sizeof(array3)-1]='\0';
    
    return 0;
}
