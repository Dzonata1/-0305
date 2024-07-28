#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;

#define random(a,b) a+rand()%(b+1-a)

class Student {
  string name;
  string surname;
  int age;

public:
  Student(string name, string surname) {
    this->name = name;
    this->surname = surname;
    age = random(20, 45);
  }

  string getName() {
    return name;
  }
  string getSurname() {
    return surname;
  }
  int getAge() {
    return age;
  }

};

ostream& operator << (ostream& os, Student& st) {
  return os << st.getName() << " " << st.getSurname()<<" "<<st.getAge();
}

class Group {
  set<Student*> students;
  string number;
public:
  Group(string number) {
    this->number = number;
  }
  void insert(Student* st) {
    students.insert(st);
  }
  void showStudents() {
    cout << "group: " << number << endl;
    int count = 1;
    for (auto el : students) {
      cout <<count++ <<": " << *el << endl;
    }
  }
  string getNumber() const{
    return number;
  }
  set<Student*> getStudents() const{
    return students;
  }
};

class Journal {
  map<string, set<Student*> > groups;
  //set<Group*> groups;
  //string number;
public:
  void insert(Group* group) {
    string number = group->getNumber();
    set<Student*> students = group->getStudents();
    groups[number] = students;
    
  }
    void showGroups() {
      for (auto& entry : groups) {
        cout << "Группа: " << entry.first << endl; 
        for (const auto& el : entry.second) { 
          cout << count++ << ": " << *el << endl;
      }
    }
  }
};

int main()
{
  Group* group = new Group("1A");
  group->insert(new Student("Pol", "Polovinov"));
  group->insert(new Student("Pol", "Polovinov"));
  group->insert(new Student("Polw", "Polo"));
  group->insert(new Student("Pole", "Polov"));

  Group* group2 = new Group("1B");
  group2->insert(new Student("Nil", "Polovinov"));
  group2->insert(new Student("Pkllkk", "Polfnov"));
  group2->insert(new Student("Psdfsdf", "Pdflo"));
  group2->insert(new Student("Pdfdfe", "Pdfsfov"));

  Journal journal;
  journal.insert(group);
  journal.insert(group2);

  journal.showGroups();
  
   
};

