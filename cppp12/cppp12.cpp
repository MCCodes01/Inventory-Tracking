#include <iostream>

#include <fstream>

#include <vector>

#include <string>

#include <sstream>

#include "cost.h"

using namespace std;

//function declarations

struct cost parse_account(ifstream*);

void pushToV(vector<cost>&, struct cost);

double sum_accounts(vector<cost>&);

int main()

{

    //declare a vector container to store cost

    //records

    vector <cost> records;

    //create an object of ifstream to read a text file

    ifstream ifs;

    struct cost onerecord;

    //open the cost file

    ifs.open("costfile.txt");

    //if file is not opened, print error message and exit

    if (!ifs.is_open())

    {

        cout << "Unable to open file" << endl;

        return 0;

    }

    cout << "*Data Records*" << endl;

    //repeat until all the records are extracted

    while (!ifs.eof())

    {

        //call parse_account and store returned

        //structure into onerecord

        onerecord = parse_account(&ifs);

        //push the record into the container

        pushToV(records, onerecord);

    }

    //print the message and the sum

    cout << "=======================" << endl;

    cout << "The sum= $" << sum_accounts(records) << endl;

    system("pause");

    return 0;

}

//parses one record each time and populates the

//data record and returns the data record

struct cost parse_account(ifstream* ifs)

{

    struct cost record;

    stringstream stringRecord;

    string str;

    //read a record into string str

    getline(*ifs, str);

    //print the record

    cout << str << endl;

    //pass the string str into stringRecord

    stringRecord << str;

    //store the record values into each

    //respected field

    stringRecord >> record.description;

    stringRecord >> record.amount;

    stringRecord >> record.itemNum;

    //return the filled record

    return record;

}

//pushes the data record into cotnainer

void pushToV(vector<cost>& records, struct cost onerecord)

{

    //add the record to the container

    records.push_back(onerecord);

}

//sums the amount of all items and

//returns the sum

double sum_accounts(vector<cost>& records)

{

    double sum = 0;

    //iterate the container,vector

    for (int i = 0; i < records.size(); i++)

    {

        //calculate sum

        sum = sum + (records[i].amount);

    }

    //return the sum

    return sum;

}