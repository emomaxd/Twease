#include <iostream>
#include <vector>

#include "Twease/Twease.h"

int main() {

#if 1

    double deltaTime = 0.016; // 60 FPS

    
    auto anim = Twease::Animation<double>::animate(0.0, 100.0).during(2.0).easing(Twease::cubicIn);

    while (!anim.isCompleted()) {
        anim.update(deltaTime);
        std::cout << "Current value: " << anim.getCurrentValue() << std::endl;
    }
    
#endif

#if 0

    auto helloworld = Twease::Tween<char>({ 'h', 'e', 'l', 'l', 'o' })
        .to({ 'w', 'o', 'r', 'l', 'd' })
        .during(50);


    for (int i = 0; i <= helloworld.during(); ++i) {
        std::vector<char> interpolatedSequence = helloworld.step(static_cast<double>(i) / helloworld.during());

        for (char c : interpolatedSequence)
            std::cout << c;
       
        std::cout << std::endl;
    }

#endif

    return 0;
}