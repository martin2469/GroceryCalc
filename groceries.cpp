#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

class groceries {
private:
    bool martin = 0, alin = 0, ray = 0, rani = 0, ken = 0;
    unordered_map<string, double> totals;
public:
    groceries() {
        totals["Martin"] = 0;
        totals["Alin"] = 0;
        totals["Ray"] = 0;
        totals["Rani"] = 0;
        totals["Ken"] = 0;
    }
    void all_true();
    void all_false();
    int num_paying();
    void input();
    
};

void groceries::all_true() {
    martin = 1, alin = 1, ray = 1, rani = 1, ken = 1;
}

void groceries::all_false() {
    martin = 0, alin = 0, ray = 0, rani = 0, ken = 0;
}

int groceries::num_paying() {
    int n = 0;
    if (martin) {
        n++;
    }
    if (alin) {
        n++;
    }
    if (ray) {
        n++;
    }
    if (rani) {
        n++;
    }
    if (ken) {
        n++;
    }
    return n;
}

// m = martin, a = alin, k = ken, y = ray, r = rani
void groceries::input() {
    double price;
    cout << "Enter a price, followed by who's included\n";
    do{
        cout << "$ ";
        cin >> price;
        if (price == 0) {
            break;
        }
        string paying;
        getline(cin >> ws, paying);
        if (paying[0] == 'e') {
            all_true();
            if (paying.length() != 1) {
                if (paying.find('m') != string::npos) {
                    martin = 0;
                }
                if (paying.find('a') != string::npos) {
                    alin = 0;
                }
                if (paying.find('y') != string::npos) {
                    ray = 0;
                }
                if (paying.find('k') != string::npos) {
                    ken = 0;
                }
                if (paying.find('r') != string::npos) {
                    rani = 0;
                }
            }
        }
        else {
            if (paying.find('m') != string::npos) {
                martin = 1;
            }
            if (paying.find('a') != string::npos) {
                alin = 1;
            }
            if (paying.find('y') != string::npos) {
                ray = 1;
            }
            if (paying.find('k') != string::npos) {
                ken = 1;
            }
            if (paying.find('r') != string::npos) {
                rani = 1;
            }
        }
        double price_each = price / static_cast<double>(num_paying());
        if (martin) {
            totals["Martin"] += price_each;
        }
        if (alin) {
            totals["Alin"] += price_each;
        }
        if (ray) {
            totals["Ray"] += price_each;
        }
        if (rani) {
            totals["Rani"] += price_each;
        }
        if (ken) {
            totals["Ken"] += price_each;
        }

        all_false();
    } while (price != 0);

    cout << "Totals:\n    Martin: $" << ceil(totals["Martin"] * 100.0) / 100.0 << '\n'
         << "    Alin: $" << ceil(totals["Alin"] * 100.0) / 100.0 << '\n'
         << "    Ray: $" << ceil(totals["Ray"] * 100.0) / 100.0 << '\n'
         << "    Rani: $" << ceil(totals["Rani"] * 100.0) / 100.0 << '\n'
         << "    Ken: $" << ceil(totals["Ken"] * 100.0) / 100.0 << '\n';
}

int main() {
    groceries g;
    g.input();
}