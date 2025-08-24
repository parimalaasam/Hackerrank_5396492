#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> generated_primes;

void generatePrimes(int q) {
    generated_primes.clear();
    int num = 2;
    while (generated_primes.size() < static_cast<size_t>(q)) {
        bool is_prime = true;
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) {
            generated_primes.push_back(num);
        }
        ++num;
    }
}

void solveWaiter(int N, int Q, const vector<int>& numbers) {
    vector<int> stack;

    for (int i = 0; i < N; ++i) {
        if (numbers[i] % generated_primes[0] != 0) {
            stack.push_back(numbers[i]);
        } else {
            cout << numbers[i] << endl;
        }
    }

    for (int prime_idx = 1; prime_idx < Q; ++prime_idx) {
        vector<int> leftover;
        for (int i = stack.size() - 1; i >= 0; --i) {
            int value = stack[i];
            if (value % generated_primes[prime_idx] != 0) {
                leftover.push_back(value);
            } else {
                cout << value << endl;
            }
        }
        stack = leftover;
    }

    for (int i = 0; i < stack.size(); ++i) {
        cout << stack[i] << endl;
    }
}

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> numbers(N);
    for (int i = 0; i < N; ++i) {
        cin >> numbers[i];
    }

    generatePrimes(Q);
    solveWaiter(N, Q, numbers);

    return 0;
}
