//      Name: Brayden Birt
//      Date: 04/12/23
// File name: lab12.cc

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <vector>
using namespace std;

//structures
struct Employee{
    int id;
    string firstName;
    string lastName;
    float salary;
};
//prototypes
Employee inputEmployee();
void loadVectStruct(vector <Employee> &allEmp, ifstream &ins);
void prntMenu(const vector <Employee> &allEmp, float salaryTotal);
int salTotal(const vector <Employee> &allEmp);


int main(){
    ifstream ins;
    ins.open("employees.txt");
    if (ins.fail())
    {
        cout << "Error" << endl;
        exit(0);
    }
    vector <Employee> allEmp;

    Employee e;
    ins >> e.id >> e.firstName >> e.lastName >> e.salary;

    while (!ins.eof()){
        allEmp.push_back(e);
        ins >> e.id >> e.firstName >> e.lastName >> e.salary;
    }
    //loadVectStruct(allEmp, ins);
    float salaryTotal = salTotal(allEmp);
    prntMenu(allEmp, salaryTotal);

    ins.close();
    return 0;
}


void loadVectStruct(vector <Employee> &allEmp, ifstream &ins){
    Employee e;
    ins >> e.id >> e.firstName >> e.lastName >> e.salary;

    while (!ins.eof()){
        allEmp.push_back(e);
        ins >> e.id >> e.firstName >> e.lastName >> e.salary;
    }
}

void prntMenu(const vector <Employee> &allEmp, float salaryTotal){
    cout << left << setw(8) << "ID" << setw(21) << "Name" << "Salary" << endl;
    cout << "--------------------------------------" << endl;
    for (size_t i = 0; i < allEmp.size(); i++)
    {
        cout << left << setw(8) << allEmp.at(i).id << allEmp.at(i).firstName << " " << setw(20 - (allEmp.at(i).firstName.size())) << allEmp.at(i).lastName << "$" << fixed << setprecision(2) << allEmp.at(i).salary << endl;
    }
    cout << endl << "Total Payroll: $" << fixed << setprecision(2) << salaryTotal << endl;
}

int salTotal(const vector <Employee> &allEmp){
    float total = 0;
    for (size_t i = 0; i < allEmp.size(); i++)
    {
        total += allEmp.at(i).salary;
    }
    return total;
}