#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include<functional>
using namespace std;
// Define a Task class
class Task {
public:
    std::string name;
    int priority;

    Task(const std::string& name, int priority) : name(name), priority(priority) {}

    // Overload the < operator to compare priorities
    bool operator>(const Task& other) {
    	cout<<"operator > is invoked"<<endl;
        return priority > other.priority;  // Higher priority means higher value
    }

    friend std::ostream& operator<<(std::ostream& os, const Task& task) {
        os << "Task: " << task.name << ", Priority: " << task.priority;
        return os;
    }
};

int main() {
    // Create a priority queue of Task objects
   // std::priority_queue<Task> taskQueue;
	std::priority_queue<Task,vector<Task>,greater<Task> >taskQueue;
    // Push Task objects onto the priority queue
    taskQueue.push(Task("Task1", 1));
    taskQueue.push(Task("Task2", 5));
    taskQueue.push(Task("Task3", 3));

    // Display and pop elements from the priority queue
    while (!taskQueue.empty()) {
        std::cout << "Processing " << taskQueue.top() << std::endl;
        taskQueue.pop();
    }

    return 0;
}

