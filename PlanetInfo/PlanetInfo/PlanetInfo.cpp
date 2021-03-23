#include <iostream>
#include <vector>
using namespace std;

class Planet
{
private:  
    string name;
    long int d;    
    bool has_life;
    int moons;

public:
    Planet();
    ~Planet();
    string get_name();
    long int get_d();
    bool get_h_l();
    int get_moons();

    void set_name(Planet*, int);
    void set_name(string);
    void set_d();
    void set_d(int);
    void set_h_l();
    void set_h_l(bool);
    void set_moons();
    void set_moons(int);
};

bool contain_planet(Planet* p_l, string lk, int n) {
    bool m = false;
    for (int i = 0; i < n; i++) {
        if (p_l[i].get_name() == lk) {
            
            m = true;
        }
    }
    return m;
}

int find_planet(Planet* p_l, string lk, int n) {
    int f;
    for (int i = 0; i < n; i++) {
        if (p_l[i].get_name() == lk) {
            f = i;
        }
    }
    return f;
}
inline string Planet::get_name() { return name; }
void Planet::set_name(Planet* p_l, int N){
    string n;
    cout << "Введите название:" << endl;
    cin >> n;
    bool m = contain_planet(p_l, n, N);
        while (m != false) {
            cout << "такая планета уже есть" << endl;
            cin >> n;
            m = contain_planet(p_l, n, N);
        }
    name = n;
    
    
}
Planet::Planet() {}
Planet::~Planet() {}
void Planet::set_name(string n) {
    name = n;
}

long int Planet::get_d() { return d; }
void Planet::set_d() {
    long int D;
    cout << "Введите диаметр:" << endl;
    bool t = false;
    while (t != true) {
        cin >> D;
        if (D > 0) {
            t = true;
        } 
    }
    d = D;
}

void Planet::set_d(int D) {
    d = D;
}

bool Planet::get_h_l() { return has_life; }
void Planet::set_h_l() {
    bool h_l;
    int h_l_int;
    cout << "Введите есть ли жизнь(1/0):" << endl;
    
    bool t = false;
    while (t != true) {
        
        cin >> h_l_int;
        if (h_l_int == 0 || h_l_int == 1) {
            t = true;
        }
    }
    h_l = h_l_int;
    has_life = h_l;
}

void Planet::set_h_l(bool h_l) {
    has_life = h_l;
}

int Planet::get_moons() { return moons; }
void Planet::set_moons(){
    int m;
    cout << "Введите количество спутников:" << endl;
    
    bool t = false;
    while (t != true) {
        cin >> m;
        if (m >= 0) {
            t = true;
        }
        
    }
    moons = m;
}

void Planet::set_moons(int m) {
    moons = m;
}

void sort(Planet* p_l, int* s, int N) {
    Planet temp;
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - 1 - i; j++) {
            if (s[j] > s[j+1]) {
                temp = p_l[j];
                p_l[j] = p_l[j+1];
                p_l[j+1] = temp;
            }
        }
    }
}

void sort(Planet* p_l, char** s, int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (strcmp(s[i], s[j])>0) {
                Planet temp = p_l[i];
                p_l[i] = p_l[j];
                p_l[j] = temp;
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    Planet* planet_list = new Planet[30];
    planet_list[0].set_name("ghf");
    planet_list[1].set_name("abc");
    planet_list[2].set_name("zxc");
    planet_list[0].set_d(12);
    planet_list[1].set_d(1);
    planet_list[2].set_d(5);
    planet_list[0].set_h_l(1);
    planet_list[1].set_h_l(0);
    planet_list[2].set_h_l(1);
    planet_list[0].set_moons(12);
    planet_list[1].set_moons(1);
    planet_list[2].set_moons(5);
    n = 4;
    //planet_list[3].set_name("gfdfg");
    //planet_list[3].set_d(12);
    //planet_list[3].set_h_l(0);
    //planet_list[3].set_moons(1);
    int k = -1;
    
    cout << "1 - удалить, 2 - добавить, 3 - вывести, 4 - изменить, 5 - сортировать, 0 - выход" << endl; 
    while (k != 0) { 
        cin >> k;
        switch (k) {
        case 1: { //удалить
            cout << "введите название" << endl;
            string name;
            cin >> name;
            int f=0;
            if (contain_planet(planet_list, name, n)) {
                f = find_planet(planet_list, name, n);
                if (n - f != 1) {
                    for (int i = f; i < n - 1; i++) {
                        planet_list[i] = planet_list[i + 1];
                    }
                }
                n--;
            }
            else cout << "Нет такой планеты" << endl;
            cout << "1 - удалить, 2 - добавить, 3 - вывести, 4 - изменить, 5 - сортировать, 0 - выход" << endl;
            break;
            }
        case 2: { //добавить
           
            planet_list[n].set_name(planet_list, n);
            bool check = false;
            
            if (!contain_planet(planet_list, planet_list[n].get_name(), n))
            {
               
                planet_list[n].set_d();
                planet_list[n].set_h_l();
                planet_list[n].set_moons();
            }
            
             n++;
             cout << "1 - удалить, 2 - добавить, 3 - вывести, 4 - изменить, 5 - сортировать, 0 - выход" << endl;
            break;
        }
        case 3: { //вывести
            if (n != 0) {
                for (int i = 0; i < n; i++) {
                    string life;
                    if (planet_list[i].get_h_l()) life = "жизнь есть";
                else life = "жизни нет";
                cout << i << ") " << planet_list[i].get_name() << " d = " << planet_list[i].get_d() << " " << life << " спутники: " << planet_list[i].get_moons() << endl;
                }
            }
            else {
                cout << "нет планет" << endl;
            }
            cout << "1 - удалить, 2 - добавить, 3 - вывести, 4 - изменить, 5 - сортировать, 0 - выход" << endl;
            break;
        }
        case 4: { //изменить
            cout << "Введите имя:" << endl;
            string name;
            cin >> name;
            if (contain_planet(planet_list, name, n)) {
                int f = find_planet(planet_list, name, n);
                cout << "какой параметр изменить: имя - 1, диаметр - 2, наличие жизни - 3, количество спутников - 4" << endl;
                int number;
                cin >> number;
                switch (number) {
                case 1: {                
                    planet_list[f].set_name(planet_list, n);
                    break;
                }
                case 2: {
                    planet_list[f].set_d();
                    break;
                }
                case 3: {
                    planet_list[f].set_h_l();
                    break;
                }
                case 4: {
                    planet_list[f].set_moons();
                    break;
                }
                }
            } else cout << "Нет такой планеты" << endl;
            cout << "1 - удалить, 2 - добавить, 3 - вывести, 4 - изменить, 5 - сортировать, 0 - выход" << endl;
            break;
        }
        case 5: { //сортировать
            if (n != 0) {
                cout << "по какому параметру отсортировать: имя - 1, диаметр - 2, количество спутников - 3" << endl;
                int p;
                cin >> p;
                switch (p) {
                case 1: {
                    char** ds = new char* [n];
                    for (int i = 0; i < n; i++)
                        ds[i] = new char[30];
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < n; j++) {
                            ds[i][j] = planet_list[i].get_name()[j];
                        }
                    }
                    sort(planet_list, ds, n);
                    break;
                }
                case 2: {
                    int* ds = new int[n];
                    for (int i = 0; i < n; i++) {
                        ds[i] = planet_list[i].get_d();
                    }
                    sort(planet_list, ds, n);
                    break;
                }
                case 3: {
                    int* ms = new int[n];
                    for (int i = 0; i < n; i++) {
                        ms[i] = planet_list[i].get_moons();
                    }
                    sort(planet_list, ms, n);
                    break;
                }
                }
                break;
            }
            else {
                cout << "нечего сортировать" << endl;
            }
            cout << "1 - удалить, 2 - добавить, 3 - вывести, 4 - изменить, 5 - сортировать, 0 - выход" << endl;
        }
        default:
            break;
        }  
    } 
    return 0;
}



//cccccccccccccccccccccccccccccccccceeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeerrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrfffffffffffffffffffffffffffffff