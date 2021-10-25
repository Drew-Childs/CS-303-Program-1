#include <iostream>
#include <string>
#include <list>
using namespace std;

class assignment {
public:

	//gathers input from user
	void addAssignment() {	
		cout << "Please enter new assignment name --> ";
		cin >> assignmentName;
		cout << "Please enter assignment due date (Enter as mm/dd/yy)--> ";
		cin >> dueDate;
	}

	//Asks user for input, if name matches any names in the list, it will remove first element found
	void removeAssignment(list<assignment>& assignmentList) {
		string removeName;
		cout << "Please enter name of assignment to remove --> ";
		cin >> removeName;

		for (list<assignment>::iterator it = assignmentList.begin(); it != assignmentList.end(); ++it) {
			if (it->assignmentName == removeName) {
				assignmentList.erase(it);
				break;
			}
		}

	}

	//Prints all assignments
	void printAssignment(list<assignment>& assignmentList) {
		for (list<assignment>::iterator it = assignmentList.begin(); it != assignmentList.end(); ++it) {
			cout << "Assignment Name: " << it->assignmentName << endl;
			cout << "Assignment Due Date: " << it->dueDate << endl << endl;
		}
	}

	//finds assignments with lowest dates
	void findAssignment(list<assignment>& assignmentList) {
		string lowMonth = "99", lowDay = "99", lowYear = "99";

		//find assignments with lowest dates and stores them in the variables above
		for (list<assignment>::iterator it = assignmentList.begin(); it != assignmentList.end(); ++it) {
			if ((it->dueDate.at(6) + it->dueDate.at(7) <= lowYear.at(0) + lowYear.at(1)) && (it->dueDate.at(0) + it->dueDate.at(1) <= lowMonth.at(0) + lowMonth.at(1)) && (it->dueDate.at(3) + it->dueDate.at(4) <= lowDay.at(0) + lowDay.at(1))) {
				lowYear = it->dueDate.at(6);
				lowYear += it->dueDate.at(7);
				lowMonth = it->dueDate.at(0);
				lowMonth += it->dueDate.at(1);
				lowDay = it->dueDate.at(3);
				lowDay += it->dueDate.at(4);
			}
		}

		//Outputs any objects that have lowest date
		for (list<assignment>::iterator it = assignmentList.begin(); it != assignmentList.end(); ++it) {
			if (it->dueDate == lowMonth + "/" + lowDay + "/" + lowYear) {
				cout << "Assignment Name: " << it->assignmentName << endl;
				cout << "Assignment Due Date: " << it->dueDate << endl << endl;
			}
		}
	}

private:

	//Member variables of class
	string assignmentName;
	string dueDate;
};

int main() {
	char choice = '1';
	list<assignment> assignmentList;		//store all assignments in list

	while (choice != 'e') {

		//text display for gui
		cout << "Homework Assignments GUI:" << endl;
		cout << "a.) Add a new assignment" << endl;
		cout << "b.) Remove an assignment" << endl;
		cout << "c.) Print assignments as assigned" << endl;
		cout << "d.) Find assignments with earliest due date" << endl;
		cout << "e.) Exit program" << endl << endl;

		cout << "Enter your choice --> ";
		cin >> choice;
		choice = tolower(choice);

		cout << endl;

		assignment newAssignment;
		string removeName;

		//decides where to go based off user input
		switch (choice) {
			case 'a':
				newAssignment.addAssignment();
				assignmentList.push_back(newAssignment);
				break;
			case 'b':
				newAssignment.removeAssignment(assignmentList);
				break;
			case 'c':
				newAssignment.printAssignment(assignmentList);
				break;
			case 'd':
				newAssignment.findAssignment(assignmentList);
				break;
			default:
				break;
		}

		cout << endl << "--------------------------------" << endl << endl;
	}

	return 0;
}