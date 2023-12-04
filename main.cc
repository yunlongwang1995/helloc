//
// Created by wangyunlong01 on 2022/4/12.
//
#include <iostream>
#include <string.h>
#include <string>

/**
 * 入门用例
 * @param argc 　　参数个数 3
 * @param argv 　　参数列表 ./main hello 123
 * @return
 */

using namespace std;

void c_string_test()
{
  char* name = "hello c";
  printf("%s len: %d\n", name, strlen(name));
}

void cpp_string_test()
{
  string city = "jinan";
  string c2 = city;
  city = "beijing";
  printf("city = %s, c2 = %s\n", city.data(), c2.data());
}

typedef struct node {
  int val;
  node* next;
} node;

node* reverse(node* head) {
  if (head == NULL) {
    return NULL;
  }

  node* current = head;
  node* next = current->next;
  current->next = NULL;

  while (next) {
    node* old_current = current;
    node* old_next = next;
    current = next;
    next = current->next;
    old_next->next = old_current;
  }

  return current;
}

void reverse_list_test() {
  node* n1 = new node();
  node* n2 = new node();
  node* n3 = new node();
  node* n4 = new node();

  n1->val = 1;
  n2->val = 2;
  n3->val = 3;
  n4->val = 4;

  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = NULL;

  node* res = reverse(n1);
  while (res != NULL) {
    printf("%d    ", res->val);
    res = res->next;
  }
  printf("\n");
}

int main(int argc, char* argv[]) {
  // c string test
  c_string_test();

  // c++ string test
  cpp_string_test();

  reverse_list_test();
}