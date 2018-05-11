#include <iostream>
#include <string>

using namespace std;

class task{
public:
  string name;
  string classname;
  int priority;
  int days;
  double doit;
  task *next;
  ~task(){
    delete next;
  }
};

class HWqueue{
private:
  task *head, *tail;

public:
  HWqueue(){
    head = NULL;
    tail = NULL;
  }
  ~HWqueue();
  void print();
  void insert(string name, string classname, int priority, int days);
  void sort();
  void destroy(string name);
  task search(string name);
};

//Methods

void HWqueue::sort()
{
  task * front;
  front = head;
  task * follow = front;
  if(front->next == NULL)
    return;

  front = front->next;
  bool swap = true;
  while(swap)
  {
    swap = false;
    while(front != NULL && follow != NULL)
    {
      if(front->doit < follow->doit)
      {
        task *temp = follow->next;
        follow->next = front->next;
        front->next = temp;

        swap = true;
      }
      front = front->next;
      follow = follow->next;
    }
  }
}

task HWqueue::search(string name)
{
  task * p;
  p = head;

  while(p != NULL)
  {
    if(p->name == name)
      return *p;
    p = p->next;
  }
  return *p;
}
void HWqueue::print()
{
  task * p;
  p = head;
  cout << "---------------" << endl;
  while(p != NULL)
  {
    cout << "Task: " << p->name << "\nClass: " << p->classname << endl;
    p = p->next;
    cout << "---------------" << endl;
  }

}

void HWqueue::insert(string name, string classname, int priority, int days)
{
  task *temp = new task;
  temp->name = name;
  temp->classname = classname;
  temp->priority = priority;
  temp->days = days;
  temp->next = head;
  temp->doit = (double)priority/days;
  head = temp;
}

void HWqueue::destroy(string name)
{
  task * front;
  task * follow;
  front = head;
  follow = front;
  if(front->name == name)
  {
    follow->next = front->next;
    delete front;
    return;
  }

  while(front != NULL)
  {
    front = front->next;
    if(front->name == name)
    {
      follow->next = front->next;
      return;
    }
    follow = follow->next;
  }
}
