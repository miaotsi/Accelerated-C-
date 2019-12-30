#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

double grade(double midterm, double final, double homework)
{
    return 0.2 * midterm + 0.4 *final + 0.4 *homework;
}



double median(vector<double>vec)
{
    typedef vector<double>::size_type vec_sz;
    vec_sz size = vec.size();
    if(size == 0)
        throw domain_error("median of an empty vector");
    sort(vec.begin(),vec.end());

    vec_sz mid = size/2;
    return size % 2 == 0 ? (vec[mid] + vec[mid-1])/2
                         : vec[mid];
}


int main()
{
    double midterm,final;
    midterm = 90;
    final = 90;
    vector<double> vec;
    vec = {89,89,89};
    cout << "Your final grade is " << setprecision(3)
    << grade(midterm, final , median(vec)) << endl;
}