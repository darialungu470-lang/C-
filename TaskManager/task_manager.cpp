#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <typeinfo>

using namespace std;

struct Task{
  int id;
  string title;
  bool completed;
};

vector<Task> tasks;

void addTask(){
  struct Task t;
  cout << "Дайте назввание: ";
  cin.ignore();
  getline(cin,t.title);
  t.id = tasks.size() + 1;
  t.completed = false;
  tasks.push_back(t);
}

void showTasks(){
  if (tasks.empty()) {
    cout << "Пока что нет задач:)" << endl;
    return;
  }

  for (auto task : tasks) {
    if (task.completed)
      cout << "[x] ";
    else
      cout << "[~] ";
    cout << task.id << ". " << task.title << endl;
  }
}

void completeTask() {
  int id;
  cout << "Укажите номер задачи: ";
  cin >> id;
  if (typeid(id).name() != "i" | id < 1 | id > tasks.size()) {
    cout << "Задача не найдена!(" << endl;
    return;
  }
  for (auto& task : tasks) {
    if (task.id == id ) {
      task.completed = true;
      return;
    }
  }

}

void deleteTask() {
  int id;
  cout << "Введите номер задачи: ";
  cin >> id;
  if (typeid(id).name() != "i" | id < 1 | id > tasks.size()) {
    cout << "Задача не найдена!(" << endl;
    return;
  }
  tasks.erase((tasks.begin()+id-1));
  for (auto it = (tasks.begin() + id - 1); it != tasks.end(); ++it) {
    it->id = id;
    ++id;
  }
}

void storage() {
  ofstream file("tasks.txt");

  for (const auto& task : tasks)
    file << task.id << "|" << task.title << "|" << task.completed << endl;
  file.close();
}

void loading_data() {
  ifstream file("tasks.txt");
  string line;

  if (!file) {
    cout << "Oшибка открытия файла!" << endl;
    return ;
  }

  while (getline(file, line)) {
    int pos1 = line.find("|");
    int pos2 = line.find("|", pos1 + 1);
    Task task;
    task.id = stoi(line.substr(0,pos1));
    task.title = line.substr(pos1+1,pos2 - pos1 - 1);
    task.completed = stoi(line.substr(pos2 + 1));
    tasks.push_back(task);
  }

  file.close();
}

void menu(){

  loading_data();
  while(true){
    cout << "1. Добавить задачу" << endl;
    cout << "2. Показать задачи" << endl;
    cout << "3. Отметить как выполненную" << endl;
    cout << "4. Удалить задачу" << endl;
    cout << "5. Выход" << endl;

    int choice;
    cout << "Выберите функцию: ";
    cin >> choice;

    switch(choice) {
      case 1:
        addTask();
        break;
      case 2:
        showTasks();
        break;
      case 3:
        completeTask();
        break;
      case 4:
        deleteTask();
          break;
      case 5:
        storage();
          return;
      default:
        cout << "Don't correct choice(.." << endl;
    }
  }
}

int main(){

  menu();

  return 0;
}
