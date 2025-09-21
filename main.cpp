#include <array>
#include <algorithm>
#include <numeric> 
#include <fstream>
#include <iostream>

using namespace std;

constexpr size_t DAYS = 30;
using Arr = array<int, DAYS>;


int sum_c(int* a, size_t n) {
    int s = 0;
    for (size_t i = 0; i < n; ++i) s += a[i];
    return s;
}


int main(){
    Arr steps{};
    ifstream fin("steps.txt");
    if (!fin) { 
        cerr << "Can't open steps.txt\n"; 
        return 1; 
    }

    for (size_t i = 0; i < steps.size(); ++i) {
        if (!(fin >> steps[i])) { cerr << "Not enough numbers\n"; return 1; }
    }

    cout << "Size = " << steps.size() << " days. First=" << steps.front() << " Last=" << steps.back() << "\n";

    try {
        cout << "Day 10 (at) = " << steps.at(9) << "\n";
    } catch(out_of_range& e){
        cout << "Out of range: " << e.what() << "\n";
    }

    cout << "Empty? " << (steps.empty() ? "true" : "false") << "\n";

    int *raw = steps.data();
    cout << "data() pointer: " << raw << "\n"; //for the location

    cout << "Max: " << *max_element(steps.begin(), steps.end()) << endl;
    cout << "Min: " << *min_element(steps.begin(), steps.end()) << endl;
    cout << "Sum: " << accumulate(steps.begin(), steps.end(), 0) << endl;

}

