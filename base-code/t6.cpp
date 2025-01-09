#include <filesystem>
#include <iostream>
#include <string>
#include <vector>


struct Person
{
  std::string name;
  int age;

  Person(std::string p_name, int p_age): name(std::move(p_name)), age(p_age) {
    std::cout << "I have been constructed" << std::endl;
  }

  Person(const Person& other): name(std::move(other.name)), age(other.age) {
    std::cout << "I have been copy constructed" << std::endl;
  }

  Person(Person&& other): name(std::move(other.name)), age(other.age) {
    std::cout << "I have been moved" << std::endl;
  }
};


int main()
{
  std::vector<Person> e;
  std::cout << "emplace_back:" << std::endl;
  e.emplace_back("Jane", 23);

  std::vector<Person> p;
  std::cout << "push_back:" << std::endl;
  p.push_back(Person("Mike", 36));
  return 0;

}
