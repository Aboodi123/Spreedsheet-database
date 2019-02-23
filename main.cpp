#include <iostream>
#include <vector>


using namespace std;
/// have polymorphic ability
class Column {
protected:
    string name;
    string type;
    vector<int> intListColumn;
    vector<string> stringListColumn;
    vector<bool> boolListColumn;
public:

    Column() {
        name = "default";
        type = "default";
    }

    Column(const string &name) : name(name) {}

    virtual const string &getName() const {
        return name;
    }

    virtual void printName() {
        cout << getName() << "\t";
    };

    virtual const string &getType() const {
        return type;
    }

    virtual void addToColumn(int number) {
        intListColumn.push_back(number);
    }

    virtual void addToColumn(string number) {
        stringListColumn.push_back(number);
    }

    virtual void addToColumn(bool number) {
        boolListColumn.push_back(number);
    }

    virtual void removeFromColumn(int index) {

        if ((intListColumn.size() >= index) || (boolListColumn.size() >= index) || (stringListColumn.size() >= index)) {
            if (!intListColumn.empty()) {
                intListColumn.erase(intListColumn.begin() + index - 1);
            } else if (!stringListColumn.empty()) {
                stringListColumn.erase(stringListColumn.begin() + index - 1);
            } else if (!boolListColumn.empty()) {
                boolListColumn.erase(boolListColumn.begin() + index - 1);
            }

        }

    }


    virtual void printColumn() {
        if (!intListColumn.empty()) {
            for (const auto &i : intListColumn) {
                cout << i << "\t";
            }

        } else if (!stringListColumn.empty()) {
            for (const auto &i : stringListColumn) {
                cout << i << "\t";

            }
        } else if (!boolListColumn.empty()) {
            for (const auto &i : boolListColumn) {
                cout << i << "\t";
            }
        }

        cout << endl;
    };

};


class IntColumn : public Column {

public:
    explicit IntColumn(const string &name) : Column(name) {
        type = "int";
    }

    const string &getName() const override {
        return name;
    }

    void printName() override {
        cout << getName() << "\t";
    };

    const string &getType() const override {
        return type;
    }

    void printColumn() override {
        for (const auto &i : intListColumn) {
            cout << i << "\t";
        }
        cout << endl;
    };


    void addToColumn(int number) override {
        intListColumn.push_back(number);
    }

};


class StringColumn : public Column {

public:
    StringColumn(const string &name) : Column(name) {
        type = "string";
    }

    const string &getName() const override {
        return name;
    }

    void printName() override {
        cout << getName() << "\t";
    };


    const string &getType() const override {
        return type;
    }

    void printColumn() override {
        for (const auto &i : stringListColumn) {
            cout << i << "\t";
        }

    };

    void addToColumn(string number) override {
        stringListColumn.push_back(number);
    }

    void updateAColumn(int index) {
        cin >> stringListColumn.at(index);
    }
};

class BoolColumn : public Column {

public:
    BoolColumn(const string &name) : Column(name) {
        type = "bool";
    }

    const string &getName() const override {
        return name;
    }

    void printName() override {
        cout << getName() << "\t";
    };


    const string &getType() const override {
        return type;
    }

    void printColumn() override {
        for (const auto &i : boolListColumn) {
            cout << i << "\t";
        }

    };

    void addToColumn(bool number) override {
        boolListColumn.push_back(number);
    }

    void updateAColumn(int index) {
        cin >> stringListColumn.at(index);
    }
};


class Table {
private:
    string name;
    vector<Column> columns;

public:


    Table(const string &name) : name(name) {

    }

    const string &getName() const {
        return name;
    }

    void addIntergerColumn(string name) {
        IntColumn intColumn(name);
        columns.push_back(intColumn);
    }

    void addString(string name) {
        StringColumn stringColumn(name);
        columns.push_back(stringColumn);
    }

    void addBool(string name) {
        BoolColumn boolColumn(name);
        columns.push_back(boolColumn);
    }

    void addNewColumn() {
        int type;
        string name;


        cout << "what type do you want(string(1) /interger(2) /boolean(3))" << endl;
        cin >> type;

        cout << "the name of the column" << endl;
        cin >> name;
        switch (type) {
            case 1:
                addString(name);
                break;
            case 2:
                addIntergerColumn(name);
                break;
            case 3:
                addBool(name);
                break;
            default:
                break;
        }
    }

    void printColumns() {
        printColumnsName();

    }

    void printColumnsName() {
        for (auto &column : columns) {
            cout <<
                 column.getName() << "(" << column.getType() << ")" << "\t";
            column.printColumn();
        }
        cout << endl;
    }

    void insertIntoATable(int indexOfColumn) {
        if (columns.at(static_cast<unsigned int>(indexOfColumn)).getType() == "string") {
            StringColumn stringColumn(columns.at(static_cast<unsigned int>(indexOfColumn)).getName());
            string value;
            cout << "enter the value to( " << columns.at(static_cast<unsigned int>(indexOfColumn)).getType() << ")"
                 << columns.at(static_cast<unsigned int>(indexOfColumn)).getName() << endl;
            cin >> value;
            columns.at(static_cast<unsigned int>(indexOfColumn)).addToColumn(value);
        } else if (columns.at(static_cast<unsigned int>(indexOfColumn)).getType() == "int") {
            IntColumn intColumn(columns.at(static_cast<unsigned int>(indexOfColumn)).getName());
            int value;
            cout << "enter the value to( " << columns.at(static_cast<unsigned int>(indexOfColumn)).getType() << ")"
                 << columns.at(static_cast<unsigned int>(indexOfColumn)).getType() << endl;
            cin >> value;
            columns.at(static_cast<unsigned int>(indexOfColumn)).addToColumn(value);
        } else if (columns.at(static_cast<unsigned int>(indexOfColumn)).getType() == "bool") {
            BoolColumn boolColumn(columns.at(static_cast<unsigned int>(indexOfColumn)).getName());
            int value;
            cout << "enter the value to( " << columns.at(static_cast<unsigned int>(indexOfColumn)).getType() << ")"
                 << columns.at(static_cast<unsigned int>(indexOfColumn)).getType() << endl;
            cin >> value;
            if (value == 1) {
                value = true;
            } else {
                value = false;
            }
            columns.at(static_cast<unsigned int>(indexOfColumn)).addToColumn(value);
        }
    }

    void insertARowIntoATable() {
        cout << endl;
        for (int i = 0; i < columns.size(); ++i) {
            insertIntoATable(i);
        }
    }

    void deleteEntryIntheTable() {
        cout << " enter the index to remove" << endl;
        int index;
        cin >> index;
        for (int i = 0; i < columns.size(); ++i) {
            columns[i].removeFromColumn(index);

        }
    }
};


class Database {
private:
    vector<Table> tables;
    string name;
public:
    Database(const string &name) : name(name) {}

    const string &getName() const {
        return name;
    }

    const vector<Table> &getTables() const {
        return tables;
    }

    void addNewTable(string name) {
        char yesNO;
        Table table(name);
        do {
            cout << "Add a column(Y/N)" << endl;
            cin >> yesNO;
            switch (yesNO) {
                case 'y':
                    table.addNewColumn();
                    break;
                default:
                    break;
            }
        } while (yesNO != 'n');
        tables.push_back(table);
    }

    void workOnATable() {
        string name;
        cout << "Enter the name of the table" << endl;
        cin >> name;
        for (int i = 0; i < tables.size(); ++i) {
            if (tables[i].getName() == name) {
                int operation;

                do {

                    cout << " 1. to insert into the table " << endl;
                    cout << "2. to display table " << endl;
                    cout << "3. delete entire row" << endl;
                    cout << "0. go back" << endl;
                    cin >> operation;
                    switch (operation) {
                        case 1:
                            tables[i].insertARowIntoATable();
                            break;
                        case 2:
                            tables[i].printColumns();
                            break;
                        case 3:
                            tables[i].deleteEntryIntheTable();
                            break;
                        default:
                            break;
                    }
                } while (operation != 0);
                break;
            }
        }

    }

    void removeTable() {
        string name;
        cout << "enter the name of the table to delete" << endl;
        cin >> name;
        for (int i = 0; i < tables.size(); ++i) {
            if (tables[i].getName() == name) {
                tables.erase(tables.begin() + i);
                break;
            }
        }

    }

    void printTables() {
        for (auto &table : tables) {
            cout << table.getName() << endl;
        }
        if (tables.empty()) {
            cout << "empty database" << endl;
        }
    }

    void performOperation() {

        int operation;
        do {
            string name;
            cout << "********************************************" << getName() << endl;
            cout << "1. add new table " << endl;
            cout << "2. delete Table" << endl;
            cout << "3. list of tables" << endl;
            cout << "4. perform oparation on a table" << endl;
            cout << "0. Go back" << endl;
            cout << "********************************************" << getName() << endl;
            cout << "Enter the operation to perform " << endl;

            cin >> operation;
            switch (operation) {
                case 1:
                    cout << "enter the desire name of table" << endl;
                    cin >> name;
                    addNewTable(name);
                    break;
                case 2:
                    removeTable();
                    break;
                case 3:
                    cout << "**************************list of tables******************" << endl;
                    printTables();
                    break;
                case 4:
                    workOnATable();
                    break;
                default:
                    break;
            }

        } while (operation != 0);
    }
};


class UserInterface {
private:
    vector<Database> databases;


    void createNewDatabase() {
        string name;
        cout << " Enter the name of the database you want" << endl;
        cin >> name;
        Database database(name);
        databases.push_back(database);
    }

    void printAllDatabasess() {
        for (int i = 0; i < databases.size(); ++i) {
            databases[i].getName();
        }
    }

public:
    void operationUser() {
        int operation;
        do {
            cout << "____________________________________________________________))" << endl;
            cout << "1. create a database " << endl;
            cout << "2. print all databases" << endl;
            cout << "3. perform operation" << endl;
            cout << "0. go back" << endl;
            cout << "____________________________________________________________))" << endl;
            cin >> operation;
            switch (operation) {
                case 1:
                    createNewDatabase();
                    break;
                case 2:
                    printAllDatabasess();
                    break;
                case 3:
                    performingOperationOnADatabase();
                    break;
                default:
                    break;
            }
        } while (operation != 0);


    }

private:
    void performingOperationOnADatabase() {
        string name;
        cout << "name of the database you want to work on" << endl;
        cin >> name;

        for (auto &database : databases) {
            if (database.getName() == name) {
                database.performOperation();
            } else {
                cout << "no database was found for this " << endl;
            }
        }

    }

};

int main() {

    UserInterface userInterface;
    userInterface.operationUser();
    return 0;
}
