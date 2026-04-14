#include <iostream>
#include <string>
using namespace std;

class TextEditor {
    string text;

    string undoStack[100];
    int undoTop = -1;

    string redoStack[100];
    int redoTop = -1;

public:
    void typeChar(char ch) {
        undoTop++;
        undoStack[undoTop] = text;

        text += ch;

        redoTop = -1;
    }

    void deleteChar() {
        if (text.length() == 0) {
            cout << "Nothing to delete\n";
            return;
        }

        undoTop++;
        undoStack[undoTop] = text;

        text.pop_back();

        redoTop = -1;
    }

    void undo() {
        if (undoTop == -1) {
            cout << "Nothing to undo\n";
            return;
        }

        redoTop++;
        redoStack[redoTop] = text;

        text = undoStack[undoTop];
        undoTop--;
    }

    void redo() {
        if (redoTop == -1) {
            cout << "Nothing to redo\n";
            return;
        }

        undoTop++;
        undoStack[undoTop] = text;

        text = redoStack[redoTop];
        redoTop--;
    }

    void display() {
        cout << "Text: " << text << endl;
    }
};

int main() {
    TextEditor editor;
    int choice;
    char ch;

    while (true) {
        cout << "\n1.Type\n2.Delete\n3.Undo\n4.Redo\n5.Display\n0.Exit\n";
        cin >> choice;

        if (choice == 0)
            break;

        if (choice == 1) {
            cout << "Enter character: ";
            cin >> ch;
            editor.typeChar(ch);
        }
        else if (choice == 2) {
            editor.deleteChar();
        }
        else if (choice == 3) {
            editor.undo();
        }
        else if (choice == 4) {
            editor.redo();
        }
        else if (choice == 5) {
            editor.display();
        }
    }

    return 0;
}