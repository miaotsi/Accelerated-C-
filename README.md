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
vector(double)　是向量，向量是存储数据集合的容器，可以根据需要增长以容纳其输入。double 是向量里面数据的类型。
vector(double)　homework; homework.push_back(x) 函数的作用是添加一个新的元素到向量的末尾。
typedef vector<double>::size_type vec_sz; vec_sz size = homework.size(); 使用了库定义的　size_type，　避免使用局部变量。vrc_sz　是　vector<double>::size_type 的替代名。
sort(homework.begin(), homework.end()); sort 函数把容器中的数据重新排序成非递减序列。homework.begin()　指示了向量中第一个元素，　homework.end()　指向紧跟在homework 最后一个元素之后的位置。
  
*Nov 5
**计算学生成绩

sort() 函数仅仅调换了原容器中的元素值的相对顺序，而不是创建一个新的容器来存储排序后的结果。
找出中位数：　vec_sz mid = size/2; double median; median = size % 2 == 0? (homework[mid] + homework[mid-1])/2 : homework[mid]; 如果向量中所含数据的个数是偶数，那么中位数是第几个？是第　mid 个和　mid+1 个的平均值。用索引来表示，因为索引从零开始，所以是　homework[mid] 和 homework[mid-1]。如果是奇数，那么中位数是第 (size+1)/2 个, 用索引表示是 homework[(size-1)/2] = homework[mid]。mid 是　size/2 向下取整的结果。

*Dec23
**组织计算　L3

抛出异常：比如throw domain_error("median of an empty vector");
在我们调用一个函数的时候，我们可以把参数看做是初始值等于参数的局部变量。在调用函数的时候，参数同时也被复制到参数中。这样会花费较多时间，因为median函数会通过调用sort从而改变它的参数值。但是同时也有好处，因为sort所做的改变不会反馈到调用函数中。
vector<double> homework;
vector<double>& hw = homework; //hw是homework 的一个替代名。叫做常量引用。对它访问相当于对关联变量直接访问，而不用我们去复制，节省开销。
对hw所做的任何动作都等价于对homework 做同样的动作。但是因为是const，不会改变它的值。
重载：可以让几个函数有同样的函数名。同时，要提供一个函数列表，系统环境能够根据第n个参数的类型来辨别我们所指的函数。
homework 向量的大小：homework.size()

*Dec 30
**读家庭作业成绩 L4

//读一个输入流，把家庭作业成绩读进一个vector<double>类型的向量中
istream& read_hw(istream& in, vector<double>& hw) 
{
	return in;
}
一个不含const的引用参数通常表示我们可以修改作为函数参数的对象的值。
例如，执行
vector<double> homework;
read_hw(cin, homework);
read_hw 的第二个参数是一个引用。对read_hw的调用会改变homework的值。
read_hw函数的两个参数都是引用，我们希望用这个函数改变两个参数的状态。
为了使程序更可靠，要增加细节。调用in.clear()来清除in内部的错误状态，这样就会让库忽略失败情况而继续输入了。同时，在试图读入第一个成绩前，有可能已经读尽了所有输入或碰到了出错。这样的话，就必须让输入流不受干涉。
#include <iostream>
#include <vector>
using namespace std;
//从输入流中将家庭作业的成绩读入到一个vector<double>中
istream read_hw(istream& in, vector<double>& hw)
{
    if(in)
    {
        //清除原先的内容
        hw.clear();
        //读家庭作业成绩
        double x;
        while (in >> x)
            hw.push_back(x);
        //清除流以使输入动作对下一个学生有效
        in.clear();
    }
    return in;
}
clear 成员在为istream服务时所表现出来的行为特性，跟它在为对象服务时的是完全不同的。对于istream对象，它清除了所有的错误标记以使输入动作继续。对于向量对象，它删除了向量中可能已经含有的全部内容，这样就会让我们再次拥有一个空的向量。
函数有一个类型为vector<double>&的参数，在这里并没有const,同样的，&让系统环境直接地把参数和参数连接起来。这样我们就可以避免对参数的复制了。不过在这里，我们之所以要避免复制操作是因为函数要改变参数的值。
与非常量引用对应的参数必须是左值。也就是说，它们必须是非临时对象。按值传递或与一个常量引用连接在一起的参数可以取任何值。例如，假定我们有一个返回空向量的函数。
//返回空向量的函数
vector<double> emptyvec()
{
    vector<double> v; //没有元素
    return v;
}
我们可以调用这个函数并且使用其结果。grade(midterm, final, emptyvec());
在运行的时候，grade函数会马上抛出一个异常，这是因为它的参数为空。然而，从语法上，这样的调用是合法的。
在我们调用read_hw的时候，它的两个参数都必须是左值，这是因为它的两个参数都是非常量引用。
read_hw(cin,emptyvec()); // 错误：emptyvec()不是左值
编译器就会提示出错，因为我们在调用emptyvec()时所创建的那个未命名的向量将会在read_hw返回时立即消失。如果我们这样调用，那结果就是，我们把输入存进了我们无法访问的对象中。

**L5

try语句：
它尝试执行在{}中紧跟在try关键字之后的语句。如果在这些语句中的任何地方发生了一个domain_error异常，那么它就会停止执行这些语句，然后转去执行另外的一系列用{}括起的语句。这些语句是catch（捕获）子句的一部分，catch子句从关键字catch开始，它指示了所捕获的异常的类型。
如果在try和catch之间的语句没有引发异常而正常结束的话，那么程序就会跳过全部的catch子句，从而继续执行下一条语句，return 0;
每当编写一条try语句的时候，我们都必须认真地考虑副作用及副作用发生的时刻。我们必须假定在try和catch之间的任何东西都有可能引发异常。在异常发生后，所有本来应该执行的运算都会被跳过。一个在时间上本来是跟在异常之后执行的运算，在程序正文中是没有必要位于异常发生的地点之后的。
//这个例子不能正常工作
try {
	streamsize prec = cout.precision();
	cout << "Your final grade is " << setprecision(3) << grade(midterm, final, homeworl) << setprecision(prec);
}
在这个重写的代码中的问题是，虽然系统环境需要从左向右地执行<<运算符，但是它并不需要按照任何特定的顺序来对操作数进行计算。它可能输出了Your final grade is之后就马上调用grade函数。假如grade抛出异常，那么输出就有可能包含了上面的短语。此外，对setprecision的第一次调用会把输出流的精度设为３，第二次调用则可能根本不能获得机会重新设成原来的值。另外，系统可能会在写任何输出之前就调用了grade语句。
因此我们要把输出块语句分割成两部分：第一条语句确保了，在产生任何的输出之前程序就调用了grade。我们有一条经验规则————也就是，我们要保证在一条语句的副作用个数不会超过一个。抛出一个异常是一个副作用，因此在一条可能会引发异常的语句中不应该再出现任何其他的副作用，尤其是包含有输入和输出的语句。




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
vector (double) is a vector, a vector is a container that stores a collection of data, a vector can grow bigger as needed to accommodate its input. Double is the type of data within the vector.
vector (double) homework; The "homework.push_back (x)" function is to add a new element to the end of the vector.
"typedef vector<double>::size_type vec_sz; vec_sz size = homework.size();" uses library-defined "size_type" to avoid local variables. "vrc_sz" is an alternative name for "vector<double>::size_type".
sort (homework.begin), homework.end()); The sort function reorders the data in the container into a non-decreasing sequence. homework.begin() indicates the first element in the vector, and homework.end() points to the position immediately after the last element of homework.
  
*Nov 5
**Calculating grades

The "sort()" function simply adjusts the relative order of the element values in the original container, rather than creating a new container to store the sorted results.
Find out the median: "vec_sz mid = size/2; double median; median = size % 2 == 0? (homework[mid] + homework[mid-1])/2 : homework[mid];" If the number of data contained in the vector is even, what is the median number? It's the average of No.mid and No.(mid+1). Because the index starts from zero, it is the average of homework[mid] and homework[mid-1]. If it's an odd number, then the median is No.(size+1)/2, which is indexed as "homework[(size-1)/2] = homework[mid]". Mid is the result of size/2 rounding down.

*Dec23
**Organizational Computing L3

Throw out exceptions: for example, throw domain_error ("median of an empty vector");
When we call a function, we can think of the argument as a local variable whose initial value is equal to the argument. When a function is called, the argument is also copied to the argument. This takes more time because the median function changes its parameter value by calling sort. But it's also beneficial because the changes that sort makes are not fed back into the calling function.
vector<double> homework;
Vector<double> and hw is an alternative name for homework. This is called a constant reference. Access to it is equivalent to direct access to the associated variable, without us copying, saving money.
Any action we do with hw is equivalent to doing the same for homework. But because it's const, it doesn't change its value.
Overload: We can make several functions have the same function name. At the same time, to provide a list of functions, the system environment is able to distinguish the function we refer to based on the type of the nth argument.
Homework vector size: homework.size()
  
*Dec30
**Read homework scores L4

//Read an input stream and read homework scores into a vector <double> type vector
istream and read_hw (istream and in, vector<double> and hw) 
{
	return in;
}
A reference parameter without const usually means that we can modify the value of the object as a function argument.
For example, 
vector<double> homework;
read_hw (cin, homework);
The second argument of the read_hw is a reference. Calls to read_hw change the value of homework.
Both parameters of the function read_hw (cin, homework) are references, and we want to use this function to change the state of both parameters.
To make the program more reliable, add details. Call in.clear() to clear the error state inside the in, which allows the library to ignore the failure and continue typing. At the same time, before attempting to read the first score, it is possible that all inputs have been read or that an error has been made. In this case, the input flow must be kept uninterfered.
#include<iostream>
#include<vector>
using namespace std;
//Read homework scores into a vector <double> from the input stream
istream read_hw (istream and in, vector<double> and hw)
{
    if(in)
    {
        //Clear the original content
        hw.clear ()
        //Read homework scores
        double x;
        while (in s s x)
            hw.push_back (x);
        //Clear the stream to make the input action valid for the next student
        in.clear ()
    }
    return in;
}
The behavior characteristics that clear members exhibit when they serve istream are completely different from when they are serving objects. For the istream object, it clears all error marks to allow the input action to continue. For vector objects, it removes everything that might already be contained in the vector, which gives us an empty vector again.

The function has a parameter of a type vector<double> , and there is no const here, the same is, & makes the system environment directly connect the one parameter to another. This way we can avoid copying parameters. Here, however, we want to avoid copying because the function changes the value of the argument.
The argument corresponding to the unusual reference must be an lvalue. That is, they must be non-temporary objects. Arguments passed by value or connected to a constant reference can take any value. For example, suppose we have a function that returns an empty vector.
//A function that returns an empty vector
vector<double> emptyvec()
{
    vector<double> v; //No elements
    return v;
}
We can call this function and use its results. grade (intin, final, emptyvec());
When running, the grad function immediately throws an exception because its arguments are empty. However, grammatically, such calls are legal.
When we call read_hw, both of its arguments must be left-values because both of its arguments are very quantitative references.
read_hw (cin, emptyvec()); //Error: emptyvec () is not a lat
The compiler will prompt an error because the unnamed vector we created when we called emptyvec() will disappear as soon as the read_hw returns. If we call like this, the result is that we save the input in an object that we cannot access.

**L5

try statement:
It tries to execute a statement that follows the try keyword. If an domain_error exception occurs anywhere in these statements, it stops executing those statements and then goes on to execute a series of other statements that are surrounded by. These statements are part of the catch clause, which starts with the keyword catch, which indicates the type of exception that is caught.
If the statement between try and catch ends normally without throwing an exception, the program skips all the catch clauses and proceeds to the next statement, return 0;
Whenever we write a try statement, we have to seriously consider the moment of side effects and side effects. We must assume that anything between try and catch can cause an anomaly. After an exception occurs, all operations that should have been performed are skipped. An operation that would have been performed after an exception in time is not necessary in the body of the program after where the exception occurred.
This example doesn't work
try{
	streamsize prec = cout.precision ();
	cout << "Your final grade is" << setprecision (3) << grade (midterm, final, homework) << setprecision(prec);
}
The problem with this rewritten code is that although the system environment needs to execute the operator from left to right, it does not need to calculate the number of operations in any particular order. It may have output your final grade is and call the grade function as soon as it is. If the grade throws an exception, the output may contain the phrase above. In addition, the first call to setprecision sets the accuracy of the output stream to 3, and the second call may not have the opportunity to reset the original value at all. In addition, the system may call the grade statement before writing any output.
So we're going to split the output block statement into two parts: the first statement ensures that the program calls the grade before any output is produced. We have a rule of thumb———— that is, we want to make sure that the number of side effects in a statement does not exceed one. Throwing an exception is a side effect, so no other side effects should occur in a statement that might throw an exception, especially one that contains input and output.

