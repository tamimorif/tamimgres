#include "main.cpp"

int main() {
    TamimDatabase tdb;
    printf("Please select one option:\n");
    printf("1.Create table\n");
    printf("2.Drop table\n");
    printf("3.Show table\n");
    int x;
    scanf("%d", x);
    switch (x) {
        case 1:
            printf("Enter table name: ");
            string tablename;
            scanf("%s", tablename);


    }


    vector<string> columns{"id", "name", "age", "phoneNumber"};
    Table studentTable = tdb.createTable("student", columns);
    cout << "Created a table " << endl;
    vector<string> values{"1", "Tamim", "20", "1234"};
    studentTable.saveNewRow(values);
    return 0;
}
