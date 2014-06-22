#include "stdio.h"

//c = (b = a+2) - (a=2);执行前和执行后有两个时间点p1和p2（用C语言标准来说叫做Sequence Point)。本例中，子表达式(a=2)的副作用在p1和p2之间是不确定的（不确定该副作用已经发生，也就是说a的值变为2）。然后，标准有这么一段，
//
//Between the previous and next sequence point an object shall have its stored value modified at most once by the evaluation of an expression. Furthermore, the prior value shall be accessed only to determine the value to be stored.
//
//第二条规则说时间点p1前的值（旧值）只能被用作计算新值。本例中，子表达式(b=a+2)中b的新值是由a来确定的（2是常量，在此不考虑），而a所指定的值是p1前的值还是新值是不确定的（参见第一>段文字）。所以就有问题了。比如，clang编译器会报警告，
//
//warning: unsequenced modification and access to 'a' [-Wunsequenced]
//
//另，如果非要写成一行，可以写做 c = (b = a+2, a=2, b-a); 因为操作符",", "||"和"&&"都对应一个序列点(Sequence Point)。

// 不建议是用这类复杂的表达式。


//int main(){
//	int a = 5;
//	int b = 0;
//	int c = (b=a+2) - (a=2);
//	printf("c的值为 %d", c);
//}
