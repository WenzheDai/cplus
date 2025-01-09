#include <iostream>


class Student{
public:
  Student(){ // default construct function
    this->age = 20;
    this->num = 1000;
  }
  Student(int a, int n):age(a), num(n){}  // Init construct function
  Student(const Student& s) { // copy construct function
    this->age = s.age;
    this->num = s.num;
  }
  Student(int r) { // Turn construct function
    this->age = r;
    this->num = 1002;
  }

  ~Student(){}

public:
  int age;
  int num;
};


int main (int argc, char *argv[]) {
  Student s1;
  Student s2(18, 10001);
  int a = 10;
  Student s3(a);
  Student s4(s3);

  std::printf("s1 age: %d, num: %d\n", s1.age, s1.num);
  std::printf("s2 age: %d, num: %d\n", s2.age, s2.num);
  std::printf("s3 age: %d, num: %d\n", s3.age, s3.num);
  std::printf("s4 age: %d, num: %d\n", s4.age, s4.num);

  return 0;
}
