#include <iostream>

class Date {
public:
    int j;
    int m;
    int a;

    void afficher() { std::cout << j << "/" << m << "/" << a << std::endl; }

    void incr() {
        // 1) Combien de jours dans le mois actuel ?
        int max;
        if (m == 2) {
            if ((a % 4 == 0 && a % 100 != 0) || a % 400 == 0)
                max = 29;   // année bissextile
            else
                max = 28;
        } else if ((m <= 7 && m % 2 == 1) || (m >= 8 && m % 2 == 0)) {
            max = 31;       // janv, mars, mai, juil, août, oct, déc
        } else {
            max = 30;       // avr, juin, sept, nov
        }

        // 2) On avance d'un jour
        if (j < max) {
            j += 1;
        } else {            // fin du mois
            j = 1;
            if (m < 12) {
                m += 1;
            } else {        // fin de l'année
                m = 1;
                a += 1;
            }
        }
    }
};

int main() {
    Date d;
    d.j = 31; d.m = 12; d.a = 2026;
    d.afficher();
    d.incr();
    d.afficher();
    return 0;
}
