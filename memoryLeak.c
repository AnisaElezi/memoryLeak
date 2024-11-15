// author https://stackoverflow.com/questions/30466098/what-are-memory-leaks-in-c


#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
  char *name;
  int age;
  int height;
  int weight;
};

struct Person Person_create(char *name, int age, int height, int weight) {
  struct Person who;
  who.name = strdup(name);
  who.age = age;
  who.height = height;
  who.weight = weight;

  return who;
}

void Person_print(struct Person who) {
  printf("Name: %s\n", who.name);
  printf("\tAge: %d\n", who.age);
  printf("\tHeight: %d\n", who.height);
  printf("\tWeight: %d\n", who.weight);
}

int main(int argc, char const *argv[]) {
  struct Person joe = Person_create("Joe Alex", 32, 64, 140);
  struct Person frank = Person_create("Frank Blank", 20, 72, 180);

  Person_print(joe);
  Person_print(frank);
  return 0;
}
