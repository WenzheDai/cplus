#include <iostream>
#include <sstream>
#include <string>


void fun1() {
    // 去掉空格
    std::cout << "==========stringsteam去除空格==========" << std::endl;
    std::stringstream ss("hello string and stringsteam");
    std::cout << ss.str() << std::endl;
    std::cout << std::endl;

    std::string str;
    //stringstream 是一个单词一个单词 “流入” string 的
    while (ss >> str) {
        std::cout << str;
    }
}

void fun2() {
    // 分割字符串
    std::cout << "==========分割字符串==========" << std::endl;
    std::string source = "abc,123,<!>";
    std::stringstream ss(source);
    std::cout << ss.str() << std::endl;
    std::cout << std::endl;

    std::string str;
    while (getline(ss, str, ',')) {
        std::cout << str << std::endl;
    }
}

void fun3() {
    // 类型转换
    // int -- > string
    std::cout << "=========类型转换============" << std::endl;
    std::cout << "== int --> string ==" << std::endl;
    int num = 123;
    std::stringstream ss;
    ss << num;
    std::string str = ss.str();
    std:: cout << str << std::endl;

    std::cout << "== string --> int ==" << std::endl;
    std::string s1 = "456";
    std::stringstream ss1(str);
    int num1;
    ss >> num1;
    std::cout << num1 << std::endl;
}


int main() {
    std::cout << "===========construct=================" << std::endl;
    std::string s("hello");
    std::stringstream ss;
    ss << s;
    std::cout << ss.str() << std::endl;

    std::stringstream ss1("hello stringstream!");
    std::cout << ss1.str() << std::endl;

    std::stringstream ss2;
    ss2 << "fre";
    ss2 << "gre";
    std::cout << ss2.str() << std::endl;

    std:: cout << "==========================================" << std::endl;
    // << 会覆盖原始s1的字符串
    std::string s1("asd");
    std::stringstream ss3(s1);
    std::cout << ss3.str() << std::endl;
    ss3 << "r";
    std::cout << ss3.str() << std::endl;
    ss3 << "13";
    std::cout << ss3.str() << std::endl;
    ss3 << "hy";
    std::cout << ss3.str() << std::endl;

    std:: cout << "==========================================" << std::endl;
    // << 不覆盖，直接追加
    std::ostringstream ss4("1 2 3 4", std:: ios_base::ate);   // 追加
    std::cout << ss4.str() << std::endl;
    ss4 << "5 3 4";
    std::cout << ss4.str() << std::endl;

    std:: cout << "==========================================" << std::endl;
    // 修改和清空stringstream内容
    std::stringstream ss5("hello string");
    std::cout << ss5.str() << std::endl;
    //修改
    ss5.str("hello stringstream");
    std::cout << ss5.str() << std::endl;
    //清空
    ss5.str("");
    std::cout << ss5.str() << std::endl;

    fun1();
    std::cout << std::endl;
    fun2();
    std::cout << std::endl;
    fun3();

    return 0;
}