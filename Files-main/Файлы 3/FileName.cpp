#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {

        fstream fin, fout;
        float x0, x1, dx, res{};
        int p = 2, k = 1;

        fin.open("in1.txt", ios::in);
        fin >> x0 >> x1 >> dx;
        fin.close();

        fout.open("out1.txt", ios::out);
        fout << "x  |  y" << endl;

        while (x0 < x1) {
            fout << x0 << "  |  ";
            res += pow(-1, p) * k * x0;
            fout << res << endl;;
            x0 += dx;
            p++;
            k++;
        }

        fout.close();

	return 0;
}