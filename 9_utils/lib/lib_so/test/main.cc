//
// Created by wangyunlong01 on 2022/10/7.
//

#include<stdio.h>
#include"myadd.h"
#include"mysub.h"
int main()
{
  int x = 100;
  int y = 30;
  int z = mysub(x,y);
  int f = myadd(x,y);
  printf("%d %d\n",z,f);
  return 0;
}
