#include <stdio.h>

int main(){
int i = 0;

for(i = 0; i < 10; ++i)
  printf("%i\n", i);

printf("----------------------------------------\n\n");

goto init;

init:
  i = 0;
  goto check_condition;

check_condition:
  if(i < 10)
    goto loop_body;
  else
    goto loop_exit;

loop_body:
  printf("%i\n", i);
  goto end_body;

end_body:
  ++i;
  goto check_condition;

loop_exit:
  return 0;
}
