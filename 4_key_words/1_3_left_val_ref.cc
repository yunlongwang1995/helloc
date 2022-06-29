//
// Created by wangyunlong01 on 2022/6/22.
//
#include <iostream>
#include "common.h"
using namespace std;
class LPerson {
public:
    LPerson() : name("default"), age(18){

    }
public:
    string name;
    int age;
};

class LFamily {
public:
    LFamily(const LPerson& person) : person(person){

    }
public:
    const LPerson &person;
};

int main() {
    LPerson* person = new LPerson();
    LFamily family = LFamily(*person);
    cout << family.person.name << " " << family.person.age << endl;
    person->name = "change1";
    person->age = 100;
    cout << family.person.name << " " << family.person.age << endl;
    delete person;

    cout << "after delete occur err: " << family.person.name << " " << family.person.age << endl;
}