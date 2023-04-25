#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class Table {
public:
    std::string tableName;

    std::ofstream getFile() {
        std::string FILE_PATH = "./" + tableName + ".txt";
        std::ofstream file(FILE_PATH, std::ios::app);
        return file;
    }

    void saveColumnNames(std::vector<std::string> values) {
        std::ofstream file = getFile();
        std::string newRow;
        for (auto &value : values) {
            newRow += value + ",";
        }
        newRow += '\n';
        file.write(newRow.c_str(), newRow.size());
        file.close();
    }

    Table(std::string name, std::vector<std::string> columnNames) {
        tableName = name;
        saveColumnNames(columnNames);
    }

    void saveNewRow(std::vector<std::string> values) {
        auto file = getFile();
        std::string newRow;
        for (auto &value : values) {
            newRow += value + ",";
        }
        newRow += '\n';
        file << newRow;
        file.close();
    }
};

class TamimDatabase {
public:
    Table createTable(string tableName, vector<string> columnNames) {
        // TODO: Check if table exist, if yes, throw an error
        Table table(tableName, columnNames);
        if (tableName == table.tableName) {
            throw runtime_error("Table already exist");
        }
        return table;
    }

    // dropTable
    //    Table dropTable(string tableName){
    //
    //    }
};

//
int main() {
    TamimDatabase tdb;
    vector<string> columns = {"id", "name", "age", "phoneNumber"};
    // Print the vector elements

    Table studentTable = tdb.createTable("students", columns);
    cout << "Created a table " << endl;

    // Save a new row of data in the table
    studentTable.saveNewRow({"1", "Tamim", "20", "1234"});
    studentTable.saveNewRow({"2", "Milod", "23", "1234"});
    return 0;
}