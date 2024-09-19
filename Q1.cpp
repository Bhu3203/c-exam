/*Q.No. 1 Banking Record System.
File handling has been effectively used for each feature of this project
Operations
? Add Record:
? Show/List Data:
? Search Record:
? Edit Record:
? Delete Record:*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Banking {
private:
    string file;

public:
    void createFile() {
        cout << "\nEnter file name: ";
        cin >> file;
        ofstream obj(file + ".txt", ios::app);
        obj.close();
        cout << "\nFile created: " << file << ".txt\n";
    }

    void addRecord(int id, const string& name, int age) {
        ofstream obj(file + ".txt", ios::app);
        obj << id << "\t" << name << "\t" << age << endl;
        obj.close();
        cout << "\nRecord added successfully!\n";
    }

    void showData() {
        ifstream in(file + ".txt");
        string line;
        cout << "\nData in file:\n";
        while (getline(in, line)) {
            cout << line << endl;
        }
        in.close();
    }

    void searchRecord(int id) {
        ifstream in(file + ".txt");
        string line;
        bool found = false;
        while (getline(in, line)) {
            if (line.find(to_string(id)) != string::npos) {
                cout << "Record found: " << line << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Record with ID " << id << " not found.\n";
        }
        in.close();
    }

    void editRecord(int id, const string& newName, int newAge) {
        ifstream in(file + ".txt");
        vector<string> records;
        string line;
        bool found = false;

        while (getline(in, line)) {
            if (line.find(to_string(id)) != string::npos) {
                line = to_string(id) + "\t" + newName + "\t" + to_string(newAge);
                found = true;
            }
            records.push_back(line);
        }
        in.close();

        ofstream out(file + ".txt");
        for (const string& record : records) {
            out << record << endl;
        }
        out.close();

        if (found) {
            cout << "Record updated successfully!\n";
        } else {
            cout << "Record with ID " << id << " not found for editing.\n";
        }
    }

    void deleteRecord(int id) {
        ifstream in(file + ".txt");
        vector<string> records;
        string line;
        bool found = false;

        while (getline(in, line)) {
            if (line.find(to_string(id)) == string::npos) {
                records.push_back(line);
            } else {
                found = true;
            }
        }
        in.close();
        ofstream out(file + ".txt");
        for (const string& record : records) {
            out << record << endl;
        }
        out.close();

        if (found) {
            cout << "Record deleted successfully!\n";
        } else {
            cout << "Record with ID " << id << " not found for deletion.\n";
        }
    }

    void deleteFile() {
        if (remove((file + ".txt").c_str()) == 0) {
            cout << "\nFile deleted successfully!\n";
        } else {
            cout << "\nFile not deleted.\n";
        }
    }
};

int main() {
    Banking b;
    b.createFile();
    
    int choice;
    do {
        cout << "\nMenu:\n1. Add Record\n2. Show Data\n3. Search Record\n4. Edit Record\n5. Delete Record\n6. Delete File\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int id, age;
                string name;
                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Age: ";
                cin >> age;
                b.addRecord(id, name, age);
                break;
            }
            case 2:
                b.showData();
                break;
            case 3: {
                int id;
                cout << "Enter ID to search: ";
                cin >> id;
                b.searchRecord(id);
                break;
            }
            case 4: {
                int id, newAge;
                string newName;
                cout << "Enter ID to edit: ";
                cin >> id;
                cout << "Enter new Name: ";
                cin >> newName;
                cout << "Enter new Age: ";
                cin >> newAge;
                b.editRecord(id, newName, newAge);
                break;
            }
            case 5: {
                int id;
                cout << "Enter ID to delete: ";
                cin >> id;
                b.deleteRecord(id);
                break;
            }
            case 6:
                b.deleteFile();
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}
	b.add_record(id,name,age);
//	b.show_data(line);
}
