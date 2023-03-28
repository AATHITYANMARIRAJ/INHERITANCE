#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CommunityMember{
	protected:
		string name;
		int age;
    public:
	   	CommunityMember(string name,int age):name(name),age(age){}
		virtual void display(){
		  cout<<"The name is "<<name<<endl;
		  cout<<"The age is "<<age<<endl;
		}   	
};

class Employee:public CommunityMember{
	protected:
		int employee_id;
	public:
	   Employee(string name,int age,int employee_id):
	   CommunityMember(name,age),employee_id(employee_id){}
	   virtual void display(){
	   	CommunityMember::display();
	   	cout<<"The id is "<<employee_id<<endl;
	   }
	   	
	
};

class Faculty:public Employee{
	protected:
		string department;
	public:
      Faculty(string name,int age,int employee_id,string department):
	  Employee(name,age,employee_id),department(department){}
	  virtual void display(){
	  	Employee::display();
	  	cout<<"The department is "<<department<<endl;
	  }
	  
}; 

class Administrator:virtual public Faculty{
	protected:
		string Title;
	public:
	  Administrator(string name,int age,int employee_id,string department,string Title):
	  Faculty(name,age,employee_id,department),Title(Title){}
	  void display(){
	     Faculty::display();
	     cout<<"The Title is "<<Title<<endl;
	  }
};

class Teacher:virtual public Faculty{
	protected:
		string course;
	public:
		Teacher(string name,int age,int employee_id,string department,string course):
		Faculty(name,age,employee_id,department),course(course){}
		void display(){
		   Faculty::display();
		   cout<<"The course is "<<course<<endl;
		}	
};

class AdministratorTeacher :public Administrator,public Teacher{
	public:
	AdministratorTeacher(string name, int age, int employee_id, string department, string Title, string Course):
	Administrator( name, age, employee_id, department, Title),
	Teacher( name, age, employee_id, department, Course),
	 Faculty(name,age,employee_id,department)
	 {}
	void display(){
		Administrator::display();
		cout<<"The course is "<<course<<endl;
	}	
};

class Staff:public Employee{
	protected:
		string office;
	public:
	   Staff(string name,int age,int employee_id,string office):
	   Employee(name,age,employee_id),office(office){}
	   void display(){
	   	Employee::display();
		cout<<"The office is "<<office<<endl;
		   
	   }
};

class Student: public CommunityMember{
	protected:
		int marks;
		char grade;
	public:
	   Student(string name,int age,int marks,char grade):
	   CommunityMember(name,age),marks(marks),grade(grade){}
	   void display(){
	   	CommunityMember::display();
	   	cout<<"The marks is "<<marks<<"\n";
	   	cout<<"The grade is "<<grade<<"\n";
	   }	
};

class Alumunus:public CommunityMember{
	protected:
		int graduation_year;
	public:
	   Alumunus(string name,int age,int graduation_year):
	   CommunityMember(name,age),graduation_year(graduation_year){}
	   void display(){
	   	CommunityMember::display();
		cout<<"Graduation year is "<< graduation_year<<endl;
		}	
};

int main(){
	
	vector<CommunityMember*> Array;//created a vector of type CommunityMember Class
	Employee* emp=new Employee("vishwa",19,1);
	Array.push_back(emp);
	
	AdministratorTeacher* vi=new AdministratorTeacher("Arunraja",12,1,"IT","DAA","C++");
	
	Faculty* fac=new Faculty("gogilarasan",18,1,"IT");
    Array.push_back(fac);
    
    Administrator* admin=new Administrator("suriya",19,2,"IT","DAA");
    Array.push_back(admin);
    
   Teacher* teacher=new Teacher("duraimurugan",29,1,"IT","DAA");
    Array.push_back(teacher);
    
	Staff* staff=new Staff("Chinnadurai",39,12,"Maths");
	Array.push_back(staff);
	
	
	Student* student=new Student("Aathityan",12,100,'O');
	Array.push_back(student);
	
	
	for(auto it:Array){
	
       it->display();
       cout<<"\n\n";
   }
	return 0;
}