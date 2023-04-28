#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class Table {
    string tableName;

    ofstream getFile() {
        string FILE_PATH = "./" + tableName + ".txt";
        ofstream file(FILE_PATH, ios::app);
        return file;
    }

    void saveColumnNames(vector<string> values) {
        ofstream file = getFile();
        string newRow;
        for (string &value : values) {
            newRow += value + ",";
        }
        newRow += '\n';
        file.write(newRow.c_str(), newRow.size());
        file.close();
    }

public:
    Table(string name, vector<string> columnNames) {
        tableName = name;
        saveColumnNames(columnNames);
    }

    void saveNewRow(vector<string> values) {
        ofstream file = getFile();
        string newRow;
        for (string &value : values) {
            newRow += value + ",";
        }
        newRow += '\n';
        file << newRow;
        file.close();
    }
};

class TamimDatabase {
public:
    bool doesTableExist(string tableName) {
        ifstream file("./" + tableName + ".txt");
        return file.good();
    }

    Table createTable(string tableName, vector<string> columnNames) {
        if (doesTableExist(tableName)) {
            throw runtime_error("Table already exists");
        }
        Table table(tableName, columnNames);
        return table;
    }

    void dropTable(string tableName) {
        if (!doesTableExist(tableName)) {
            throw runtime_error("Table does not exist");
        }
        string filePath = "./" + tableName + ".txt";
        int result = remove(filePath.c_str());
        if (result != 0) {
            throw runtime_error("Error deleting file");
        }
    }
};


int main() {
    TamimDatabase tdb;
    vector<string> columns{"id", "name", "age", "phoneNumber"};
    Table studentTable = tdb.createTable("students", columns);
    cout << "Created a table " << endl;
    vector<string> values{"1", "Tamim", "20", "1234"};
    studentTable.saveNewRow(values);
    // columns.push_back("id");
    // columns.push_back("name");
    // columns.push_back("age");
    // columns.push_back("phoneNumber");

    // tdb.dropTable("students");
    // Save a new row of data in the table

    // values.push_back("1");
    // values.push_back("Tamim");
    // values.push_back("20");
    // values.push_back("1234");

    return 0;
}
