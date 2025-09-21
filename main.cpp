#include <array>
#include <fstream>
#include <iostream>

using namespace std;

constexpr size_t DAYS = 30;
using Arr = array<int, DAYS>;

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

    cout << "Loaded " << steps.size() << "days. First=" << steps.front() << " Last=" << steps.back() << "\n";

}

