#include <stdio.h>

int main(void)
{
  int a = 10;
  int b = 5;
  int sum = 0,diff = 0,product = 0,quotient = 0;

  /* Calling Functions from our library */
  sum      = add(a,b);
  diff     = sub(a,b);
  product  = mul(a,b);
  quotient = div(a,b);

  printf("Sum      = %d\n",sum);
  printf("Diff     = %d\n",diff);
  printf("Product  = %d\n",product);
  printf("Quotient = %d\n",quotient);
 
  return 0;
}
