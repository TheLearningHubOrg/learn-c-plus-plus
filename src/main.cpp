#include <iostream>
#include <iomanip>
#include "roadmap.hpp"
#include "thread_pool.hpp"

int main() {
    std::cout << std::string(70, '=') << "\n";
    std::cout << "  Learn C++ (C++20 / C++23) Modern Systems Architecture Masterclass\n";
    std::cout << std::string(70, '=') << "\n\n";

    std::cout << "[Modern ThreadPool] Initializing 4 worker threads with std::future queues...\n";
    learning::ThreadPool pool(4);

    auto futureTask = pool.enqueue([]() {
        return "Async computation finished on worker thread.";
    });

    std::cout << "\n[Curriculum Progression] 7-Stage Modern C++ Roadmap:\n";
    auto stages = learning::Curriculum::getStages();

    for (const auto& stage : stages) {
        std::string symbol = stage.completed ? "[x]" : "[ ]";
        std::cout << "  " << symbol << " Stage " << stage.stageNumber << ": " << stage.title << "\n";
        std::cout << "      Focus: " << stage.domainFocus << "\n";
    }

    int progress = learning::Curriculum::getProgressPercentage();
    std::cout << "\n[Progress Metric] Mastered " << learning::Curriculum::getCompletedCount() 
              << " of " << stages.size() << " stages (" << progress << "%)\n";

    std::cout << "[ThreadPool Result] " << futureTask.get() << "\n";

    return 0;
}
