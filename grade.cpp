#include <iostream>
#include <iomanip>
#include <ios>
#include <string>

using namespace std;

int main()
{
    cout << "Please enter your first name: ";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;

    cout << "exam" << endl;
    double midterm, final;
    cin >> midterm >> final;

    cout << "home grades, "
            "followed by end-of-file: ";

    int count = 0;
    int sum = 0;

    double x;

    while(cin >> x)
    {
        ++ count;
        sum += x;
    }

    streamsize prec = cout.precision();
    cout << "Grade is " << setprecision(3)
    << 0.2 * midterm + 0.4 * final + 0.4 * sum/count
    << setprecision(prec) << endl;

    return 0;
}