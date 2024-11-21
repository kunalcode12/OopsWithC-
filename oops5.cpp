#include <iostream>
#include <string>
using namespace std;

class student
{
public:
    int age;
    string first_name;
    string last_name;
    int standard;
    void set(int age, string first_name, string last_name, int standard);
};

void student::set(int a, string fname, string lname, int std)
{
    age = a;
    first_name = fname;
    last_name = lname;
    standard = std;
}
struct get
{
    int age;
    string first_name;
    string last_name;
    int standard;
};

get out(int age, string first_name, string last_name, int standard)
{
    get result;
    result.age = age;
    result.first_name = first_name;
    result.last_name = last_name;
    result.standard = standard;
    return result;
}

int main()
{
    int a;
    string fname;
    string lname;
    int std;
    student s;
    cin >> a >> fname >> lname >> std;
    s.set(a, fname, lname, std);

    get details = out(s.age, s.first_name, s.last_name, s.standard);

    cout << details.age << endl;
    cout << details.last_name << ',' << ' ';
    cout << details.first_name << endl;
    cout << details.standard << endl;
    cout << endl;

    cout << details.age << ',' << details.first_name << ',' << details.last_name << ',' << details.standard << endl;

    return 0;
}