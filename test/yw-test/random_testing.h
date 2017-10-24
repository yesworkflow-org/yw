#include <string>

namespace yw {
    namespace test {

        class RandomTextGenerator {

        public:
            void RandomTextGenerator::setSeed(unsigned int seed) {
                srand(seed);
            }

            char RandomTextGenerator::getRandomASCIICharacter() {
                return rand() % 128;
            }

            std::string RandomTextGenerator::getRandomASCIIText(size_t size) {
                std::stringstream ss;
                for (size_t i = 0; i < size; ++i) {
                    ss << getRandomASCIICharacter();
                }
                return ss.str();
            }
        };
    }
}