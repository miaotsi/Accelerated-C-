# Accelerated-C-++
中英对照 Chinese &amp; English

学习笔记：

Nov 2
注释：//   /* */
标准头文件：#include <iostream>
作用域：作用到全体，或者作用到某个局部中。在一对 {} 中定义的变量是局部变量，程序执行完 {} 中的部分后，就会销毁这个变量，然后系统回收变量所占用的所有内存。
名字空间：命名的空间，比如 “cv::Mat” 是和 “cv空间的Mat” 等同的表达。
表达式：miaotsi.name, “.” 表示后者是前者的属性或者函数。
语句：std::string stars(10, '*'); 那么 stars.size() 的结果是10， stars 本身包含十个*字符。
字符串直接量以及输出：std::string hello = "hello"; std::string stars(100, '*'); std::string name; 三种均表示字符串生成。
Notes: // /* */
Standard header file: #include <iostream>
Scope: Acts to the whole, or to a local. The variable defined in a pair of {}, the one that is a local variable, is destroyed after the program has executed the part of the variable, and the system reclaims all the memory that the variable occupies.
Name space: Named spaces, such as "cv:Mat" are the equivalent expression of "Mat" in namespace cv.
Expression: miaotsi.name, "." indicates that the latter is a property or function of the former.
Statement: std:: string stars (10, '''); Then the result of stars.size() is 10, and the stars themselves contain ten '*'s.
String direct quantity and output: std::string hello = "hello"; std:: string stars (100, '*'); std:: string name; All three represent string generation.
