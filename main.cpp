#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void getEvenNumbers(long long userInput, vector<int> &ans) {
    int current = static_cast<int>(userInput % 10);
    auto residue = userInput / 10;

    if ((current % 2) == 0) ans.push_back(static_cast<int>(current));
    if (residue) getEvenNumbers(residue, ans);
}

int main() {
    long long testList[] = {
            9223372036854775806,
            10000000,
            3571,
            111111111111111111,
            1234567890,
    };

    for (auto item : testList) {
        vector<int> ans{};
        getEvenNumbers(item, ans);

        if (!ans.empty()) {
            cout << item << " contains even numbers:: ";
            for (int i: ans) cout << i << " ";
            cout << "\nTotal Found: " << ans.size() << endl;
        } else {
            cout << "In " << item << " no even numbers found" << endl;
        }
    }
}