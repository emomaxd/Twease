Twease Library
===============

Overview
--------
Twease is a header only C++ library designed to provide utilities for animation, tweening, and easing functions. It facilitates smooth transitions between values and can be integrated into various applications requiring dynamic value changes over time.

Features
--------
1. **Tweening**: Interpolate between sequences of values over a specified duration.
2. **Easing Functions**: Provide various easing functions (e.g., linear, quadratic, cubic) for smooth animations.
3. **Animation**: Transition smoothly between different states or values.
4. **Customizable**: Easily integrate into existing C++ projects with customizable interpolation methods and easing functions.


Animation example:
--------
```cpp
#include <iostream>
#include <vector>

#include "Twease/Twease.h"

int main() {

    double deltaTime = 0.016; // 60 FPS

    
    auto anim = Twease::Animation<double>::animate(0.0, 100.0).during(2.0).easing(Twease::cubicIn);

    while (!anim.isCompleted()) {
        anim.update(deltaTime);
        std::cout << "Current value: " << anim.getCurrentValue() << std::endl;
    }
    
    return 0;
}
```
Tweening example:
--------
```cpp
#include <iostream>
#include <vector>

#include "Twease/Twease.h"

int main() {

    auto helloworld = Twease::Tween<char>({ 'h', 'e', 'l', 'l', 'o' })
    .to({ 'w', 'o', 'r', 'l', 'd' })
    .during(50);


    for (int i = 0; i <= helloworld.during(); ++i) {
        std::vector<char> interpolatedSequence = helloworld.step(static_cast<double>(i) / helloworld.during());

        for (char c : interpolatedSequence)
            std::cout << c;

        std::cout << std::endl;
    }
    
    return 0;
}
```