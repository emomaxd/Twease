#pragma once

namespace Twease {

    template<typename T>
    class Tween {
    public:
        explicit Tween(const std::vector<T>& sequence) : sequence_(sequence) {}

        Tween<T>& to(const std::vector<T>& target) {
            targets_.push_back(target);
            return *this;
        }

        Tween<T>& during(int steps) {
            steps_ = steps;
            return *this;
        }

        std::vector<T> step(double t) const {
            if (targets_.empty()) {
                return sequence_;
            }

            double segmentDuration = 1.0 / targets_.size();
            int currentSegment = static_cast<int>(t / segmentDuration);

            currentSegment = std::min(static_cast<int>(targets_.size()) - 1, currentSegment);

            const std::vector<T>& from = (currentSegment == 0) ? sequence_ : targets_[currentSegment - 1];
            const std::vector<T>& to = targets_[currentSegment];

            std::vector<T> result;
            result.reserve(sequence_.size());
            for (size_t i = 0; i < sequence_.size(); ++i) {
                T interpolatedValue = tween(from[i], to[i], (t - currentSegment * segmentDuration) / segmentDuration);
                result.push_back(interpolatedValue);
            }

            return result;
        }

        int during() const {
            return steps_;
        }

    private:
        std::vector<T> sequence_;
        std::vector<std::vector<T>> targets_;
        int steps_ = 50;

    private:
        T tween(const T& from, const T& to, double progress) const {
            return from + static_cast<T>((to - from) * progress);
        }
    };

}