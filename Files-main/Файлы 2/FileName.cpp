#include <iostream> 
#include <fstream>

using namespace std;

int main() {
    int x;
    string y;
    cout << "Vvedite nomer treka: ";
    cin >> x;
    if (x == 1) {
        y = "1.mp3";
    }
    if (x == 2) {
        y = "2.mp3";
    }
    if (x == 3) {
        y = "3.mp3";
    }
    ifstream input(y, ios::binary);
    if (!input.is_open()) {
        cout << "Oshibka otkritiya faila" << endl;
        return 1;
    }

    input.seekg(0, ios::end);
    int size = input.tellg();
    input.seekg(0, ios::beg);

    input.seekg(-128, ios::end);

    char buffer[128];
    input.read(buffer, 128);

    if (buffer[0] == 'T' && buffer[1] == 'A' && buffer[2] == 'G') {

        string title(buffer + 3, buffer + 33);
        string artist(buffer + 33, buffer + 63);
        string album(buffer + 63, buffer + 93);
        string year(buffer + 93, buffer + 97);
        string comment(buffer + 97, buffer + 127);
        int track = buffer[126];

        cout << "Nazvanie: " << title << endl;
        cout << "Ispolnitel: " << artist << endl;
        cout << "Albom: " << album << endl;
        cout << "God: " << year << endl;
        cout << "Komentariy: " << comment << endl;
        if (track != 0) {
            cout << "Nomer treka: " << track << endl;
        }
    }
    else {
        cout << "ID3v1 teg ne naiden" << endl;
    }

    input.close();

    return 0;
}