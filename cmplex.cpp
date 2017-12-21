#include <iostream>
#include <sstream>
using namespace std;

struct complex_t {
    float real;
    float imag;
};
bool read(istream & stream, complex_t & complex) {
    char ch;
    bool res = true;
    float real, imag;
    if (stream >> ch && ch == '(' &&
    stream >> real &&
    stream >> ch && ch == ',' &&
    stream >> imag &&
    stream>> ch && ch == ')') {
        complex.real = real;
        complex.imag = imag;
    }
    else {res = false; cout << "An error has occured while reading input data";}
    return res;
}

bool write(ostream &stream, complex_t complex) {
    return bool(stream << '(' << complex.real << ',' << complex.imag << ')' << endl);
}

complex_t add(complex_t cm1, complex_t cm2) {
    complex_t complex;
    complex.real = cm1.real + cm2.real;
    complex.imag = cm1.imag + cm2.imag;
    return complex;
}

complex_t sub(complex_t cm1, complex_t cm2) {
    complex_t complex;
    complex.real = cm1.real - cm2.real;
    complex.imag = cm1.imag - cm2.imag;
    return complex;
}

complex_t mul(complex_t cm1, complex_t cm2) {
    complex_t complex;
    complex.real = cm1.real * cm2.real - cm1.imag * cm2.imag;
    complex.imag = cm1.imag * cm2.real + cm1.real * cm2.imag;
    return complex;
}

complex_t div(complex_t cm1, complex_t cm2) {
    complex_t complex;
    complex.real = (cm1.real * cm2.real + cm1.imag * cm2.imag)/(cm2.real * cm2.real + cm2.imag * cm2.imag);
    complex.imag = (cm1.imag * cm2.real - cm1.real * cm2.imag)/(cm2.real * cm2.real + cm2.imag * cm2.imag);
    return complex;
}

int main() {
    complex_t cm1, cm2, itog;
    string string;
    getline(cin, string);
    istringstream stream(string);
    char op;
    if(read(stream, cm1) && stream >> op && read(stream, cm2)) {
    switch (op) {
        case '+': {itog = add(cm1,cm2);
                    break;};
        case '-': {itog = sub(cm1,cm2);
                    break;};
        case '*': {itog = mul(cm1,cm2); 
                    break;};
        case '/': {itog = div(cm1,cm2); 
                    break;};
        default : {cout << "Incorrect operation"; 
                    break;}
        }
        write(cout, itog);
    }
}
