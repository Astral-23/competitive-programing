#include <assert.h>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <iterator>
#include <numeric>
#include <thread>
#include <vector>

template <std::random_access_iterator IterType>
typename std::iterator_traits<IterType>::value_type calculate_sum_parallel(
    const IterType &it_begin,
    const IterType &it_end,
    const size_t threadNum) {
    using ValueType = std::iterator_traits<IterType>::value_type;

    const size_t N = std::distance(it_begin, it_end);
    assert(N != 0);
    const auto blockNum = (N + threadNum - 1) / threadNum;
    std::vector<ValueType> results(threadNum, 0);
    std::vector<std::thread> threads(threadNum);
    for (size_t i = 0; i < threadNum; ++i) {
        auto itl = it_begin + std::min(N, blockNum * i);
        auto itr = it_begin + std::min(N, blockNum * (i + 1));
        threads[i] = std::thread(
            [itl, itr, &results, i]() { results[i] = std::reduce(itl, itr); });
    }

    for (auto &th : threads) {
        th.join();
    }
    return std::reduce(results.begin(), results.end());
}

int main() {
    constexpr size_t N = 1'00'000'000;
    std::vector<unsigned int> A(N);
    for (auto &x : A) {
        x = std::rand();
    }

    // ↓↓↓ ウォームアップ部分 ↓↓↓
    std::cout << "--- Warming up ---" << std::endl;
    // 最大スレッド数で一度実行する（時間は計測しない）
    auto ret_warmup = calculate_sum_parallel(A.begin(), A.end(), 20);
    // 結果が使われないことによる最適化を防ぐため、結果をvoidキャストして意図を示す
    (void)ret_warmup;
    std::cout << "Warm up complete." << std::endl << std::endl;
    // ↑↑↑ ウォームアップ部分 ↑↑↑

    printf("vectorSize: %zuBB\n", N);

    // ↓↓↓ 追加部分 ↓↓↓
    std::cout << "--- Baseline (Sequential std::reduce) ---" << std::endl;
    const auto st_seq = std::chrono::high_resolution_clock::now();
    const auto ret_seq = std::reduce(A.begin(), A.end());
    const auto tt_seq = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double> diff_seq = tt_seq - st_seq;
    printf("Sequential ret: %u time: %f sec\n", ret_seq, diff_seq.count());
    std::cout << "-----------------------------------------" << std::endl
              << std::endl;
    // ↑↑↑ 追加部分 ↑↑↑

    for (int threadNum = 1; threadNum <= std::thread::hardware_concurrency();
         ++threadNum) {
        const auto st = std::chrono::high_resolution_clock::now();
        const auto ret = calculate_sum_parallel(A.begin(), A.end(), threadNum);
        const auto tt = std::chrono::high_resolution_clock::now();
        const std::chrono::duration<double> diff = tt - st;
        printf("threadNum: %u ret: %d time: %f sec\n", threadNum, ret,
               diff.count());
    }
}