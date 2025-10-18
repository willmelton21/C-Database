#include <stdio.h>
#include <stdbool.h>
#include <getopt.h>
#include <stdlib.h>

#include "common.h"
#include "file.h"
#include "parse.h"

void print_usage(char *argv[]) {

  printf("Usage:\n %s -n -f <database file> -a <new Employee>\n",argv[0]);
  printf("\t -n - Create a new Database file\n");
  printf("\t -f - (required) List a filepath for database file\n");
  printf("\t -a - Creates a new entry in the database <name>,<address>,<ID>\n");
  return;
}

int main(int argc, char *argv[]) { 

  char c;
  char* filepath = NULL;
  char* newEmployee = NULL; 
  bool newFile = true;
  while ((c = getopt(argc, argv, "nf:a:")) != -1){
    switch (c){
      case 'n':
        newFile = true;
        break;
      case 'f':
        filepath = optarg;
        break;
      case 'a':
        newEmployee = optarg;
        break;
      case '?':
        printf("Unkown option -%c\n",c);
        break;
      default:
        return -1;
      }
    }


  if (filepath == NULL) {
    printf("filepath is required\n");
    print_usage(argv);
  }

  printf("Newfile: %d\n",newFile);
  printf("New Employee: %s\n",newEmployee);
  printf("filepath %s\n", filepath);
  return 0;
	
}
