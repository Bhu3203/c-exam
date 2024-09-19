
/*Write a C++ program to accpet worker information Worker_Name, No_Of_Hours_Worked,
Pay_Rate and Salary. Write necessary functions to calculate and display the salary of Worker. (Use
Default values for Pay_Rate Rs. 500 per hours)*///
#include<iostream>
using namespace std;
class Worker{
	private:
		string name;
		int hrs;
		float salary,r;
	public:
		Worker(){
			r=500;
		}
		void get(string name,int hrs){
			this->name=name;
			this->hrs=hrs;
		}
		void sal(){
			salary=r*hrs;
		}
		void set(){
			sal();
			cout<<"\n Name:"<<name<<"\n Salary is:"<<salary;
		}
		
};
int main(){
	Worker w1,w2;
	int hrs;
	string name;	
	w1.get("Bhushan",5);
	w1.set();
	w2.get("Neelash",12.5f);
	w2.set();
}