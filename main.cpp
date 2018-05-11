#include "queue.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main(){

  cout << "********** Now running Ultimate Homework Planner **********" << endl;
  cout << "Please enter your name:" << endl;
  string name;
  cin >> name;
  cout << endl;
  cout << "Hi " << name << "!" << endl;

  cout << "Ultimate Homework Planner is an application that will organize your homeworks for you by creating a schedule that sorts your homeworks by due date and priority." << endl;
  cout << endl;
  cout << "Would you like us to help you? (Y/N)" << endl;

  char answer;
  cin >> answer;
  if (answer != 'N' && answer != 'Y') {
    while (answer != 'N' && answer != 'Y') {
      cout << "Invalid response. Please try again." << endl;
      cin >> answer;
    }
  }
  if (answer == 'N'){
    cout << "Goodbye!" << endl;
    return 0;
  }
  cout << endl;
  cout << "Great! We are happy to help. Let's begin by entering all your classes. Please enter a -1 when you're done to indicate the end of your input." << endl;
  string classname;
  vector<string> allclasses;
  cin.ignore();
  while (classname != "-1") {
    allclasses.push_back(classname);
    getline(cin, classname);
  }

  cout << endl;
  cout << "Thank you! We will now display a list of the classes you just entered to confirm." << endl;
  int count = 1;

  for (unsigned i = 1; i < allclasses.size(); i++) {
    cout << count << ") " << allclasses[i] << endl;
    count++;
  }

  cout << endl;
  cout << "Let's move on to adding all homeworks due for each class." << endl;
  cout << endl;

  HWqueue *queue = new HWqueue();
  for (unsigned i = 1; i < allclasses.size(); i++) {
    cout << "Class: " << allclasses[i] << endl;
    string homework;
    int duedate;
    int priority;
    cout << "Do you have homeworks for this class? (Y/N)" << endl;
    char ans;
    cin >> ans;
    if (ans != 'N' && ans != 'Y') {
      while (ans != 'N' && ans != 'Y') {
        cout << "Invalid response. Please try again." << endl;
        cin >> ans;
      }
    }
    if (ans == 'Y'){
      cout << "Please enter one of your homeworks for this class." << endl;
      cin.ignore();
      getline(cin,homework);
      while (homework != "-1") {
        cout << "What priority would you give this homework?" << endl;
        cin >> priority;
        cout << "How many days until it's due?" << endl;
        cin >> duedate;
        queue->insert(homework, allclasses[i], priority, duedate);
        cout << "Please enter your next homework for this class (if done, enter -1)." << endl;
        cin.ignore();
        getline(cin, homework);
      }
    }
    cout << endl;
  }

  cout << endl;
  cout << "Awesome! We have finished adding all of your homeworks to our system." << endl;
  cout << endl;
  queue->sort();
  cout << "We recommend you work on your homeworks in this order:" << endl;
  cout << endl;
  queue->print();

  cout << endl;
  cout << "Thank you for using our service. We hope you visit us again soon!" << endl;

}
