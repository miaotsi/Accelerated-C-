# Accelerated-C-++
中英对照 Chinese &amp; English

***学习笔记：

*Nov 2
**使用字符串

注释：//   /* */
标准头文件：#include <iostream>
作用域：作用到全体，或者作用到某个局部中。在一对 {} 中定义的变量是局部变量，程序执行完 {} 中的部分后，就会销毁这个变量，然后系统回收变量所占用的所有内存。
名字空间：命名的空间，比如 “cv::Mat” 是和 “cv空间的Mat” 等同的表达。
表达式：miaotsi.name, “.” 表示后者是前者的属性或者函数。
语句：std::string stars(10, '*'); 那么 stars.size() 的结果是10， stars 本身包含十个*字符。
字符串直接量以及输出：std::string hello = "hello"; std::string stars(100, '*'); std::string name; 三种均表示字符串生成。
  
  
**循环和计数

输出数目未知的行：用while(r != rows)控制

*Nov 3
**循环和计数

设计while语句：保证　while　第一句开始时条件为真实情况，下一句开始前条件也为真实情况。
输出一行：int 的长度无法满足时，可以输入 string 表示长字符.
逻辑运算符：|| && 逻辑运算符是左结合的。如果程序发现 || 的左操作数的值为真，它就根本不会再去计算右操作数。，算数运算符具有优先权，先计算 || 两侧的内容，再进行 || 运算。
for 循环体：从0开始，能够直观的看出循环次数和结束条件。

*Nov 2
**Using String 

Notes: // /* */
Standard header file: #include <iostream>
Scope: Acts to the whole, or to a local. The variable defined in a pair of {}, the one that is a local variable, is destroyed after the program has executed the part of the variable, and the system reclaims all the memory that the variable occupies.
Name space: Named spaces, such as "cv:Mat" are the equivalent expression of "Mat" in namespace cv.
Expression: miaotsi.name, "." indicates that the latter is a property or function of the former.
Statement: std:: string stars (10, '''); Then the result of stars.size() is 10, and the stars themselves contain ten '*'s.
String direct quantity and output: std::string hello = "hello"; std:: string stars (100, '*'); std:: string name; All three represent string generation.

*Nov 3  
**Loops and counters

Output an unknown number of rows: control with while (r! s row)


**Loops and counters

Design the while statement: Ensure that the condition at the beginning of the first sentence is the real situation, and the condition is the real situation before the next loop begins.
Output one line: When the length of the int is not satisfied, you can enter a string for a long character
Logical Operators: The logic operator is left-bound. If the program has found that the program has found that the the value of the left operator of || is true, it does not even calculate the number of right operators. The arithmetic operator has priority. The the arithmatic operators go first, and then the logical operation.
For Loop Body: Starting from 0, you can see intuitively the number of cycles and the closing conditions.
