#include "mini_bench.h"

#include <string>
#include <vector>
#include "BracketStats.h"

namespace {

std::string generate_valid_brackets(std::size_t n) {
    std::string s;
    s.append(n, '(');
    s.append(n, ')');
    return s;
}

std::string generate_unmatched_brackets(std::size_t n) {
    std::string s;
    s.append(n, '(');
    s.append(n / 2, ')');
    return s;
}

std::string generate_alternating_brackets(std::size_t n) {
    std::string s;
    for (std::size_t i = 0; i < n; ++i) {
        s.push_back((i % 2 == 0) ? '(' : ')');
    }
    return s;
}

}  // namespace

int main() {
    constexpr int trials = 3;

    // Prueba 1: Secuencias validas (n abiertos + n cerrados)
    {
        constexpr std::size_t n = 1500; // 1500 opens + 1500 closes = 3000 chars, para que nonopt termine en tiempo razonable
        const std::string input = generate_valid_brackets(n);

        const double avg_opt = PC2::bench::average_us(trials, [&] {
            volatile auto res = PC2::solveBracketsOptimized(input);
            (void)res;
        });

        const double avg_nonopt = PC2::bench::average_us(trials, [&] {
            volatile auto res = PC2::solveBracketsNonOptimized(input);
            (void)res;
        });

        PC2::bench::print_header("Benchmark: Secuencias validas (n opens + n closes)", 2*n, trials);
        PC2::bench::print_result("Optimizado O(n)", avg_opt);
        PC2::bench::print_result("No optimizado O(n^3)", avg_nonopt);
        std::cout << "Speedup: " << (avg_nonopt / avg_opt) << "x\n\n" << std::flush;
    }

    // Prueba 2: Parentesis sin emparejar
    {
        constexpr std::size_t n = 2000; // 2000 opens + 1000 closes = 3000 chars
        const std::string input = generate_unmatched_brackets(n);

        const double avg_opt = PC2::bench::average_us(trials, [&] {
            volatile auto res = PC2::solveBracketsOptimized(input);
            (void)res;
        });

        const double avg_nonopt = PC2::bench::average_us(trials, [&] {
            volatile auto res = PC2::solveBracketsNonOptimized(input);
            (void)res;
        });

        PC2::bench::print_header("Benchmark: Parentesis sin emparejar (n opens + n/2 closes)", 
                                  n + n/2, trials);
        PC2::bench::print_result("Optimizado O(n)", avg_opt);
        PC2::bench::print_result("No optimizado O(n^3)", avg_nonopt);
        std::cout << "Speedup: " << (avg_nonopt / avg_opt) << "x\n\n" << std::flush;
    }

    // Prueba 3: Alternancia ()()...
    {
        constexpr std::size_t n = 3000; // 1500 opens + 1500 closes = 3000 chars, para que nonopt termine en tiempo razonable
        const std::string input = generate_alternating_brackets(n);

        const double avg_opt = PC2::bench::average_us(trials, [&] {
            volatile auto res = PC2::solveBracketsOptimized(input);
            (void)res;
        });

        const double avg_nonopt = PC2::bench::average_us(trials, [&] {
            volatile auto res = PC2::solveBracketsNonOptimized(input);
            (void)res;
        });

        PC2::bench::print_header("Benchmark: Alternancia ()()... (n caracteres)", n, trials);
        PC2::bench::print_result("Optimizado O(n)", avg_opt);
        PC2::bench::print_result("No optimizado O(n^3)", avg_nonopt);
        std::cout << "Speedup: " << (avg_nonopt / avg_opt) << "x\n\n" << std::flush;
    }

    return 0;
}
