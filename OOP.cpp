#include <iostream>
#include <iomanip>

using namespace std;

const int onePomodoro = 25;

struct Maingoal
{
    string name;
    string todo[9];
    string matrial[10];
};

struct Pomodoro
{
    int numbersOfPomodoros;
    string todo_in_rest;
};

class TimeTable
{
private:
    // 4 sections
    struct Maingoal main_goals[3];
    struct Pomodoro pomodoros[5];
    string rates;
    string notes;

public:
    TimeTable(){}
    TimeTable(string l, string m, string n)
    {
        main_goals[0].name = l;
        main_goals[1].name = m;
        main_goals[2].name = n;
    }
    void setMaingoals(int num, string namee)
    {
        main_goals[num].name = namee;
    }
    void setGoalsTodo(int MGnum, int num, string namee)
    {
        main_goals[MGnum].todo[num] = namee;
    }
    void setRates(string eva)
    {
        rates = eva;
    }
    void setNotes(string note)
    {
        notes = note;
    }
    string getMainGoalName(int num)
    {
        return main_goals[num].name;
    }
    string getGoalsTodo(int MGnum, int num)
    {
        return main_goals[MGnum].todo[num];
    }
};

void cheer()
{
    cout << "Thank you for using our TimeTable application" << endl;
    cout << "cheers @Mina_Phoenix" << endl;
}

string PrintNTable(int width, string s);

void menu(int numeee);

int main()
{
    TimeTable tt;
    bool existsTable = false;
    int choice;
    do
    {
        menu(1);
        cin >> choice;
        if (choice == 1)        // new timetable
        {
            existsTable = true;
            menu(2);
            cin >> choice;
            if (choice == 1)
            {
                cout << "Enter the 3 main goals: {1, 2, 3} & name" << endl;
                for (int i = 0; i < 3; i++)
                {
                    string goalName;       int goalnum;         cin >> goalnum;
                    getline(cin, goalName);
                    tt.setMaingoals(goalnum-1, goalName);
                }
                for (int i = 0; i < 3; i++) 
                {
                    bool flag = false;
                    string th; if (i == 0) th = "first"; if (i == 1) th = "second"; if (i == 2) th = "third";
                    cout << "Enter todo of the " << th << " main goal" << endl;
                    for (int j = 0; j < 9; j++)
                    {
                        
                        string goaalName;
                        if (!flag) getline(cin, goaalName);
                        if (goaalName == "-")
                        {
                            flag = true;
                        }
                        if (flag) goaalName = "-";
                        tt.setGoalsTodo(i, j, goaalName);
                    }
                }
            }
        }
        else if (choice == 2)       // status remain timetable
        {
            if (!existsTable)
            {
                cout << "There is no TimeTable exists" << endl;
                continue;
            }
            menu(3);
            cin >> choice;
            if (choice == 1)
            {                   // half of table = 45 >> quart of table = 22
                cout << ".___________________________________________________________________________________________." << endl;
                cout << "|" << PrintNTable(45, tt.getMainGoalName(0)) << "|" << PrintNTable(45, "") << "|" << endl;
                cout << "|_____________________________________________|" << PrintNTable(45, "") << "|" << endl;
                cout << "|" << PrintNTable(22, tt.getGoalsTodo(0, 0)) << "|                      |" << PrintNTable(45, "") << "|" << endl;
                cout << "|" << PrintNTable(22, tt.getGoalsTodo(0, 1)) << "|                      |_____________________________________________" << "|" << endl;
                cout << "|" << PrintNTable(22, tt.getGoalsTodo(0, 2)) << "|                      |" << PrintNTable(45, "") << "|" << endl;
                cout << "|" << PrintNTable(22, tt.getGoalsTodo(0, 3)) << "|                      |" << PrintNTable(45, "") << "|" << endl;
                cout << "|" << PrintNTable(22, tt.getGoalsTodo(0, 4)) << "|                      |" << PrintNTable(45, "") << "|" << endl;
                cout << "|" << PrintNTable(22, tt.getGoalsTodo(0, 5)) << "|                      |" << PrintNTable(45, "") << "|" << endl;
                cout << "|" << PrintNTable(22, tt.getGoalsTodo(0, 6)) << "|                      |" << PrintNTable(45, "") << "|" << endl;
                cout << "|" << PrintNTable(22, tt.getGoalsTodo(0, 7)) << "|                      |" << PrintNTable(45, "") << "|" << endl;
                cout << "|" << PrintNTable(22, tt.getGoalsTodo(0, 8)) << "|                      |" << PrintNTable(45, "") << "|" << endl;
                cout << "|_____________________________________________|" << PrintNTable(45, "") << "|" << endl;
                cout << "|" << PrintNTable(45, tt.getMainGoalName(1)) << "|" << PrintNTable(45, "") << "|" << endl;
                cout << "|_____________________________________________|" << PrintNTable(45, "") << "|" << endl;
                cout << "|" << PrintNTable(22, tt.getGoalsTodo(1, 0)) << "|                      |_____________________________________________" << "|" << endl;
                cout << "|" << PrintNTable(22, tt.getGoalsTodo(1, 1)) << "|                      | Rates:                                      " << "|" << endl;
                cout << "|" << PrintNTable(22, tt.getGoalsTodo(1, 2)) << "|                      |" << PrintNTable(45, "") << "|" << endl;
                cout << "|" << PrintNTable(22, tt.getGoalsTodo(1, 3)) << "|                      |" << PrintNTable(45, "") << "|" << endl;
                cout << "|" << PrintNTable(22, tt.getGoalsTodo(1, 4)) << "|                      |" << PrintNTable(45, "") << "|" << endl;
                cout << "|" << PrintNTable(22, tt.getGoalsTodo(1, 5)) << "|                      |" << PrintNTable(45, "") << "|" << endl;
                cout << "|" << PrintNTable(22, tt.getGoalsTodo(1, 6)) << "|                      |_____________________________________________" << "|" << endl;
                cout << "|" << PrintNTable(22, tt.getGoalsTodo(1, 7)) << "|                      | Notes:                                      " << "|" << endl;
                cout << "|" << PrintNTable(22, tt.getGoalsTodo(1, 8)) << "|                      |" << PrintNTable(45, "") << "|" << endl;
                cout << "|_____________________________________________|" << PrintNTable(45, "") << "|" << endl;
                cout << "|" << PrintNTable(45, tt.getMainGoalName(2)) << "|" << PrintNTable(45, "") << "|" << endl;
                cout << "|_____________________________________________|" << PrintNTable(45, "") << "|" << endl;
                cout << "|" << PrintNTable(22, tt.getGoalsTodo(2, 0)) << "|                      |" << PrintNTable(45, "") << "|" << endl;
                cout << "|" << PrintNTable(22, tt.getGoalsTodo(2, 1)) << "|                      |" << PrintNTable(45, "") << "|" << endl;
                cout << "|" << PrintNTable(22, tt.getGoalsTodo(2, 2)) << "|                      |" << PrintNTable(45, "") << "|" << endl;
                cout << "|" << PrintNTable(22, tt.getGoalsTodo(2, 3)) << "|                      |" << PrintNTable(45, "") << "|" << endl;
                cout << "|" << PrintNTable(22, tt.getGoalsTodo(2, 4)) << "|                      |" << PrintNTable(45, "") << "|" << endl;
                cout << "|" << PrintNTable(22, tt.getGoalsTodo(2, 5)) << "|                      |" << PrintNTable(45, "") << "|" << endl;
                cout << "|" << PrintNTable(22, tt.getGoalsTodo(2, 6)) << "|                      |" << PrintNTable(45, "") << "|" << endl;
                cout << "|" << PrintNTable(22, tt.getGoalsTodo(2, 7)) << "|                      |" << PrintNTable(45, "") << "|" << endl;
                cout << "|" << PrintNTable(22, tt.getGoalsTodo(2, 8)) << "|                      |" << PrintNTable(45, "") << "|" << endl;
                cout << "|___________________________________________________________________________________________|" << endl;
            }
        }
    } while (choice != 0);
    cheer();
}
void menu(int numeee)
{
    if (numeee == 1)            // main
    {
        cout << "1- Create a new timetable" << endl;
        cout << "2- Status remain timetable" << endl;
        cout << "0- Exit" << endl;
    }
    else if (numeee == 2)        // new timetable
    {
        cout << "1- Main Goals" << endl;
        cout << "2- Pomodoros" << endl;
        // cout << "3- Rates" << endl;
        // cout << "4- Notes" << endl;
    }
    else if (numeee == 3)       // sub numeee 2
    {
        cout << "1- Display TimeTable temblete" << endl;
    }
}

string PrintNTable(int width, string s)
{
    int len = s.length();
    if (width < len) return s;
    int deff = width - len;
    int pad1 = deff/2;
    int pad2 = deff - pad1;
    return string(pad1, ' ') + s + string(pad2, ' ');
}