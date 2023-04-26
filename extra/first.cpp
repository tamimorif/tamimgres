#include "iostream"
//class Table{
//    Table(std::string name, std::vector<std::string> columnNames) {
//        tableName = name;
//        saveColumnNames(columnNames);
//    }
//};
int main(){
    std::string myString = "Hello, world!";
    const char* myCString = myString.c_str();
    std::cout << myCString;
}