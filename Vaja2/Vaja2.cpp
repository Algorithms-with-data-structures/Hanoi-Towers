//TOWERS OF HANOI

#include <iostream>
using namespace std;

void displayMenu() {
    cout << "1) Set initial state of the game." << endl;
    cout << "2) Move the top disk from tower X to tower Y." << endl;
    cout << "3) Display towers." << endl;
    cout << "Choice: ";
}

void push(int* tower, int value, int& top, int max) {
    if ((top - 1) == max) { // If the index TOP equals the size of the stack, the stack is full
        cout << "ERROR: Tower is full!" << endl;
        cout << endl;
    }
    else {
        tower[top] = value;
        top++;
    }
}

int pop(int* stack, int& top) {
    if (top == 0) { // If the index TOP equals 0, it means the stack is empty
        cout << "ERROR: Tower is empty!" << endl;
        cout << endl;
    }
    else {
        top--; // Otherwise, return the last element in the stack and decrease TOP by 1
        return stack[top];
    }
}

int setInitialState(int& top1, int& top2, int& top3, int*& tower1, int*& tower2, int*& tower3) {
    int numDisks;
    cout << "Number of disks on the 1st tower: ";
    cin >> numDisks;
    const int max = numDisks; // User enters the maximum number of disks on the tower

    tower1 = new int[max];
    for (int i = 0; i < max; i++) { // Build the tower (stack) of length "numDisks" with descending numbers
        push(tower1, numDisks, top1, max);
        numDisks--;
    }

    tower2 = new int[max];
    tower3 = new int[max];

    cout << endl;
    return max;
}

void transferDisk(int max, int& top1, int& top2, int& top3, int*& tower1, int*& tower2, int*& tower3) {
    int fromTower; // Tower from which to transfer
    int toTower;   // Tower to which to transfer
    int disk;      // Disk to transfer

    cout << "From which tower to which tower do you want to move? (Values 1-3)." << endl;

    cout << "From: ";
    cin >> fromTower;
    while (fromTower < 1 || fromTower > 3) { // Get the number of the tower to transfer from
        cout << "Invalid choice (value between 1-3):" << endl << "From: ";
        cin >> fromTower;
    }

    cout << "To: ";
    cin >> toTower;
    while ((toTower < 1 || toTower > 3) || toTower == fromTower) { // Get the number of the tower to transfer to
        cout << "Invalid choice (value between 1-3): " << endl << "To: ";
        cin >> toTower;
    }
    cout << endl;

    if (fromTower == 1 && toTower == 2) {
        if ((tower1[top1 - 1] > tower2[top2 - 1]) && top2 != 0) {
            cout << "Cannot place a larger disk on a smaller disk!" << endl;
        }
        else {
            disk = pop(tower1, top1);
            push(tower2, disk, top2, max);
        }
    }
    else if (fromTower == 1 && toTower == 3) {
        if (tower1[top1 - 1] > tower3[top3 - 1] && top3 != 0) {
            cout << "Cannot place a larger disk on a smaller disk!" << endl;
            cout << endl;
        }
        else {
            disk = pop(tower1, top1);
            push(tower3, disk, top3, max);
        }
    }
    else if (fromTower == 2 && toTower == 1) {
        if (tower2[top2 - 1] > tower1[top1 - 1] && top1 != 0) {
            cout << "Cannot place a larger disk on a smaller disk!" << endl;
            cout << endl;
        }
        else {
            disk = pop(tower2, top2);
            push(tower1, disk, top1, max);
        }
    }
    else if (fromTower == 2 && toTower == 3) {
        if (tower2[top2 - 1] > tower3[top3 - 1] && top3 != 0) {
            cout << "Cannot place a larger disk on a smaller disk!" << endl;
            cout << endl;
        }
        else {
            disk = pop(tower2, top2);
            push(tower3, disk, top3, max);
        }
    }
    else if (fromTower == 3 && toTower == 1) {
        if (tower3[top3 - 1] > tower1[top1 - 1] && top1 != 0) {
            cout << "Cannot place a larger disk on a smaller disk!" << endl;
            cout << endl;
        }
        else {
            disk = pop(tower3, top3);
            push(tower1, disk, top1, max);
        }
    }
    else if (fromTower == 3 && toTower == 2) {
        if (tower3[top3 - 1] > tower2[top2 - 1] && top2 != 0) {
            cout << "Cannot place a larger disk on a smaller disk!" << endl;
            cout << endl;
        }
        else {
            disk = pop(tower3, top3);
            push(tower2, disk, top2, max);
        }
    }

    if (top1 == 0) {
        cout << "GAME OVER!" << endl;
    }
}

void displayTowers(int top1, int top2, int top3, int* tower1, int* tower2, int* tower3) {
    cout << endl;
    cout << "TOWER 1: ";
    for (int i = 0; i < top1; i++) {
        cout << tower1[i] << " ";
    }
    cout << endl;

    cout << "TOWER 2: ";
    for (int i = 0; i < top2; i++) {
        cout << tower2[i] << " ";
    }
    cout << endl;

    cout << "TOWER 3: ";
    for (int i = 0; i < top3; i++) {
        cout << tower3[i] << " ";
    }
    cout << endl;
    cout << endl;
}

int main() {
    bool running = true;
    int choice;

    int* tower1 = nullptr;
    int* tower2 = nullptr;
    int* tower3 = nullptr;

    int top1 = 0;
    int top2 = 0;
    int top3 = 0;
    int max = 0;

    do {
        displayMenu();
        cin >> choice;
        system("cls");
        switch (choice) {
        case 1:
            max = setInitialState(top1, top2, top3, tower1, tower2, tower3);
            break;
        case 2:
            transferDisk(max, top1, top2, top3, tower1, tower2, tower3);
            break;
        case 3:
            displayTowers(top1, top2, top3, tower1, tower2, tower3);
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    } while (running);

    return 0;
}
