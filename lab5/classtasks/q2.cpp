#include <iostream>
#include <string>

using namespace std;

struct Node {
    string data;
    Node* next;
    Node(string d) : data(d), next(nullptr) {}
};

class Stack {
private:
    Node* topNode;

    void printReverse(Node* node, bool& first) {
        if (node == nullptr) return;
        printReverse(node->next, first);
        if (!first) cout << " ";
        cout << node->data;
        first = false;
    }

public:
    Stack() : topNode(nullptr) {}

    void push(string data) {
        Node* newNode = new Node(data);
        newNode->next = topNode;
        topNode = newNode;
    }

    string pop() {
        if (isEmpty()) return "";
        Node* temp = topNode;
        string popped = temp->data;
        topNode = topNode->next;
        delete temp;
        return popped;
    }

    bool isEmpty() {
        return topNode == nullptr;
    }

    void clear() {
        while (!isEmpty()) {
            pop();
        }
    }

    void printStack() {
        bool first = true;
        printReverse(topNode, first);
        cout << endl;
    }
};

class TextEditor {
private:
    Stack undoStack;
    Stack redoStack;

    void clear_redo() {
        redoStack.clear();
    }

public:
    void type(string word) {
        undoStack.push(word);
        clear_redo();
    }

    void undo() {
        if (!undoStack.isEmpty()) {
            redoStack.push(undoStack.pop());
        }
    }

    void redo() {
        if (!redoStack.isEmpty()) {
            undoStack.push(redoStack.pop());
        }
    }

    void print() {
        undoStack.printStack();
    }
};

int main() {
    TextEditor editor;
    
    editor.type("Hello");
    editor.print();
    
    editor.type("World");
    editor.print();
    
    editor.undo();
    editor.print();
    
    editor.redo();
    editor.print();
    
    editor.undo();
    editor.print();
    
    editor.type("There");
    editor.print();
    
    editor.redo();
    editor.print();

    return 0;
}