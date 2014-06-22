/*
 * Test.c
 *
 *  Created on: 2014年6月22日
 *      Author: kangfoo-mac
 */

#include<stdio.h>

int main()
{
  int a,b;

  scanf("%d %d",&a,&b);

  printf("%d + %d = %d\n",a,b,a+b);
  printf("%d - %d = %d\n",a,b,a-b);
  printf("%d * %d = %d\n",a,b,a*b);
  printf("%d / %d = %d\n",a,b,a/b);

  return 0;
}
