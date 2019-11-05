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

*Nov 4
**计算学生成绩

小数定义时，一般用　float ，不用较短的　float。
如果两个以上的字符串直接量仅仅是被空白符分隔开的话，这些字符串会被自动连接到一起。因此，对于长句，可以写成多行，便于阅读。
定义变量时，要确定初始值。
setprecision(int) 是一个控制器，setprecision(3) 表示十进制小数点前有两位有效数，小数点后有一位。setprecision(int)　对后面的所有输出都产生作用，因此往往需要恢复原来的精度。用　streamsize prec = cout.precision() 记录之前的精度，用 setprecision(prec) 从新的精度恢复成原始值。
if (cin >> x) 和　cin>>x; if(cin) 效果相同。cin 可以通过变换，返回成 bool　值。

用中值代替平均值：
vector(double)　是向量，向量是存储数据集合的容器，double 是向量里面数据的类型。
vector(double)　homework; homework.push_back(x) 函数的作用是添加一个新的元素到向量的末尾。
typedef vector<double>::size_type vec_sz; vec_sz size = homework.size(); 使用了库定义的　size_type，　避免使用局部变量。vrc_sz　是　vector<double>::size_type 的替代名。
sort(homework.begin(), homework.end()); sort 函数把容器中的数据重新排序成非递减序列。homework.begin()　指示了向量中第一个元素，　homework.end()　指向紧跟在homework 最后一个元素之后的位置。
  
*Nov 5
**计算学生成绩

sort() 函数仅仅调换了原容器中的元素值的相对顺序，而不是创建一个新的容器来存储排序后的结果。
找出中位数：　vec_sz mid = size/2; double median; median = size % 2 == 0? (homework[mid] + homework[mid-1])/2 : homework[mid]; 如果向量中所含数据的个数是偶数，那么中位数是第几个？是第　mid 个和　mid+1 个的平均值。用索引来表示，因为索引从零开始，所以是　homework[mid] 和 homework[mid-1]。如果是奇数，那么中位数是第 (size+1)/2 个, 用索引表示是 homework[(size-1)/2] = homework[mid]。mid 是　size/2 向下取整的结果。

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

*Nov 4
**Calculating grades

When decimals are defined, floats are generally used in stead of float, which is smaller.
If the more than two strings are separated simply  by a blank character, the strings are automatically connected to together. Therefore, for long sentences, we can write multiple lines for easy reading.
When a variable is defined, the initial value should be given.
Setprecision (int) is a controller, and setprecision (3) means that there are two valid numbers before the decimal point and one afer. Setprecision (int) acts on all subsequent outputs, so it is often necessary to restore the original accuracy. Record the previous precision with streamsize prec = cout.precision(), and restore the original value with setprecision(prec).
"If (cin>>x)" and "cin >> x; If (cin);" have the same effect. Cin can be transformed to return to a bool value.

Replace the mean with the median:
vector (double) is a vector, a vector is a container that stores a collection of data, and double is the type of data within the vector.
vector (double) homework; The "homework.push_back (x)" function is to add a new element to the end of the vector.
"typedef vector<double>::size_type vec_sz; vec_sz size = homework.size();" uses library-defined "size_type" to avoid local variables. "vrc_sz" is an alternative name for "vector<double>::size_type".
sort (homework.begin), homework.end()); The sort function reorders the data in the container into a non-decreasing sequence. homework.begin() indicates the first element in the vector, and homework.end() points to the position immediately after the last element of homework.
  
*Nov 5
**Calculating grades

The "sort()" function simply adjusts the relative order of the element values in the original container, rather than creating a new container to store the sorted results.
Find out the median: "vec_sz mid = size/2; double median; median = size % 2 == 0? (homework[mid] + homework[mid-1])/2 : homework[mid];" If the number of data contained in the vector is even, what is the median number? It's the average of No.mid and No.(mid+1). Because the index starts from zero, it is the average of homework[mid] and homework[mid-1]. If it's an odd number, then the median is No.(size+1)/2, which is indexed as "homework[(size-1)/2] = homework[mid]". Mid is the result of size/2 rounding down.
