
#include <iostream>
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
    void set_name(string);
    void set_d(int);
    void set_h_l(bool);
    void set_moons(int);
};

inline string Planet::get_name() 
{ 
    return name; 
}

void Planet::set_name(string NAME) 
{
    name = NAME;
}

long int Planet::get_d() 
{ 
    return d; 
}

void Planet::set_d(int D) 
{
    d = D;
}

bool Planet::get_h_l() 
{ 
    return has_life; 
}

void Planet::set_h_l(bool h_l) 
{
    has_life = h_l;
}
int Planet::get_moons() 
{ 
    return moons; 
}

void Planet::set_moons(int m) 
{
    moons = m;
}

Planet::Planet() {}

Planet::~Planet() {}

bool compareFunction(std::string a, std::string b) { return a < b; }

void sort(Planet* p_l, int* s, int N) {
    Planet temp;
    int tempint;
    for (int i = 0; i < N - 1; i++) { 
        for (int j = 0; j < N - 1 - i; j++) {
            if (s[j] > s[j + 1]) {
                tempint = s[j];
                s[j] = s[j + 1];
                s[j + 1] = tempint;
                temp = p_l[j];
                p_l[j] = p_l[j + 1];
                p_l[j + 1] = temp;
            }
        }
    }
}

void sort(Planet* p_l, char** s, int N) {
    
    for (int i = 0; i < N-1; i++) {
        for (int j = i+1; j < N; j++)
        {
            if (strcmp(s[i], s[j]) > 0)
            {
                char* tempchar = s[i];
                s[i] = s[j];
                s[j] = tempchar;
                Planet temp = p_l[i];
                p_l[i] = p_l[j];
                p_l[j] = temp;
                cout << i << " " << j << endl;
            }
            
        }
        
    }
}

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
    int f=0;
    for (int i = 0; i < n; i++) {
        if (p_l[i].get_name() == lk) {
            f = i;
        }
    }
    return f;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    Planet* planet_list = new Planet[30];
    planet_list[0].set_name("labc");
    planet_list[1].set_name("fehjs");
    planet_list[2].set_name("kdwkj");
    planet_list[3].set_name("wnmm");
    planet_list[0].set_d(12);
    planet_list[1].set_d(1);
    planet_list[2].set_d(5);
    planet_list[3].set_d(5);
    planet_list[0].set_h_l(1);
    planet_list[1].set_h_l(0);
    planet_list[2].set_h_l(1);
    planet_list[3].set_h_l(1);
    planet_list[0].set_moons(12);
    planet_list[1].set_moons(1);
    planet_list[2].set_moons(5);
    planet_list[3].set_moons(5);
    
    n = 4;
    int k = -1;
    cout << "1 - удалить, 2 - добавить, 3 - вывести, 4 - изменить, 5 - сортировать, 0 - выход" << endl;
    while (k != 0) {
        cin >> k;
        switch (k) {
        case 1: { //удалить
            cout << "введите название" << endl;
            string name;
            cin >> name;
            int findplanet = 0;
            if (contain_planet(planet_list, name, n)) {
                findplanet = find_planet(planet_list, name, n);
                if (n - findplanet != 1) {
                    for (int i = findplanet; i < n - 1; i++) {
                        planet_list[i] = planet_list[i + 1];
                    }
                }
                n--;
            }
            else
                cout << "нет такой планеты" << endl;
            cout << "1 - удалить, 2 - добавить, 3 - вывести, 4 - изменить, 5 - сортировать, 0 - выход" << endl;
            break;
        }
        case 2: { //добавить
            cout << "введите название планеты" << endl;
            string name;
            long int d;
            bool h_l;
            int moons;
            cin >> name;
            bool containplanet = contain_planet(planet_list, name, n);
            while (containplanet != false) {
                cout << "такая планета уже существует" << endl;
                cout << "введите название планеты" << endl;
                cin >> name;
                containplanet = contain_planet(planet_list, name, n);
            }
            planet_list[n].set_name(name);

            cout << "введите диаметр" << endl;
            bool t;
            cin >> d;
            d > 0 ? t = true : t = false;
            while (t != true) {
                cout << "введите верный диаметр" << endl;
                cin >> d;
                d > 0 ? t = true : t = false;
            }
            planet_list[n].set_d(d);

            cout << "введите есть ли жизнь на планете" << endl;
            cin >> h_l;
            (h_l == 1 || h_l == 0) ? t = true : t = false;
            while (t != true) {
                cout << "введите 1 или 0" << endl;
                cin >> h_l;
                (h_l == 1 || h_l == 0) ? t = true : t = false;
            }
            planet_list[n].set_h_l(h_l);

            cout << "введите количество спутников" << endl;
            cin >> moons;
            moons >= 0 ? t = true : t = false;
            while (t != true) {
                cout << "введите настоящее количество спутников" << endl;
                cin >> moons;
                moons >= 0 ? t = true : t = false;
            }
            planet_list[n].set_moons(moons);

            n++;

            cout << "1 - удалить, 2 - добавить, 3 - вывести, 4 - изменить, 5 - сортировать, 0 - выход" << endl;
            break;
        }
        case 3: { //вывести
            if (n != 0) {
                for (int i = 0; i < n; i++) {
                    string life;
                    if (planet_list[i].get_h_l() == 0)
                        life = "нет жизни ";
                    else
                        life = "есть жизнь ";
                    cout << planet_list[i].get_name() << " d = " << planet_list[i].get_d() << " " << life << "спутники: " << planet_list[i].get_moons() << endl;
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
                int findplanet = find_planet(planet_list, name, n);
                cout << "какой параметр изменить: имя - 1, диаметр - 2, наличие жизни - 3, количество спутников - 4" << endl;
                int parameter;
                cin >> parameter;
                switch (parameter) {
                case 1: {
                    cout << "введите новое имя" << endl;
                    string name;
                    cin >> name;
                    bool containplanet = contain_planet(planet_list, name, n);
                    while (containplanet != false) {
                        cout << "такая планета уже существует" << endl;
                        cout << "введите название планеты" << endl;
                        cin >> name;
                        containplanet = contain_planet(planet_list, name, n);
                    }
                    planet_list[findplanet].set_name(name);

                    break;
                }
                case 2: {
                    cout << "введите новый диаметр" << endl;
                    bool t;
                    long int d;
                    cin >> d;
                    d > 0 ? t = true : t = false;
                    while (t != true) {
                        cout << "введите верный диаметр" << endl;
                        cin >> d;
                        d > 0 ? t = true : t = false;
                    }
                    planet_list[findplanet].set_d(d);
                    break;
                }
                case 3: {
                    bool h_l;
                    cout << "введите есть ли жизнь на планете" << endl;
                    cin >> h_l;
                    bool t;
                    if (h_l == 1 || h_l == 0) {
                        t = true;
                    }
                    else {
                        t = false;
                    }
                    
                    while (t != true) {
                        cout << "введите 1 или 0" << endl;
                        cin >> h_l;
                        if (h_l == 1 || h_l == 0) {
                            t = true;
                        }
                        else {
                            t = false;
                        }
                    }
                    planet_list[findplanet].set_h_l(h_l);
                    break;
                }
                case 4: {
                    int moons;
                    cout << "введите новое количество спутников" << endl;
                    cin >> moons;
                    bool t;
                    moons >= 0 ? t = true : t = false;
                    while (t != true) {
                        cout << "введите настоящее количество спутников" << endl;
                        cin >> moons;
                        moons >= 0 ? t = true : t = false;
                    }
                    planet_list[findplanet].set_moons(moons);
                    break;
                }
                default: {
                    break;
                }
                }
            }
            else cout << "Нет такой планеты" << endl;
            cout << "1 - удалить, 2 - добавить, 3 - вывести, 4 - изменить, 5 - сортировать, 0 - выход" << endl;
            break;
        }
        case 5: { //сортировать
            if (n != 0) {
                cout << "по какому параметру отсортировать: имя - 1, диаметр - 2, количество спутников - 3" << endl;
                int parameter;
                cin >> parameter;
                switch (parameter) {
                case 1: {
                    Planet t;
                    for (int i = 0; i < n; ++i) {
                        for (int j = 0; j < n - 1 - i; ++j) {
                            if (planet_list[j].get_name() > planet_list[j + 1].get_name()) {
                                t = planet_list[j + 1];
                                planet_list[j + 1] = planet_list[j];
                                planet_list[j] = t;
                            }
                        }
                    }
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
                default: {
                    break;
                }
                }
            }
            else {
                cout << "нечего сортировать" << endl;
            }
            cout << "1 - удалить, 2 - добавить, 3 - вывести, 4 - изменить, 5 - сортировать, 0 - выход" << endl;
            break;
        }
        default:
            break;

        }
    }
}

