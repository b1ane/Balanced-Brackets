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

    void print() {
        node* current = top;
        while( current != nullptr) {
            cout << current->data << endl;
            current = current -> next;
        }
    }

};

bool openBracket(char value) {
    return( value == '(' || value == '{' || value == '[' );
}

bool closeBracket(char value) {
    return( value == ')' || value == '}' || value == ']' );
}

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
            //cout << inputString << endl;
        }
    }
    file.close();

    stack stack1;

    bool isBalanced;

    //separate string by characters, push bracket into stack
    for( int i = 0; i < inputString.size(); i++) {
        char value = inputString[i];
        if(openBracket(value)) {
            stack1.push( value);
        } 
        //if closing bracket, check if it's a match with the top value
        if(closeBracket(value)) {
            //stores top value in topBracket
            char topBracket = stack1.peek();
            //deletes that value 
            //if value and top bracket do not match, string is not balanced
            if(value == ')' && topBracket != '(' || value == ']' && topBracket != '[' || value == '}' && topBracket != '{' ) {
                isBalanced = false;
            }
            else {
                stack1.pop();
            }
        }
    }

    if(stack1.isEmpty()) {
        isBalanced = true;
    }

    ofstream outputfile("output.txt");


    if(isBalanced) {
        outputfile << "True" << endl;
    }
    else {
        outputfile << "False" << endl;
    }

}