#include <iostream>
#include <string>
using namespace std;

const int MAX_TIKET = 100;

struct Tiket {
    int id;
    string nama_event;
    int jumlah_tiket;
};

// Stack Implementation
struct StackNode {
    Tiket data;
    StackNode* next;
};

class Stack {
public:
    StackNode* top;

    Stack() { top = nullptr; }

    void push(Tiket tiket) {
        StackNode* newNode = new StackNode;
        newNode->data = tiket;
        newNode->next = top;
        top = newNode;
        cout << "Tiket berhasil ditambahkan ke Stack!\n";
    }

    Tiket pop() {
        if (isEmpty()) {
            cout << "Stack kosong!\n";
            Tiket emptyTiket = {0, "Kosong", 0};
            return emptyTiket;
        }
        StackNode* temp = top;
        Tiket tiket = top->data;
        top = top->next;
        delete temp;
        return tiket;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void tampilkanStack() {
        StackNode* current = top;
        if (!current) {
            cout << "Stack kosong!\n";
            return;
        }
        cout << "Daftar Tiket dalam Stack:\n";
        while (current) {
            cout << "ID: " << current->data.id
                 << ", Nama Event: " << current->data.nama_event
                 << ", Jumlah Tiket: " << current->data.jumlah_tiket << endl;
            current = current->next;
        }
    }
};

// Queue Implementation
struct QueueNode {
    Tiket data;
    QueueNode* next;
};

class Queue {
public:
    QueueNode* front;
    QueueNode* rear;

    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(Tiket tiket) {
        QueueNode* newNode = new QueueNode;
        newNode->data = tiket;
        newNode->next = nullptr;

        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Tiket berhasil ditambahkan ke Queue!\n";
    }

    Tiket dequeue() {
        if (isEmpty()) {
            cout << "Queue kosong!\n";
            Tiket emptyTiket = {0, "Kosong", 0};
            return emptyTiket;
        }
        QueueNode* temp = front;
        Tiket tiket = front->data;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
        return tiket;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void tampilkanQueue() {
        QueueNode* current = front;
        if (!current) {
            cout << "Queue kosong!\n";
            return;
        }
        cout << "Daftar Tiket dalam Queue:\n";
        while (current) {
            cout << "ID: " << current->data.id
                 << ", Nama Event: " << current->data.nama_event
                 << ", Jumlah Tiket: " << current->data.jumlah_tiket << endl;
            current = current->next;
        }
    }
};

// Fungsi untuk input tiket
Tiket inputTiket() {
    Tiket tiket_baru;
    cout << "Masukkan ID Tiket: ";
    cin >> tiket_baru.id;
    cout << "Masukkan Nama Event: ";
    cin.ignore();
    getline(cin, tiket_baru.nama_event);
    cout << "Masukkan Jumlah Tiket: ";
    cin >> tiket_baru.jumlah_tiket;
    return tiket_baru;
}

int main() {
    Stack tiketStack;
    Queue tiketQueue;
    int pilihan;

    while (true) {
        cout << "\n=== Sistem Pengelolaan Tiket dengan Queue dan Stack ===\n";
        cout << "1. Tambah Tiket ke Stack\n";
        cout << "2. Tambah Tiket ke Queue\n";
        cout << "3. Tampilkan Tiket dari Stack\n";
        cout << "4. Tampilkan Tiket dari Queue\n";
        cout << "5. Hapus Tiket dari Stack (Pop)\n";
        cout << "6. Hapus Tiket dari Queue (Dequeue)\n";
        cout << "7. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                Tiket tiket = inputTiket();
                tiketStack.push(tiket);
                break;
            }
            case 2: {
                Tiket tiket = inputTiket();
                tiketQueue.enqueue(tiket);
                break;
            }
            case 3:
                tiketStack.tampilkanStack();
                break;
            case 4:
                tiketQueue.tampilkanQueue();
                break;
            case 5: {
                Tiket tiket = tiketStack.pop();
                if (tiket.id != 0) {
                    cout << "Tiket dengan ID " << tiket.id << " dihapus dari Stack.\n";
                }
                break;
            }
            case 6: {
                Tiket tiket = tiketQueue.dequeue();
                if (tiket.id != 0) {
                    cout << "Tiket dengan ID " << tiket.id << " dihapus dari Queue.\n";
                }
                break;
            }
            case 7:
                return 0;
            default:
                cout << "Pilihan tidak sesuai. Silakan coba lagi.\n";
        }
    }
    return 0;
}