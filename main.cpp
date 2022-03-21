#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.141592653589793;

class angle{
private:
    int grade, minute, secunde;
public:
    angle()=default;
    angle(int grade, int minute, int secunde) : grade(grade), minute(minute), secunde(secunde) {}
    angle(double x) ;
    void print(){
        cout<<"Unghiul are "<<grade<<" grade, "<<minute<<" minute si "<<secunde<<" secunde"<<endl;
    }
    double radians(){
        double x = grade + double(minute)/60 + double(secunde)/3600;
        return x * PI / 180;
    }
    double sin(){
        if (::sin(this->radians()) > 0.99)
            return 1.0;
        if (::sin(this->radians()) < 0.01)
            return 0.0;
        return ::sin(this->radians());
    }
    double cos(){
        if (::cos(this->radians()) > 0.99)
            return 1.0;
        if (::cos(this->radians()) < 0.01)
            return 0.0;
        return ::cos(this->radians());
    }
    double tan(){
        return ::tan(this->radians());
    }
    double cot(){
        if (::tan(this->radians()) != 0)
            return 1/::tan(this->radians());
        else return 1.7976931348623157E+308;
    }

    int getGrade() const {
        return grade;
    }

    int getMinute() const {
        return minute;
    }

    int getSecunde() const {
        return secunde;
    }

    void setGrade(int grade) {
        angle::grade = grade;
    }

    void setMinute(int minute) {
        angle::minute = minute;
    }

    void setSecunde(int secunde) {
        angle::secunde = secunde;
    }


};
angle :: angle(double x) {double z, y;
    z = x * 180 / PI;
    grade = int(z);
    z = modf(z, &y) * 60;
    minute = int(z);
    z = modf(z, &y) * 60;
    secunde = int(z);
}
angle aduna(angle a1, angle a2){
    angle a3;
    a3.setGrade(a1.getGrade()+a2.getGrade());
    a3.setMinute(a1.getMinute()+a2.getMinute());
    a3.setSecunde(a1.getSecunde()+a2.getSecunde());

    return a3;
}
angle minim(angle a, angle b){
    if (a.getGrade() > b.getGrade())
        return b;
    else if (a.getGrade() < b.getGrade())
        return a;
    if (a.getMinute() > b.getMinute())
        return b;
    else if (a.getMinute() < b.getMinute())
        return a;
    if (a.getSecunde() >= b.getSecunde())
        return b;
    else
        return a;
}

class Triunghi{
private:
    angle a, b, c;
public:
    Triunghi(const angle &a, const angle &b, const angle &c) : a(a), b(b), c(c) {}

    void unghiminim_afisare(){
        minim(minim(a, b),c).print();
    }
    angle unghiminim(){
        return minim(minim(a, b),c);

    }
    void laturi(double l);
    void arie(double l);
    void ascutit(){
        if (a.getGrade()>=90 or b.getGrade()>=90 or c.getGrade()>=90)
            cout<<"Triunghiul nu este ascutitunghic"<<endl;
        else cout<<"Triunghiul este ascutitunghic"<<endl;

    }
    void cerinta(double l){
        this->unghiminim_afisare();
        this->laturi(l);
        this->arie(l);
        this->ascutit();

    }


};
void Triunghi :: laturi(double l){ //cu t sinusului e cel mai simplu
    double l1, l2 , l3;
    l1 = l * a.sin() / this->unghiminim().sin();
    l2 = l * b.sin() / this->unghiminim().sin();
    l3 = l * c.sin() / this->unghiminim().sin();

    cout<<"Lungimile laturilor sunt "<<l1<<", "<<l2<<" si "<<l3<<endl;
}
void Triunghi :: arie(double l){
    double l1, l2 , l3, p;
    l1 = l * sin(a.radians()) / this->unghiminim().sin();
    l2 = l * sin(b.radians()) / this->unghiminim().sin();
    l3 = l * sin(c.radians()) / this->unghiminim().sin();
    p = (l1 + l2 + l3) / 2;
    cout<<"Aria triunghiului este "<<sqrt(p*(p-l1)*(p-l2)*(p-l3))<<endl;
}




int main() {
angle a1 (23, 30, 10);
angle a2 (PI / 2);
angle a0;
angle a3 = aduna(a1, a2);
a3.print();
cout<<"Unghiul are "<<a3.radians()<<" rad"<<endl;
cout<<"Unghiul are "<<a2.radians()<<" rad"<<endl;
cout<<"Cosinusul unghiului este "<<a2.cos()<<endl<<endl; // nu afiseaza 0 (dar e foarte aproape) fara aproximare, problema e ca nici la cout << cos(PI/2) nu afiseaza 0, calcule pe double :)
                                                         // ma intriga ca a2.sin() da 1 :/
Triunghi t1(angle(30, 0, 0), angle(60, 0, 0), angle(90, 0, 0));
t1.cerinta(30);

    return 0;
}
