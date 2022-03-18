#include "std_lib_facilities.h"

struct Person {
    Person() : first_name(""), second_name(""), age(0) { }
    Person(string first, string last, int a) :first_name(first), second_name(last), age(a)
    {
        const string banned_characters = ";:\"'[]*&^%$#@!";
        for (int i = 0; i<first.size(); ++i)
            for (int j = 0; j<banned_characters.size(); ++j)
                if (first[i]==banned_characters[j]) error("illegal character: ",string(1,first[i]));
        for (int i = 0; i<last.size(); ++i)
            for (int j = 0; j<banned_characters.size(); ++j)
                if (last[i]==banned_characters[j]) error("illegal character: ",string(1,last[i]));
        if (a<0 || a>=150) error("Age must be between 0 and 150");
    }
    string get_first_name() const { return first_name; }
    string get_second_name() const { return second_name; }
    int get_age() const { return age; }
private:
    string first_name;
    string second_name;
    int age;
};

istream& operator>>(istream& is, Person& person)
{
    string first_name, last_name;
    int age;
    is >> first_name >> last_name >> age;
    if (!is) return is;
    person = Person(first_name,last_name,age);
    return is;
}

ostream& operator<<(ostream& os, const Person& p)
{
    return os << "Name: " << p.get_first_name() << ' ' <<
        p.get_second_name() << ", age: " << p.get_age();
}

int main()
try {
	//Person Goofy;
	//p1.name = "Goofy Goofster";
	//p1.age = 63;
	//cout << "Name: " << Goofy.name << "\nAge: " << Goofy.age << \n;


 	Person Goofy = Person("Goofy", "Goofster", 63); 
    	cout << Goofy;

	vector<Person> persons;
	Person person3;
	cout << "\nPlease enter some names and ages divided by spaces. To see them, type '- - -' \n";
	while (cin>>person3)
		persons.push_back(person3);
	for (int i = 0; i<persons.size(); ++i)
		cout << persons[i] << endl;

	keep_window_open("-");
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	keep_window_open();
}
catch (...) {
	cerr << "exception\n";
	keep_window_open();
}
