#include <iostream>
#include <stdio.h>
    /*
    这个程序为了说明在C或C++中，如下程序

    int a=3；
    int add(int a )
    {
    a=a+1;
    return a;
    }
    cout<<a<<endl;

    这个程序结果显示的a=3；
    而如果以Verilog的思路，则是4
    两个角度考虑：
    角度1：int a=3 中的a是实参；
    int add(int a )中的a是形参；
    调用函数时，会给形参开辟一个新的内存空间
    角度2：Verilog是直接对寄存器进行操作，寄存器改变，不执行其他操作，函数值自然紧跟上一时钟周期的结果；
    C++中，调用函数，在指令周期结束，函数会把调用的寄存器释放；
    角度1的理解更好！
    */

using namespace std;

int add(int a)
{
    a = a+1;
    cout<<"func:"<<&a<<endl;
    return a;
}

int main()
{
    int a = 3;
    cout<<"main:"<<(&a)<<endl;

    add(a);

    cout<<a<<endl;
    return 0;

}
