#include <iostream>
using namespace std;

class Person
{
public:
	string name;
	int age;

	Person()
	{
		name = "";
		age = 0;
	}

	Person(string n, int a)
	{
		name = n;
		age = a;
	}

	void print_details()
	{
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
	}	
};

class Kids
{
public:

	Person child;
	int school_grade;

	Kids()
	{
		school_grade = 0;
	}

	Kids(Person c, int s)
	{
		child = c;
		school_grade = s;
	}

	void print_details()
	{
		child.print_details();
		cout << "School Grade: " << school_grade << endl;
	}
};

class Adults
{
public:

 	Person adult;
 	string occupation;

 	Adults()
 	{
 		occupation = "";
 	}

 	Adults(Person a, string o)
 	{
 		adult = a;
 		occupation = o;
 	}

 	void print_details()
 	{
 		adult.print_details();
 		cout << "Occupation: " << occupation << endl;
 	}
};

class Community
{
public:
	string country;
	int population;

	Community()
	{
		country = "";
		population = 0;
	}

	Community(string c, int p)
	{
		country = c;
		population = p;
	}

	void print_details()
	{
		cout << "Country: " << country << endl;
		cout << "Population: " << population << endl;
	}
};

class City
{
public:
  string city;
  Community com;

  City()
  {
  	city = "";
  }

  City(string c, Community com1)
  {
  	city = c;
  	com = com1;
  }

  void print_details()
  {
  	cout << "City: " << city << endl;
  	com.print_details();
  }
};

class Family
{
public:
  int num_of_child;
  Kids *child;
  Adults *parent;

  Family()
  {
  	num_of_child = 0;
  }

  Family(int n, Kids *k, Adults *a)
  {
  	num_of_child = n;
  	child = k;
  	parent = a;
  }

  void print_details()
  {
  	cout << "Number of Children: " << num_of_child << endl;
  	for(int i=0; i<num_of_child; i++)
  	{
  		cout << "Child " << i+1 << " Details: " << endl;
  		(child+i)->print_details();
  	}
  	for(int i=0; i<2; i++)
  	{
  		cout << "Parent " << i+1 << " Details: " << endl;
  		(parent+i)->print_details();
  	}
  }
};

class Team
{
public:
	string name;
	int members;
	Person *member;

	Team()
	{
		name = "";
		members = 0;
	}

	Team(string n, int m, Person *mem)
	{
		name = n;
		members = m;
		member = mem;
	}

	void print_details()
	{
		cout << name << " Team:" << endl;
		cout << "Number of Members: " << members << endl;
		for(int i=0; i<members; i++)
		{
			cout << "Member " << i+1 << " Details: " << endl;
			(member+i)->print_details();
		}
	}
};

class CommunityProject
{
public:
	string name;
	Team team;
	City city;

	CommunityProject()
	{
		name = "";
	}

	CommunityProject(string n, Team t, City c)
	{
		name = n;
		team = t;
		city = c;
	}

	void print_details()
	{
		cout << name << " Project Details:" << endl;
		team.print_details();
		cout << endl;
		city.print_details();
	}
};

int main()
{
	Person p1("John", 38);
	Person p2("Mary", 32);
	Person p3("David", 11);
	Person p4("Henry", 8);

	Kids k1(p3, 5);
	Kids k2(p4, 3);

	Adults a1(p1, "Software Engineer");
	Adults a2(p2, "Doctor");

	Family fam(2, &k1, &a1);

	Person m1("Ranjit", 27);
	Person m2("Kumar", 25);
	Person m3("Anoop", 24);
	Person m4("Bhaskar", 23);

	Person *member = new Person[4] {m1, m2, m3, m4};
	Team team_project("Clean Environment", 4, member);

	Community com("India", 1300000000);
	City city("New Delhi", com);

	CommunityProject project("Help the Needy", team_project, city);

	cout << "Details of Community Project 'Help the Needy' :" << endl;
	project.print_details();

	return 0;
}