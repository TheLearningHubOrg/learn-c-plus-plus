#pragma once

#include <string>
#include <vector>
#include <string_view>
#include <span>

namespace learning {

struct RoadmapStage {
    int stageNumber;
    std::string title;
    std::string domainFocus;
    bool completed;
};

class Curriculum {
public:
    static std::span<const RoadmapStage> getStages();
    static size_t getCompletedCount();
    static int getProgressPercentage();
};

} // namespace learning
