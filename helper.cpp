#include <iostream>
#include <vector>
#include <chrono>

using namespace std;


static int case_idx = 0;


template<typename T>
void customPrint(const T& result) {
    cout << result;
}


template<>
void customPrint<bool>(const bool& b) {
    cout << boolalpha << b << noboolalpha;
}


template<typename T>
void customPrint(const vector<T>& v) {
    if (v.size() == 0) {
        cout << "[]";
        return;
    }

    cout << "[";

    for (int i = 0; i < v.size() - 1; i++) {
        customPrint(v[i]);
        cout << ", ";
    }
    if (!v.empty()) customPrint(v[v.size() - 1]);
    
    cout << "]";
}


void printComma(int idx, int size) {
    if (idx < size) cout << ", ";
}


template<typename Func, typename... Args>
double getFunctionRuntime(Func func, Args&&... args) {
    // Measure time
    chrono::high_resolution_clock::time_point begin { chrono::high_resolution_clock::now() };

    func(forward<Args>(args)...);
    
    chrono::high_resolution_clock::time_point end { chrono::high_resolution_clock::now() };

    return chrono::duration_cast<chrono::microseconds>(end - begin).count();
}


void resetCases() {
    case_idx = 0;
}


template<typename Func, typename... Args>
void outputFunctionStats(Func func, Args&&... args) {
    cout << "Case #" << case_idx << '\n';
    cout << "Input: ";

    // Lambda loop for packed args
    int numArgs = sizeof...(Args) - 1;
    int i{};
    ([numArgs, &i](const auto& x) {
        customPrint(x);
        if(i++ < numArgs) cout << ", ";
    } (args), ...);
    cout << '\n';

    cout << "Result: ";
    customPrint(func(forward<Args>(args)...));
    cout << '\n';

    double runtime { getFunctionRuntime(func, forward<Args>(args)...) };
    cout << "Runtime: " << runtime << "µs\n" << endl;

    case_idx++;
}