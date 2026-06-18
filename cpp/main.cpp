#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

struct person {
    string dob;
    string colour;
    string likes_peas;
    string dogs_or_cats;
};

void printPerson(person s) {
    cout << "DoB: " << s.dob << endl;
    cout << "Colour: " << s.colour << endl;
    cout << "Likes peas: " << s.likes_peas << endl;
    cout << "Dogs or Cats: " << s.dogs_or_cats << endl;
}

string removeSpaces(string& s) {
    int n = s.length();
    int i = 0, itr = 0;

    // Iterate through the string
    while (i < n) {
        
        // Check if current character 
        // is not a space
        if (s[i] != ' '){
            
            // Copy the non-space character 
            // to the new string
            s[itr++] = s[i];
        }
        i++;
    }

    // Return only the modified part of the string 
    // without any extra characters
    return s.substr(0, itr);

}

vector<string> split(string s, string delim) {
    vector<string> strings;
    size_t pos = 0;
    string substring;
    while ((pos = s.find(delim)) != string::npos) {
        substring = s.substr(0, pos);
        strings.push_back(removeSpaces(substring));
        s.erase(0, pos+1);
    }
    strings.push_back(removeSpaces(s));

    return strings;
}

int main(int argc, char **argv)
{
    map<string, person> table;

    // read lines from file and process into Map as they are read
    ifstream file("../test.data");
    string line;
    vector<string> splitString;
    person currData;

    while (getline(file, line)) {
        if (line[0] == '#' || line.length() == 0) {
            continue;
        }

        splitString = split(line, ",");
        currData.dob = splitString[0];
        
        // If line is missing data
        if (splitString.size() < 5) {
            if (splitString[2] == "y" || splitString[2] == "n") {
                currData.colour = "None";
                currData.likes_peas = splitString[2];
                currData.dogs_or_cats = splitString[3];
            }
        } else {
            // Nothing is missing, enter as expected
            currData.colour = splitString[2];
            currData.likes_peas = splitString[3];
            currData.dogs_or_cats = (splitString[4] == "") ? "Neither" : splitString[4];
        }
        
        // insert into map
        table.insert({splitString[1], currData});
    }

    // Prints to stdout the data from the lookup table sorted by key
    cout << "# Data from table sorted by key" << endl;
    for (map<string, person>::iterator i = table.begin(); i != table.end(); i++)
    {
        cout << "Name: " << i->first << "\n";
        printPerson(i->second);
        cout << endl;
    }

    // Prints a list of names that like peas.
    cout << "# Names of the people who like peas:" << endl;
    for (map<string, person>::iterator i = table.begin(); i != table.end(); i++)
    {
        if (i->second.likes_peas == "y") {
            cout << i->first << endl;
        }
    }
    cout << endl;

    // Get user input for name, return data if found, otherwise error
    string target;
    bool run = true;

    // loop until exit conditions are met
    while (run) {
        cout << "Enter a name to get the data for: ";
        cin >> target;

        // exit conditions
        if (target == "exit" || target == "") {
            run == false;
            continue;
        }

        // look for target name in table
        // alternatively could use throw for an exception and no loop
        if (table.find(target) == table.end()) {
            cout << "Name not found" << endl;
        } else {
            cout << "Name: " << target << endl;
            printPerson(table[target]);
        }
    }

    return 0;
}
