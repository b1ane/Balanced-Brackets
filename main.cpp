#include <iostream>
#include <string>
#include <fstream>
using namespace std;


struct node {
    char data;
    node* next;
};

class stack {
    private:
    node* top; //points to first element in stack

    public:
    //Constructor
    stack() { 
        top = nullptr;
    }

    //Returns value at front of list 
    char peek() {
        return top->data;
    }

    //Insert at FRONT
    void push(char value) {
        node* newNode = new node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    //Delete at FRONT
    void pop() {
        node* temp = new node;
        temp = top;
        top = top->next;
        delete temp;
    }

    bool isEmpty() {
        return top == nullptr;
    }






};

int main(int argc, char** argv) {
    if(argc!=2) {
        return 1;
    }

    string inputString;

    string inputFile;
    inputFile = argv[1];

    ifstream file;
    file.open(inputFile);
    if(file.is_open()) {
        while(getline(file, inputString)) {
            cout << inputString << endl;
        }
    }
    file.close();



}