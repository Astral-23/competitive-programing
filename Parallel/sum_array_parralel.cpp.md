---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Parallel/sum_array_parralel.cpp\"\n#include <assert.h>\n\
    #include <algorithm>\n#include <chrono>\n#include <iostream>\n#include <iterator>\n\
    #include <numeric>\n#include <thread>\n#include <vector>\n\ntemplate <std::random_access_iterator\
    \ IterType>\ntypename std::iterator_traits<IterType>::value_type calculate_sum_parallel(\n\
    \    const IterType &it_begin,\n    const IterType &it_end,\n    const size_t\
    \ threadNum) {\n    using ValueType = std::iterator_traits<IterType>::value_type;\n\
    \n    const size_t N = std::distance(it_begin, it_end);\n    assert(N != 0);\n\
    \    const auto blockNum = (N + threadNum - 1) / threadNum;\n    std::vector<ValueType>\
    \ results(threadNum, 0);\n    std::vector<std::thread> threads(threadNum);\n \
    \   for (size_t i = 0; i < threadNum; ++i) {\n        auto itl = it_begin + std::min(N,\
    \ blockNum * i);\n        auto itr = it_begin + std::min(N, blockNum * (i + 1));\n\
    \        threads[i] = std::thread(\n            [itl, itr, &results, i]() { results[i]\
    \ = std::reduce(itl, itr); });\n    }\n\n    for (auto &th : threads) {\n    \
    \    th.join();\n    }\n    return std::reduce(results.begin(), results.end());\n\
    }\n\nint main() {\n    constexpr size_t N = 1'00'000'000;\n    std::vector<unsigned\
    \ int> A(N);\n    for (auto &x : A) {\n        x = std::rand();\n    }\n\n   \
    \ // \u2193\u2193\u2193 \u30A6\u30A9\u30FC\u30E0\u30A2\u30C3\u30D7\u90E8\u5206\
    \ \u2193\u2193\u2193\n    std::cout << \"--- Warming up ---\" << std::endl;\n\
    \    // \u6700\u5927\u30B9\u30EC\u30C3\u30C9\u6570\u3067\u4E00\u5EA6\u5B9F\u884C\
    \u3059\u308B\uFF08\u6642\u9593\u306F\u8A08\u6E2C\u3057\u306A\u3044\uFF09\n   \
    \ auto ret_warmup = calculate_sum_parallel(A.begin(), A.end(), 20);\n    // \u7D50\
    \u679C\u304C\u4F7F\u308F\u308C\u306A\u3044\u3053\u3068\u306B\u3088\u308B\u6700\
    \u9069\u5316\u3092\u9632\u3050\u305F\u3081\u3001\u7D50\u679C\u3092void\u30AD\u30E3\
    \u30B9\u30C8\u3057\u3066\u610F\u56F3\u3092\u793A\u3059\n    (void)ret_warmup;\n\
    \    std::cout << \"Warm up complete.\" << std::endl << std::endl;\n    // \u2191\
    \u2191\u2191 \u30A6\u30A9\u30FC\u30E0\u30A2\u30C3\u30D7\u90E8\u5206 \u2191\u2191\
    \u2191\n\n    printf(\"vectorSize: %zuBB\\n\", N);\n\n    // \u2193\u2193\u2193\
    \ \u8FFD\u52A0\u90E8\u5206 \u2193\u2193\u2193\n    std::cout << \"--- Baseline\
    \ (Sequential std::reduce) ---\" << std::endl;\n    const auto st_seq = std::chrono::high_resolution_clock::now();\n\
    \    const auto ret_seq = std::reduce(A.begin(), A.end());\n    const auto tt_seq\
    \ = std::chrono::high_resolution_clock::now();\n    const std::chrono::duration<double>\
    \ diff_seq = tt_seq - st_seq;\n    printf(\"Sequential ret: %u time: %f sec\\\
    n\", ret_seq, diff_seq.count());\n    std::cout << \"-----------------------------------------\"\
    \ << std::endl\n              << std::endl;\n    // \u2191\u2191\u2191 \u8FFD\u52A0\
    \u90E8\u5206 \u2191\u2191\u2191\n\n    for (int threadNum = 1; threadNum <= std::thread::hardware_concurrency();\n\
    \         ++threadNum) {\n        const auto st = std::chrono::high_resolution_clock::now();\n\
    \        const auto ret = calculate_sum_parallel(A.begin(), A.end(), threadNum);\n\
    \        const auto tt = std::chrono::high_resolution_clock::now();\n        const\
    \ std::chrono::duration<double> diff = tt - st;\n        printf(\"threadNum: %u\
    \ ret: %d time: %f sec\\n\", threadNum, ret,\n               diff.count());\n\
    \    }\n}\n"
  code: "#include <assert.h>\n#include <algorithm>\n#include <chrono>\n#include <iostream>\n\
    #include <iterator>\n#include <numeric>\n#include <thread>\n#include <vector>\n\
    \ntemplate <std::random_access_iterator IterType>\ntypename std::iterator_traits<IterType>::value_type\
    \ calculate_sum_parallel(\n    const IterType &it_begin,\n    const IterType &it_end,\n\
    \    const size_t threadNum) {\n    using ValueType = std::iterator_traits<IterType>::value_type;\n\
    \n    const size_t N = std::distance(it_begin, it_end);\n    assert(N != 0);\n\
    \    const auto blockNum = (N + threadNum - 1) / threadNum;\n    std::vector<ValueType>\
    \ results(threadNum, 0);\n    std::vector<std::thread> threads(threadNum);\n \
    \   for (size_t i = 0; i < threadNum; ++i) {\n        auto itl = it_begin + std::min(N,\
    \ blockNum * i);\n        auto itr = it_begin + std::min(N, blockNum * (i + 1));\n\
    \        threads[i] = std::thread(\n            [itl, itr, &results, i]() { results[i]\
    \ = std::reduce(itl, itr); });\n    }\n\n    for (auto &th : threads) {\n    \
    \    th.join();\n    }\n    return std::reduce(results.begin(), results.end());\n\
    }\n\nint main() {\n    constexpr size_t N = 1'00'000'000;\n    std::vector<unsigned\
    \ int> A(N);\n    for (auto &x : A) {\n        x = std::rand();\n    }\n\n   \
    \ // \u2193\u2193\u2193 \u30A6\u30A9\u30FC\u30E0\u30A2\u30C3\u30D7\u90E8\u5206\
    \ \u2193\u2193\u2193\n    std::cout << \"--- Warming up ---\" << std::endl;\n\
    \    // \u6700\u5927\u30B9\u30EC\u30C3\u30C9\u6570\u3067\u4E00\u5EA6\u5B9F\u884C\
    \u3059\u308B\uFF08\u6642\u9593\u306F\u8A08\u6E2C\u3057\u306A\u3044\uFF09\n   \
    \ auto ret_warmup = calculate_sum_parallel(A.begin(), A.end(), 20);\n    // \u7D50\
    \u679C\u304C\u4F7F\u308F\u308C\u306A\u3044\u3053\u3068\u306B\u3088\u308B\u6700\
    \u9069\u5316\u3092\u9632\u3050\u305F\u3081\u3001\u7D50\u679C\u3092void\u30AD\u30E3\
    \u30B9\u30C8\u3057\u3066\u610F\u56F3\u3092\u793A\u3059\n    (void)ret_warmup;\n\
    \    std::cout << \"Warm up complete.\" << std::endl << std::endl;\n    // \u2191\
    \u2191\u2191 \u30A6\u30A9\u30FC\u30E0\u30A2\u30C3\u30D7\u90E8\u5206 \u2191\u2191\
    \u2191\n\n    printf(\"vectorSize: %zuBB\\n\", N);\n\n    // \u2193\u2193\u2193\
    \ \u8FFD\u52A0\u90E8\u5206 \u2193\u2193\u2193\n    std::cout << \"--- Baseline\
    \ (Sequential std::reduce) ---\" << std::endl;\n    const auto st_seq = std::chrono::high_resolution_clock::now();\n\
    \    const auto ret_seq = std::reduce(A.begin(), A.end());\n    const auto tt_seq\
    \ = std::chrono::high_resolution_clock::now();\n    const std::chrono::duration<double>\
    \ diff_seq = tt_seq - st_seq;\n    printf(\"Sequential ret: %u time: %f sec\\\
    n\", ret_seq, diff_seq.count());\n    std::cout << \"-----------------------------------------\"\
    \ << std::endl\n              << std::endl;\n    // \u2191\u2191\u2191 \u8FFD\u52A0\
    \u90E8\u5206 \u2191\u2191\u2191\n\n    for (int threadNum = 1; threadNum <= std::thread::hardware_concurrency();\n\
    \         ++threadNum) {\n        const auto st = std::chrono::high_resolution_clock::now();\n\
    \        const auto ret = calculate_sum_parallel(A.begin(), A.end(), threadNum);\n\
    \        const auto tt = std::chrono::high_resolution_clock::now();\n        const\
    \ std::chrono::duration<double> diff = tt - st;\n        printf(\"threadNum: %u\
    \ ret: %d time: %f sec\\n\", threadNum, ret,\n               diff.count());\n\
    \    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: Parallel/sum_array_parralel.cpp
  requiredBy: []
  timestamp: '2025-06-12 00:58:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Parallel/sum_array_parralel.cpp
layout: document
redirect_from:
- /library/Parallel/sum_array_parralel.cpp
- /library/Parallel/sum_array_parralel.cpp.html
title: Parallel/sum_array_parralel.cpp
---
