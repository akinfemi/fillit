#include "fillit.h"
#include <stdio.h>
int main() {
  
  char *str = "....\n###.\n..#.\n....\n";
  char **sd = ft_split(str,'\n');
  while(*sd)
  {
  	printf("Tetris:\n%s\n", *sd);
  	if (isvalid(*sd) == 0)
  		printf("Not Valid!\n");
  	else
  		printf("Valid\n");
  	sd++;
  }
      return 0;
  }

// int		main(void)
// {
// 	char *big = "###.\n..#";
// 	char *little = "##..\n..##\n...#\n...#";

// 	return (0);
// }