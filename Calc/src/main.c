#pragma warning(disable:4996)

#include"Global.h"
#include"Error.h"
#include"vld.h"
#include<stdio.h>

int main(int argc, char const* argv[])
{
  FILE* in = stdin;
  char* line = NULL;
  error_t current_Error = ERR_OK;

  if (argc > 2)
  {
    printf("ERROR: Too much arguments for call\n");
    return -1;
  }

  if (argc > 1 && (in = fopen(argv[1], "r")) == NULL)
  {
    printf("ERROR: Cannot open file '%s'\n", argv[1]);
    return -1;
  }

  if (in != stdin)
    fclose(in);
  return 0;
}