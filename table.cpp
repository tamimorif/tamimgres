#include <string>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

class Table {
    string tableName;

    ofstream getFile() {
        string FILE_PATH = "../" + tableName + ".txt";
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
        ifstream file("../" + tableName + ".txt");
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
        string filePath = "../" + tableName + ".txt";
        int result = remove(filePath.c_str());
        if (result != 0) {
            throw runtime_error("Error deleting file");
        }
    }
};

