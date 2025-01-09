
class Person
{
  int m_A;
  mutable int m_b;

public:
  void add() const { // 在函数里不可修改this指针指向的指
    // m_A = 10; // error
    m_b = 20;
  }
};


class student
{
public:
  int m_A;
  mutable int m_B;
};


int main (int argc, char *argv[]) {
  const student s = student();
  // s.m_A = 10;
  s.m_B = 200;
  return 0;
}
