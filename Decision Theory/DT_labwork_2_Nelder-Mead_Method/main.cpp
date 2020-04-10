#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const double epsylon = 0.1; // точность
const double m = 1; // длина ребра
const size_t n = 2; // размерность
const size_t iteration_max = 20;
const double beta = 2.8; // растяжение
const double gamma = 0.4; // сжатие
size_t vars_counter = 0;


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

    friend ostream& operator<<(ostream &out,  Coords const& other) {
        string temp = "";
        out << "(";
        for (auto it : other.x) {
            out << temp << it;
            temp = ", ";
        }
        out << ")";
        return out;
    }
};



double compute_func(Coords x) {
    return x.x[0]*x.x[0] - x.x[0]*x.x[1] + 3*x.x[1]*x.x[1] - x.x[0];
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
        tmp.index = vars_counter++;
        x_vars.push_back(tmp);
    }
}

vector<double> compute_func_values(vector<Coords> const& x_vars) {
    vector<double> result;
    for (int i = 0; i < x_vars.size(); ++i) {
        result.push_back(compute_func(x_vars[i]));
    }
    return result;
}

size_t find_max(vector<double> const& func_values) {
    auto result = max_element(func_values.begin(), func_values.end());
    auto int_result = distance(func_values.begin(), result);
    return int_result;
}

size_t find_second_max(vector<double> const& func_values) {
    vector<double> tmp = func_values;
    auto result = max_element(tmp.begin(), tmp.end());
    tmp.erase(result);
    result = max_element(tmp.begin(), tmp.end());
    auto second_max = find(func_values.begin(), func_values.end(), *result);
    size_t int_result = distance(func_values.begin(), second_max);
    return int_result;
}

size_t find_min(vector<double> const& func_values) {
    auto result = min_element(func_values.begin(), func_values.end());
    auto int_result = distance(func_values.begin(), result);
    return int_result;
}

Coords compute_cg(vector<Coords> const& simplex_vars, size_t const& max_var) {
    Coords result = simplex_vars[0];
    for (int i = 1; i < simplex_vars.size(); ++i) {
        if(i != max_var)
            result = result + simplex_vars[i];
    }
    return result/n;
}

Coords reflect_vertex(Coords cg_vertex, Coords const& vertex) {
    return (cg_vertex * 2) - vertex;
}

Coords compression(Coords cg_vertex, Coords vertex) {
    return cg_vertex + (vertex - cg_vertex) * gamma;
}

Coords stretching(Coords cg_vertex, Coords vertex) {
    return cg_vertex + (vertex - cg_vertex) * beta;
}

void reduction(vector<Coords>& simplex_vertex) {
    size_t number = find_min(compute_func_values(simplex_vertex));
    for (int i = 0; i < simplex_vertex.size(); ++i)
        if (i != number)
            simplex_vertex[i] = simplex_vertex[number] + (simplex_vertex[i] - simplex_vertex[number])/2;
}


void print_simplex_vertex(vector<Coords> const& simplex_vertex) {
    for (int i = 0; i < simplex_vertex.size(); ++i) {
        cout << "\tVertex " << simplex_vertex[i].index << ": " << simplex_vertex[i] << endl;
    }
}

void print_coords_funcs(vector<Coords> const& simplex_vertex, vector<double> const& func_values) {
    for (int i = 0; i < func_values.size(); ++i)
        cout << "\tF(" << simplex_vertex[i].index << ") = " << func_values[i] << endl;
}

bool comparing_vertex(vector<Coords> &simplex_vertex, vector<double> &func_values, size_t &current_vertex,
                      Coords &new_vertex) {
    double new_vertex_func = compute_func(new_vertex);
    cout << new_vertex_func << " < " << func_values[current_vertex];
    if (new_vertex_func < func_values[current_vertex]) {
        cout << " success" << endl;
        simplex_vertex[current_vertex] = new_vertex;
        func_values[current_vertex] = new_vertex_func;
        return true;
    }
    else {
        cout << " fail" << endl;
        return false;
    }
}

void vertex_morphing(vector<Coords>& simplex_vertex, vector<double>& func_values, size_t& current_vertex, Coords& cg_vertex,
                     Coords& reflected_vertex, double& max_vertex, double& second_max_vertex, double& min_vertex) {

    if(comparing_vertex(simplex_vertex, func_values, current_vertex, reflected_vertex)) {
        cout << "Checking for stretching:" << endl;
        cout << "\t" << func_values[current_vertex] << " < " << min_vertex;
        if (func_values[current_vertex] < min_vertex) {
            cout << " success" << endl;
            cout << "Running stretching..." << endl;
            Coords stretched_vertex = stretching(cg_vertex, simplex_vertex[current_vertex]);
            stretched_vertex.index = vars_counter++;
            if(comparing_vertex(simplex_vertex, func_values, current_vertex, stretched_vertex))
                return;
        }
        cout << " fail" << endl;
    }

    cout << "Checking for compression:" << endl;
    cout << "\t" << second_max_vertex << " < " <<  func_values[current_vertex] << " < " << max_vertex;
    if (second_max_vertex < func_values[current_vertex] && func_values[current_vertex] < max_vertex) {
        cout << " success" << endl;
        cout << "Running compression..." << endl;
        Coords compressed_vertex = compression(cg_vertex, simplex_vertex[current_vertex]);
        compressed_vertex.index = vars_counter++;
        if(comparing_vertex(simplex_vertex, func_values, current_vertex, compressed_vertex))
            return;
    }

    cout << " fail" << endl;
    cout << "Running reduction..." << endl;
    reduction(simplex_vertex);
}

Coords compute_simplex_cg(vector<Coords> const& simplex_vars) {
    Coords result = simplex_vars[0];
    for (int i = 1; i < simplex_vars.size(); ++i) {
        result = result + simplex_vars[i];
    }
    return result/(n+1);
}


bool check_for_end(vector<double> func_values, double simplex_cg_func) {
    double sigma = 0;
    cout << endl << "Start checking end condition..." << endl;
    for (int i = 0; i <= n; ++i)
        sigma += pow((func_values[i] - simplex_cg_func), 2);
    sigma /= n+1;
    sigma = sqrt(sigma);

    cout << "\t" << sigma << " < " << epsylon;
    if (sigma < epsylon) {
        cout << " success" << endl;
        return true;
    }
    else {
        cout << " fail" << endl << "Running next iteration..." << endl;
        return false;
    }
}

int main() {
    vector<Coords> simplex_vertex;

    simplex_vertex.push_back({0, 0});
    simplex_vertex[0].index = vars_counter++;

    get_first_coords(simplex_vertex);

    auto func_values = compute_func_values(simplex_vertex);

    bool exit_var = false;
    size_t iteration_counter = 0;

    while(!exit_var) {
        if(iteration_counter >= iteration_max) {
            cout << "Could't get result for " << iteration_max << "iterations" << endl;
            return 1;
        }
        cout << endl <<  "Iteration: " << iteration_counter << endl;

        cout << "Simplex vertex's coords:" << endl;
        print_simplex_vertex(simplex_vertex);
        cout << "Coords funcs:" << endl;
        print_coords_funcs(simplex_vertex, func_values);

        size_t current_vertex = find_max(func_values);
        cout << "Vertex with max function value: F(" << current_vertex << ") = " << func_values[current_vertex] << endl;

        double max_vertex = func_values[find_max(func_values)];
        double second_max_vertex = func_values[find_second_max(func_values)];
        double min_vertex = func_values[find_min(func_values)];

        cout << "Max function value = " << max_vertex << endl;
        cout << "Second Max function value = " << second_max_vertex << endl;
        cout << "Min function value = " << min_vertex << endl;

        Coords cg_vertex = compute_cg(simplex_vertex, current_vertex);
        cout << "C.G. except max vertex: " << cg_vertex << endl;

        Coords reflected_vertex = reflect_vertex(cg_vertex, simplex_vertex[current_vertex]);
        reflected_vertex.index = vars_counter++;
        cout << "Reflected vertex[" << reflected_vertex.index << "]: " << reflected_vertex << endl;
        cout << "Reflected vertex[" << reflected_vertex.index << "] function value: " <<  compute_func(reflected_vertex) << endl;

        vertex_morphing(simplex_vertex, func_values, current_vertex, cg_vertex, reflected_vertex, max_vertex, second_max_vertex, min_vertex);

        Coords simplex_cg = compute_simplex_cg(simplex_vertex);
        cout << "Simplex C.G. coords: " << simplex_cg << endl;
        cout << "Simplex C.G. function value: " << compute_func(simplex_cg) << endl;

        exit_var = check_for_end(func_values, compute_func(simplex_cg));

        iteration_counter++;
    }

    cout << endl << "Answer: " << endl;
    size_t answer_vertex = find_min(func_values);
    cout << "\tVertex coords: " << simplex_vertex[answer_vertex] << endl;
    cout << "\tFunction value: " <<  func_values[answer_vertex] << endl;
}