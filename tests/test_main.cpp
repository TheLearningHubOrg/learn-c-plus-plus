#include <iostream>
#include <cassert>
#include "roadmap.hpp"
#include "thread_pool.hpp"

void testCurriculumStages() {
    auto stages = learning::Curriculum::getStages();
    assert(stages.size() == 7);
    assert(stages[0].stageNumber == 1);
    assert(stages[6].stageNumber == 7);

    size_t completed = learning::Curriculum::getCompletedCount();
    assert(completed >= 2);

    int percent = learning::Curriculum::getProgressPercentage();
    assert(percent >= 0 && percent <= 100);

    std::cout << "PASS: testCurriculumStages\n";
}

void testThreadPoolConcurrency() {
    learning::ThreadPool pool(2);

    auto f1 = pool.enqueue([]() { return 10; });
    auto f2 = pool.enqueue([]() { return 20; });

    assert(f1.get() == 10);
    assert(f2.get() == 20);

    std::cout << "PASS: testThreadPoolConcurrency\n";
}

int main() {
    std::cout << "Running C++20 Unit Tests...\n";
    testCurriculumStages();
    testThreadPoolConcurrency();
    std::cout << "ALL C++20 TESTS PASSED SUCCESSFULLY!\n";
    return 0;
}
