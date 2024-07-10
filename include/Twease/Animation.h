#pragma once


template <typename T>
class Animation {
public:
    Animation(const T& from, const T& to, double duration, std::function<double(double)> easingFunc)
        : m_From(from), m_To(to), m_Duration(duration), m_EasingFunc(easingFunc), m_CurrentTime(0.0), m_Completed(false) {}

    Animation& during(double duration) {
        m_Duration = duration;
        return *this;
    }

    Animation& to(const T& target) {
        m_To = target;
        return *this;
    }

    Animation& easing(std::function<double(double)> easingFunc) {
        m_EasingFunc = easingFunc;
        return *this;
    }

    void update(double deltaTime) {
        if (m_Completed) return;

        m_CurrentTime += deltaTime;
        if (m_CurrentTime >= m_Duration) {
            m_CurrentValue = m_To;
            m_Completed = true;
        }
        else {
            double t = m_CurrentTime / m_Duration;
            m_CurrentValue = Ease::lerp(m_From, m_To, m_EasingFunc(t));
        }
    }

    T getCurrentValue() const {
        return m_CurrentValue;
    }

    bool isCompleted() const {
        return m_Completed;
    }

    static Animation<T> animate(const T& from, const T& to) {
        return Animation<T>(from, to, 1.0, Ease::quadIn); // Default duration and easing function
    }

private:
    T m_From;
    T m_To;
    double m_Duration;
    std::function<double(double)> m_EasingFunc;
    double m_CurrentTime;
    T m_CurrentValue;
    bool m_Completed;
};