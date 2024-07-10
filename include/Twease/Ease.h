#pragma once

#include <cmath>
#include <functional>

// Define M_PI if not already defined
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

namespace Twease {

    // Linear interpolation function (lerping)
    template <typename T>
    T lerp(T a, T b, double t) {
        return a + t * (b - a);
    }

    // Linear easing (no easing, no acceleration)
    inline double linear(double t) {
        return t;
    }

    // Quadratic easing in - accelerating from zero velocity
    inline double quadIn(double t) {
        return t * t;
    }

    // Quadratic easing out - decelerating to zero velocity
    inline double quadOut(double t) {
        return t * (2.0 - t);
    }

    // Quadratic easing in/out - acceleration until halfway, then deceleration
    inline double quadInOut(double t) {
        if (t < 0.5) {
            return 2.0 * t * t;
        }
        return -1.0 + (4.0 - 2.0 * t) * t;
    }

    // Cubic easing in - accelerating from zero velocity
    inline double cubicIn(double t) {
        return t * t * t;
    }

    // Cubic easing out - decelerating to zero velocity
    inline double cubicOut(double t) {
        t -= 1.0;
        return t * t * t + 1.0;
    }

    // Cubic easing in/out - acceleration until halfway, then deceleration
    inline double cubicInOut(double t) {
        return t < 0.5 ? 4 * t * t * t : 1 - std::pow(-2 * t + 2, 3) / 2;
    }

    // Quartic easing in - accelerating from zero velocity
    inline double quartIn(double t) {
        return t * t * t * t;
    }

    // Quartic easing out - decelerating to zero velocity
    inline double quartOut(double t) {
        t -= 1.0;
        return 1.0 - t * t * t * t;
    }

    // Quartic easing in/out - acceleration until halfway, then deceleration
    inline double quartInOut(double t) {
        if (t < 0.5) {
            return 8.0 * t * t * t * t;
        }
        t -= 1.0;
        return -1.0 * (8.0 * t * t * t * t - 1.0);
    }

    // Quintic easing in - accelerating from zero velocity
    inline double quintIn(double t) {
        return t * t * t * t * t;
    }

    // Quintic easing out - decelerating to zero velocity
    inline double quintOut(double t) {
        t -= 1.0;
        return t * t * t * t * t + 1.0;
    }

    // Quintic easing in/out - acceleration until halfway, then deceleration
    inline double quintInOut(double t) {
        if (t < 0.5) {
            return 16.0 * t * t * t * t * t;
        }
        t -= 1.0;
        return 0.5 * (32.0 * t * t * t * t * t + 1.0);
    }

    // Sine easing in - accelerating from zero velocity
    inline double sineIn(double t) {
        return 1.0 - std::cos((t * M_PI) / 2.0);
    }

    // Sine easing out - decelerating to zero velocity
    inline double sineOut(double t) {
        return std::sin((t * M_PI) / 2.0);
    }

    // Sine easing in/out - acceleration until halfway, then deceleration
    inline double sineInOut(double t) {
        return -0.5 * (std::cos(M_PI * t) - 1.0);
    }

    // Exponential easing in - accelerating from zero velocity
    inline double expoIn(double t) {
        return (t == 0.0) ? 0.0 : std::pow(2.0, 10.0 * (t - 1.0));
    }

    // Exponential easing out - decelerating to zero velocity
    inline double expoOut(double t) {
        return (t == 1.0) ? 1.0 : (-std::pow(2.0, -10.0 * t) + 1.0);
    }

    // Exponential easing in/out - acceleration until halfway, then deceleration
    inline double expoInOut(double t) {
        if (t == 0.0 || t == 1.0) return t;
        if (t < 0.5) {
            return 0.5 * std::pow(2.0, 20.0 * t - 10.0);
        }
        return -0.5 * std::pow(2.0, -20.0 * t + 10.0) + 1.0;
    }

    // Circular easing in - accelerating from zero velocity
    inline double circIn(double t) {
        return 1.0 - std::sqrt(1.0 - t * t);
    }

    // Circular easing out - decelerating to zero velocity
    inline double circOut(double t) {
        t -= 1.0;
        return std::sqrt(1.0 - t * t);
    }

    // Circular easing in/out - acceleration until halfway, then deceleration
    inline double circInOut(double t) {
        if (t < 0.5) {
            return 0.5 * (1.0 - std::sqrt(1.0 - 4.0 * t * t));
        }
        return 0.5 * (std::sqrt(-((2.0 * t - 3.0) * (2.0 * t - 1.0))) + 1.0);
    }

    // Back easing in - accelerating from zero velocity
    inline double backIn(double t) {
        const double c1 = 1.70158;
        const double c3 = c1 + 1.0;
        return c3 * t * t * t - c1 * t * t;
    }

    // Back easing out - decelerating to zero velocity
    inline double backOut(double t) {
        const double c1 = 1.70158;
        const double c3 = c1 + 1.0;
        t -= 1.0;
        return c3 * t * t * t + c1 * t * t + 1.0;
    }

    // Back easing in/out - acceleration until halfway, then deceleration
    inline double backInOut(double t) {
        const double c1 = 1.70158;
        const double c2 = c1 * 1.525;
        if (t < 0.5) {
            return 0.5 * (t * t * ((c2 + 1.0) * t - c2));
        }
        t -= 2.0;
        return 0.5 * (t * t * ((c2 + 1.0) * t + c2) + 2.0);
    }

    // Elastic easing in - accelerating from zero velocity
    inline double elasticIn(double t) {
        const double c4 = (2 * M_PI) / 3.0;
        return (t == 0.0) ? 0.0 : (t == 1.0) ? 1.0 : -std::pow(2.0, 10.0 * t - 10.0) * std::sin((t * 10.0 - 10.75) * c4);
    }

    // Elastic easing out - decelerating to zero velocity
    inline double elasticOut(double t) {
        const double c4 = (2 * M_PI) / 3.0;
        return (t == 0.0) ? 0.0 : (t == 1.0) ? 1.0 : std::pow(2.0, -10.0 * t) * std::sin((t * 10.0 - 0.75) * c4) + 1.0;
    }

    // Elastic easing in/out - acceleration until halfway, then deceleration
    inline double elasticInOut(double t) {
        const double c5 = (2 * M_PI) / 4.5;
        return (t == 0.0) ? 0.0 : (t == 1.0) ? 1.0 :
            (t < 0.5 ? -(std::pow(2.0, 20.0 * t - 10.0) * std::sin((20.0 * t - 11.125) * c5)) / 2.0 :
                (std::pow(2.0, -20.0 * t + 10.0) * std::sin((20.0 * t - 11.125) * c5)) / 2.0 + 1.0);
    }

    // Bounce easing out - decelerating to zero velocity
    inline double bounceOut(double t) {
        if (t < (1.0 / 2.75)) {
            return 7.5625 * t * t;
        }
        else if (t < (2.0 / 2.75)) {
            t -= (1.5 / 2.75);
            return 7.5625 * t * t + 0.75;
        }
        else if (t < (2.5 / 2.75)) {
            t -= (2.25 / 2.75);
            return 7.5625 * t * t + 0.9375;
        }
        else {
            t -= (2.625 / 2.75);
            return 7.5625 * t * t + 0.984375;
        }
    }

    // Bounce easing in - accelerating from zero velocity
    inline double bounceIn(double t) {
        return 1.0 - bounceOut(1.0 - t);
    }

    // Bounce easing in/out - acceleration until halfway, then deceleration
    inline double bounceInOut(double t) {
        return (t < 0.5) ? bounceIn(t * 2.0) * 0.5 : bounceOut(t * 2.0 - 1.0) * 0.5 + 0.5;
    }

    // Circular easing in - accelerating from zero velocity
    inline double circleIn(double t) {
        return 1.0 - std::sqrt(1.0 - t * t);
    }

    // Circular easing out - decelerating to zero velocity
    inline double circleOut(double t) {
        t -= 1.0;
        return std::sqrt(1.0 - t * t);
    }

    // Circular easing in/out - acceleration until halfway, then deceleration
    inline double circleInOut(double t) {
        if (t < 0.5) {
            return 0.5 * (1.0 - std::sqrt(1.0 - 4.0 * t * t));
        }
        return 0.5 * (std::sqrt(-((2.0 * t - 3.0) * (2.0 * t - 1.0))) + 1.0);
    }

}
