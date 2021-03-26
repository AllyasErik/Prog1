#include "std_lib_facilities.h"

struct Person{
	Person() { };
	Person(string f, string l, int age);
	//string name() const { return p_name; };

	string first_name() const { return first; };
	string last_name() const { return last; };

	int age() const { return p_age; };

private:
	//string p_name;
	string first;
	string last;
	int p_age=0;
};

Person::Person(string f, string l, int age): first(f), last(l), p_age(age)
{
	if(age < 0 || age>150)
		error("Invalid age");

	//string t_name = name;
	string t_name = f + l;
	for(char c: t_name)
		switch(c)
		{
			case ';':
			case ':':
			case '"':
			case '\'':
			case '[':
			case ']':
			case '*':
			case '&':
			case '^':
			case '%':
			case '$':
			case '#':
			case '@':
			case '!':					
				error("Invalid character in names");
			default:
				break;
		}
}

istream& operator>>(istream &is, Person &p)
{
	//string is_name;
	string is_fname;
	string is_lname;
	int is_age;

	//is >> is_name >> is_age;
	is >> is_fname >> is_lname >> is_age;
	//p = Person(is_name, is_age);
	p = Person{is_fname, is_lname, is_age};

	return is;
}

ostream& operator<<(ostream &os, Person &p)
{
	//os << p.name() << " " << p.age() << endl;
	os << p.first_name() << " " << p.last_name() << " " << p.age() << endl;
	return os;
}

main()
try{
	Person p("Goofy", "Brown", 63);
	cout << p << endl;
	
	vector<Person> vp;
	cout << "Enter some names and ages, then write 'end' if done.\n";
	Person pp;
	while(cin >> pp)
	{
		if(pp.first_name() == "end") break;
		vp.push_back(pp);
	}

	for(Person p : vp)
		cout << p << endl;



	return 0;
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
    keep_window_open();
}