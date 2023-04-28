#include "table.cpp"
#include <iostream>

int main() {
    TamimDatabase tdb;
    printf("Please select one option:\n");
    printf("1.Create table\n");
    printf("2.Drop table\n");
    printf("3.Show table\n");
    int x;
    cin >> x;
    if (x == 1) {
        cout << "Enter table name: ";
        string tablename;
        cin >> tablename;
        cout << "How many column do you want? ";
        int columnnumber;
        cin >> columnnumber;
        vector<string> columnNames;
        for (int i = 1; i <= columnnumber; ++i) {
            cout << "Enter column name " << i << ": ";
            string column;
            cin >> column;
            columnNames.push_back(column);
        }
        tdb.createTable(tablename, columnNames);
        cout << "Created a table\n";
    } else if (x == 2) {
        for (;;) {
            printf("Enter table name: ");
            string tablename;
            cin >> tablename;
            tdb.dropTable(tablename);
            cout << "Table deleted\n";
        }
    } else if (x == 3) {
        string tableName;
        for (;;) {
            printf("Enter table name: ");
            cin >> tableName;
            if (!tdb.doesTableExist(tableName)) {
                throw runtime_error("Table does not exist");
            } else {
                break;
            }
        }
        ifstream inputFile("../" + tableName + ".txt");
        if (inputFile.is_open()) {
            string line;
            while (getline(inputFile, line)) {
                cout << line;
            }
            cout << '\n';
            inputFile.close();
        } else {
            std::cout << "Unable to open file\n";
        }
    } else {
        cout << "Invalid choice.\n";
    }
    return 0;
}