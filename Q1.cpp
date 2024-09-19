/*Q.No. 1 Banking Record System.
File handling has been effectively used for each feature of this project
Operations
? Add Record:
? Show/List Data:
? Search Record:
? Edit Record:
? Delete Record:*/
#include<iostream>
#include<fstream>
using namespace std;
class Banking{
	private:
		string line,file,name;
		int id,age;
	public:
		void createfile(){
			ofstream obj;
			cout<<"\n Enter File name:";
			cin>>file;
			obj.open(file+".txt",ios::app);
			cout<<"\nfdyudhuggsdghgf";.
			obj.close();
			cout<<"\nFile created\n";
					}
		void add_record(int id,string name,int age){
			ofstream obj;
			obj.open(file+".txt",ios::app);
			this->id=id;
			this->name=name;
			this->age=age;
			while(true){
				if(line=="1"){
					break;
				}
				
				obj<<"\n ID:"<<id<<"\t Name:"<<name<<"\t Age:"<<age;
			}
			obj.close();
			
		}
		
};
		void show_data(string line){
			ifstream in;
			in.open("Banking.txt");
			while(getline(in,line)){
			cout<<line;
			}
			in.close();
					}
		void deletefile(string file){
		
			if(remove((file+".txt").c_str())==0){
			cout<<"\nFile Deleted sucessfully ! ";

			}else{
			cout<<"\nFile not deleted ";
			}
			
};

int main(){
	Banking b;
	b.createfile();
	int id;
	cin>>id;
	string name,line;
	cin>>name;
	int age;
	cin>>age;
	
	b.add_record(id,name,age);
//	b.show_data(line);
}