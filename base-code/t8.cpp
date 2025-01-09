//  lambda 表达式
/*
形式：  [capture list] (params list) mutable exception-> return type { function body }
    capture list	捕获外部变量列表
    params list	    形参列表
    mutable	        用于是否可以修改捕获的变量
    exception	    异常设定
    return type	    返回类型
    function body	函数体
除了capture list和function body是不可省略的，其它的都可以跟据使用需求进行省略.
*/

#include<iostream>
#include<vector>
#include<algorithm>


int main() {
    std::vector<int> numbers = {1, 34, 23, 55, 3, 36};

    // 赋予匿名函数  函数名
    auto print = [](int i){std::cout << i << " ";};

    std::cout << "origin numbers: ";
    std::for_each(numbers.begin(), numbers.end(), print);

    std::sort(numbers.begin(), numbers.end(), [](int a, int b) -> bool {return a < b;});
    std::cout << std::endl;
    std::cout << "sorted numbers: ";
    std::for_each(numbers.begin(), numbers.end(), print);

    std::cout << std::endl;
    std::cout << "================外部变量使用===================" << std::endl;
    int x = 5;
    std::for_each(numbers.begin(), numbers.end(), [](int i) -> void {if (i < 5) std::cout << " " << i;});
    std::cout << std::endl;
    std::cout << "值捕获" << std::endl;
    std::for_each(numbers.begin(), numbers.end(), [x](int i) -> void {if (i < x) std::cout << " " << i;});

    std::cout << std::endl << "自动推断" << std::endl;
    std::for_each(numbers.begin(), numbers.end(), [=](int i) -> void {if (i < x) std::cout << " " << i;});
    std::cout << std::endl;
    std::for_each(numbers.begin(), numbers.end(), [&](int i) -> void {if (i < x) std::cout << " " << i;});

    std::cout << std::endl << "================mutable修改变量===================" << std::endl;
    int a = 10;
    // auto fun1 = [a]{a++;};    报错
    auto fun1 = [&a] {a++;};
    auto fun2 = [a] ()mutable {a++;};
    fun1();
    fun2();
    std::cout << "a: " << a << std::endl;
    std::cout << std::endl << "================异常抛出===================" << std::endl;

    // TODO: c++17取消了动态异常，，不建议使用
    auto except = []()throw(int) {
        throw 1;
    };
    try {
        except();
    }
    catch (int) {
        std::cout << "捕获到显式异常" << std::endl;
    }

    std::cout << "隐式异常" << std::endl;
    auto except1 = []{
        throw 1;
    };

    try {
        except1();
    }
    catch (int) {
        std::cout << "捕获到隐式异常";
    }

    return 0;
}