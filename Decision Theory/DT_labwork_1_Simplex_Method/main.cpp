#include <iostream>
#include <vector>
#include <cmath>

//test comment
using namespace std;

const double epsylon = 0.1; // точность
const double m = 0.25; // длина ребра
const size_t n = 2; // размерность
const size_t iteration_max = 100;

struct Coords {
    double x[n];
    size_t index;

    Coords operator+(Coords const& other) {
        Coords tmp;
        for (int i = 0; i < n; ++i)
            tmp.x[i] = x[i] + other.x[i];
        return tmp;
    }

    Coords operator-(Coords const& other) {
        Coords tmp;
        for (int i = 0; i < n; ++i)
            tmp.x[i] = x[i] - other.x[i];
        return tmp;
    }

    Coords operator/(double const& other) {
        Coords tmp;
        for (int i = 0; i < n; ++i)
            tmp.x[i] = x[i]/other;
        return tmp;
    }

    Coords operator*(double const& other) {
        Coords tmp;
        for (int i = 0; i < n; ++i)
            tmp.x[i] = x[i] * other;
        return tmp;
    }

    friend ostream& operator<<(ostream &out,  Coords const& other);

};

ostream& operator<<(ostream &out,  Coords const& other) {
    string temp = "";
    out << "(";
    for (auto it : other.x) {
        out << temp << it;
        temp = ", ";
    }
    out << ")";
    return out;
}

double compute_func(Coords x) {
    return x.x[0]*x.x[0] - x.x[0]*x.x[1] + 3*x.x[1]*x.x[1] - x.x[0];
}

size_t find_max(vector<Coords> const& x_vars) {
double max = compute_func(x_vars[0]);
size_t number = 0;
for(int i = 1;i < x_vars.size();++i) {
double tmp = compute_func(x_vars[i]);
if (max < tmp) {
max = tmp;
number = i;
}
}
cout << "Max func: F(" << number << ") = " << max << endl;
return number;
}

void get_first_coords(vector<Coords>& x_vars) {
    const double delta1 = ((sqrt(n+1)-1)/(n * sqrt(2))) * m;
    const double delta2 = ((sqrt(n+1)+n-1)/(n * sqrt(2))) * m;

    cout << "Delta 1 = " << delta1 << endl;
    cout << "Delta 2 = " << delta2 << endl;


    for (int i = 0; i < n; ++i) {
        Coords tmp;
        for (int j = 0; j < n; ++j) {
            if (i == j)
                tmp.x[j] = x_vars[0].x[j] + delta1;
            else
                tmp.x[j] = x_vars[0].x[j] + delta2;
        }
        tmp.index = i+1;
        x_vars.push_back(tmp);
    }
}

Coords compute_cg(vector<Coords> const& simplex_vars, size_t const& max_var) {
Coords result = simplex_vars[0];
for (int i = 1; i < simplex_vars.size(); ++i) {
if(i != max_var)
result = result + simplex_vars[i];
}
return result/n;
}

Coords reflect_vertex(Coords cg_var, Coords const& vertex) {
    return (cg_var * 2) - vertex;
}

bool check_condition(Coords const& vertex, Coords const& reflected_vertex) {
    return compute_func(reflected_vertex) < compute_func(vertex);
}

size_t find_min(vector<Coords>& simplex_vars) {
    double min = compute_func(simplex_vars[0]);
    size_t number = 0;
    for(int i = 1;i < simplex_vars.size();++i) {
        double tmp = compute_func(simplex_vars[i]);
        if (min > tmp) {
            min = tmp;
            number = i;
        }
    }
    return number;
}

void reduction(vector<Coords>& simplex_vars) {
    size_t number = find_min(simplex_vars);
    for (int i = 0; i < simplex_vars.size(); ++i)
        if (i != number)
            simplex_vars[i] = simplex_vars[number] + (simplex_vars[i] - simplex_vars[number])/2;
}

Coords compute_simplex_cg(vector<Coords> const& simplex_vars) {
Coords result = simplex_vars[0];
for (int i = 1; i < simplex_vars.size(); ++i) {
result = result + simplex_vars[i];
}
return result/(n+1);
}

bool check_for_end(vector<Coords> simplex_vars, Coords simplex_cg) {
    for(auto it : simplex_vars) {
        cout << "|" << compute_func(it) << " - " << compute_func(simplex_cg) << "|";
        if (abs(compute_func(it) - compute_func(simplex_cg)) >= epsylon) {
            cout << " >= " << epsylon << endl;
            cout << "Failed. Going to next iteration..." << endl;
            return false;
        }
        cout << " < " << epsylon << endl;
    }
    cout << "Success. Ending..." << endl;
    return true;
}

void print_simple_vertex(vector<Coords> const& simple_vars) {
for (int i = 0; i < simple_vars.size(); ++i) {
cout << "\tVertex " << i << ": " << simple_vars[i] << endl;
}
}

void print_coords_funcs(vector<Coords> simple_vars) {
    for (int i = 0; i < simple_vars.size(); ++i)
        cout << "\tF(" << i << ") = " << compute_func(simple_vars[i]) << endl;
}

int main() {
    vector<Coords> simplex_vars;
    simplex_vars.push_back({0, 0});

    get_first_coords(simplex_vars);

    bool exit_var = false;
    size_t iteration_counter = 0;

    while(!exit_var) {
        if(iteration_counter >= iteration_max) {
            cout << "Could't get result for " << iteration_max << "iterations" << endl;
            return 1;
        }
        cout << endl <<  "Iteration: " << iteration_counter << endl;

        cout << "Simplex vertex's coords:" << endl;
        print_simple_vertex(simplex_vars);
        cout << "Coords funcs:" << endl;
        print_coords_funcs(simplex_vars);

        size_t max_var = find_max(simplex_vars);

        Coords cg_var = compute_cg(simplex_vars, max_var);
        cout << "C.G. except max vertex: " << cg_var << endl;

        Coords reflected_vertex = reflect_vertex(cg_var, simplex_vars[max_var]);
        cout << "Reflected vertex: " << reflected_vertex << endl;
        cout << "Reflected vertex func: " <<  compute_func(reflected_vertex) << endl;

        cout << compute_func(reflected_vertex) << " < " << compute_func(simplex_vars[max_var]) << " ";
        if (check_condition(simplex_vars[max_var], reflected_vertex)) {
            cout << "success" << endl;
            simplex_vars[max_var] = reflected_vertex;
        }
        else {
            cout << "failed" << endl;
            cout << "Running reduction..." << endl;
            reduction(simplex_vars);
            cout << "New simplex vertex's:" << endl;
            print_simple_vertex(simplex_vars);
        }

        Coords simplex_cg = compute_simplex_cg(simplex_vars);
        cout << "Simplex C.G. coords: " << simplex_cg << endl;
        cout << "Simplex C.G. function value: " << compute_func(simplex_cg) << endl;

        exit_var = check_for_end(simplex_vars, simplex_cg);

        iteration_counter++;
    }

    cout << endl << "Answer: " << endl;
    cout << "\tVertex coords: " << simplex_vars[find_min(simplex_vars)] << endl;
    cout << "\tFunction value: " <<  compute_func(simplex_vars[find_min(simplex_vars)]) << endl;

}