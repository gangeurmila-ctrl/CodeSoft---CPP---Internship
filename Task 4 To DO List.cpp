#include <iostream>
#include <vector>
using namespace std;

class Task {
public:
    string name;
    bool completed;

    Task(string n) {
        name = n;
        completed = false;
    }
};

int main() {
    vector<Task> tasks;
    int choice;
    cout << "\n \n Welcome to TO DO List \n";
    do {
        cout << "\n===== TO-DO LIST =====\n";
        cout << "1. Add Task";
        cout << "\n2. View Tasks\n";
        cout << "3. Mark Completed";
        cout << "\n4. Delete Task";
        cout << "\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if(choice == 1) {
            string name;
            cout << "Enter task: ";
            getline(cin,name);
            tasks.push_back(Task(name));
        }

        else if(choice == 2) {
            for(size_t i=0; i<tasks.size(); i++)
                cout << i+1 << ". " << tasks[i].name 
                     << (tasks[i].completed ? " [Done]" : " [Pending]") << endl;
        }

        else if(choice == 3) {
            int num;
            cout << "Enter task number: ";
            cin >> num;
            tasks[num-1].completed = true;
        }

        else if(choice == 4) {
            int num;
            cout << "Enter task number: ";
            cin >> num;
            tasks.erase(tasks.begin()+num-1);
        }

    } while(choice != 5);

    return 0;
}