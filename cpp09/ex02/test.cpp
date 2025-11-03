#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <climits>
#include <chrono>

// Utility: trim whitespace
std::string trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t");
    if (start == std::string::npos) return "";
    size_t end = str.find_last_not_of(" \t");
    return str.substr(start, end - start + 1);
}

// Validate if string is a valid non-negative integer (with optional +)
bool isValidNumber(const std::string& s) {
    if (s.empty()) return false;
    size_t start = 0;
    if (s[0] == '+') start = 1;
    if (start == s.size()) return false;
    for (size_t i = start; i < s.size(); ++i) {
        if (!std::isdigit(s[i])) return false;
    }
    // Check range
    try {
        size_t pos;
        long long num = std::stoll(s, &pos);
        if (pos != s.size()) return false;
        if (num < 0 || num > INT_MAX) return false;
    } catch (...) {
        return false;
    }
    return true;
}

// Generate Jacobsthal number J(n)
int jacobsthal(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; ++i) {
        c = b + 2 * a;
        a = b;
        b = c;
    }
    return c;
}

// Generate insertion order using Jacobsthal numbers
std::vector<int> generateJacobsthalOrder(int pendingSize) {
    if (pendingSize == 0) return {};

    std::vector<int> jacobNumbers;
    // Collect J(3), J(4), ... <= pendingSize
    for (int i = 3; ; ++i) {
        int j = jacobsthal(i);
        if (j > pendingSize) break;
        jacobNumbers.push_back(j);
    }

    std::vector<bool> used(pendingSize + 1, false); // 1-indexed
    std::vector<int> order;

    // Step 1: From each Jacob number, go downward and add unused indices
    for (int j : jacobNumbers) {
        for (int k = j; k >= 1; --k) {
            if (k <= pendingSize && !used[k]) {
                order.push_back(k);
                used[k] = true;
            }
        }
    }

    // Step 2: Fill any remaining indices from pendingSize down to 1
    for (int k = pendingSize; k >= 1; --k) {
        if (!used[k]) {
            order.push_back(k);
            used[k] = true;
        }
    }

    return order;
}

// Binary search to find insertion position (returns index)
int binarySearchInsert(const std::vector<int>& arr, int value, int high) {
    int low = 0;
    if (high >= static_cast<int>(arr.size())) high = arr.size() - 1;
    if (high < 0) high = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= value) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low; // insertion point
}

// Ford-Johnson Sort with step printing
std::vector<int> fordJohnsonSort(std::vector<int> input, int depth = 0) {
    std::string indent(depth * 2, ' ');

    if (input.size() <= 1) {
        std::cout << indent << "Base case: " << (input.empty() ? "[]" : "[" + std::to_string(input[0]) + "]") << "\n";
        return input;
    }

    if (input.size() == 2) {
        std::cout << indent << "Sorting pair: [" << input[0] << ", " << input[1] << "]\n";
        if (input[0] > input[1]) std::swap(input[0], input[1]);
        std::cout << indent << "Result: [" << input[0] << ", " << input[1] << "]\n";
        return input;
    }

    // === STEP 1: Pairing ===
    std::vector<std::pair<int, int>> pairs;
    std::vector<int> main, pend;
    int oddElement = -1;
    bool hasOdd = (input.size() % 2 == 1);

    std::cout << indent << "Input: [";
    for (size_t i = 0; i < input.size(); ++i) {
        if (i > 0) std::cout << ", ";
        std::cout << input[i];
    }
    std::cout << "]\n";

    for (size_t i = 0; i + 1 < input.size(); i += 2) {
        int a = input[i], b = input[i+1];
        if (a < b) {
            pairs.emplace_back(a, b);
        } else {
            pairs.emplace_back(b, a);
        }
        pend.push_back(pairs.back().first);
        main.push_back(pairs.back().second);
    }

    if (hasOdd) {
        oddElement = input.back();
        pend.push_back(oddElement);
        std::cout << indent << "Odd element: " << oddElement << "\n";
    }

    std::cout << indent << "Pairs formed: ";
    for (const auto& p : pairs) {
        std::cout << "(" << p.first << "," << p.second << ") ";
    }
    std::cout << "\n";
    std::cout << indent << "Main (larger): [";
    for (size_t i = 0; i < main.size(); ++i) {
        if (i > 0) std::cout << ", ";
        std::cout << main[i];
    }
    std::cout << "]\n";
    std::cout << indent << "Pend (smaller): [";
    for (size_t i = 0; i < pend.size(); ++i) {
        if (i > 0) std::cout << ", ";
        std::cout << pend[i];
    }
    std::cout << "]\n";

    // === STEP 2: Recursively sort Main ===
    std::cout << indent << "Recursively sorting Main...\n";
    std::vector<int> sortedMain = fordJohnsonSort(main, depth + 1);

    // Reorder Pend to match sortedMain
    std::vector<int> sortedPend(sortedMain.size());
    for (size_t i = 0; i < sortedMain.size(); ++i) {
        for (size_t j = 0; j < main.size(); ++j) {
            if (main[j] == sortedMain[i]) {
                sortedPend[i] = pend[j];
                break;
            }
        }
    }
    if (hasOdd) {
        sortedPend.push_back(oddElement);
    }

    std::cout << indent << "After recursion:\n";
    std::cout << indent << "  Sorted Main: [";
    for (size_t i = 0; i < sortedMain.size(); ++i) {
        if (i > 0) std::cout << ", ";
        std::cout << sortedMain[i];
    }
    std::cout << "]\n";
    std::cout << indent << "  Aligned Pend: [";
    for (size_t i = 0; i < sortedPend.size(); ++i) {
        if (i > 0) std::cout << ", ";
        std::cout << sortedPend[i];
    }
    std::cout << "]\n";

    // === STEP 3: Generate Jacobsthal insertion order ===
    int pendingSize = sortedPend.size();
    std::vector<int> jacobOrder = generateJacobsthalOrder(pendingSize);

    std::cout << indent << "Jacobsthal insertion order (1-indexed pend indices): [";
    for (size_t i = 0; i < jacobOrder.size(); ++i) {
        if (i > 0) std::cout << ", ";
        std::cout << jacobOrder[i];
    }
    std::cout << "]\n";

    // === STEP 4: Insert pend elements in Jacob order ===
    std::vector<int> result = sortedMain;

    for (int idx : jacobOrder) {
        // idx is 1-based
        int value = sortedPend[idx - 1];
        // Determine search range: start with full, but we'll improve in real impl
        int pos = binarySearchInsert(result, value, result.size() - 1);
        result.insert(result.begin() + pos, value);
        std::cout << indent << "Inserted pend[" << (idx - 1) << "] = " << value
                  << " at position " << pos << " → Result: [";
        for (size_t i = 0; i < result.size(); ++i) {
            if (i > 0) std::cout << ", ";
            std::cout << result[i];
        }
        std::cout << "]\n";
    }

    return result;
}

// Parse command-line arguments
std::vector<int> parseInput(int argc, char* argv[]) {
    std::vector<int> nums;
    for (int i = 1; i < argc; ++i) {
        std::string arg = trim(argv[i]);
        if (!isValidNumber(arg)) {
            std::cerr << "Error: Invalid number '" << argv[i] << "'\n";
            exit(1);
        }
        nums.push_back(std::stoi(arg));
    }
    return nums;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <num1> <num2> ... <numN>\n";
        return 1;
    }

    std::vector<int> input = parseInput(argc, argv);

    std::cout << "=== Ford-Johnson (Merge-Insertion) Sort Demo ===\n";
    std::cout << "Original input: [";
    for (size_t i = 0; i < input.size(); ++i) {
        if (i > 0) std::cout << ", ";
        std::cout << input[i];
    }
    std::cout << "]\n\n";

    auto start = std::chrono::high_resolution_clock::now();
    std::vector<int> sorted = fordJohnsonSort(input);
    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "\n✅ Final sorted array: [";
    for (size_t i = 0; i < sorted.size(); ++i) {
        if (i > 0) std::cout << ", ";
        std::cout << sorted[i];
    }
    std::cout << "]\n";
    std::cout << "⏱️  Time taken: " << duration.count() << " microseconds\n";

    return 0;
}
