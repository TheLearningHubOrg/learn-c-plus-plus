#include "roadmap.hpp"
#include <numeric>

namespace learning {

static const std::vector<RoadmapStage> STAGES = {
    {1, "Memory Model, Move Semantics & Value Categories", "rvalue references, std::move, std::forward, copy elision (NRVO)", true},
    {2, "Smart Pointers & RAII Resource Management", "std::unique_ptr, std::shared_ptr, std::weak_ptr, custom deleters", true},
    {3, "Modern Metaprogramming & C++20 Concepts", "requires clauses, type traits, SFINAE replacement, constexpr / consteval", true},
    {4, "Multithreading & Concurrency Primitives", "std::jthread, std::latch, std::barrier, std::atomic, memory orders", false},
    {5, "Ranges Library & Functional Composition", "std::views, pipe syntax |, lazy evaluation, projection iterators", false},
    {6, "Coroutines & Asynchronous Generators", "co_await, co_yield, co_return, promise_type, task schedulers", false},
    {7, "Staff C++ Architect Handbook & Systems Hardening", "Undefined Behavior Sanitizer (UBSan), cache-line ping-pong, lock-free queues", true}
};

std::span<const RoadmapStage> Curriculum::getStages() {
    return STAGES;
}

size_t Curriculum::getCompletedCount() {
    return std::count_if(STAGES.begin(), STAGES.end(), [](const RoadmapStage& s) {
        return s.completed;
    });
}

int Curriculum::getProgressPercentage() {
    return static_cast<int>((getCompletedCount() * 100) / STAGES.size());
}

} // namespace learning
