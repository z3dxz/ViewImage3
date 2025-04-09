#include <SFML/Audio.hpp>
#include <vector>
#include <cmath>
#include <iostream>

inline sf::SoundBuffer generateBeep(float frequency, float durationSeconds, unsigned sampleRate = 44100)
{
    const std::size_t sampleCount = static_cast<std::size_t>(durationSeconds * sampleRate);
    std::vector<sf::Int16> samples(sampleCount);

    const double twoPiF = 2.0 * 3.14159265359 * frequency;

    for (std::size_t i = 0; i < sampleCount; ++i)
    {
        double t = static_cast<double>(i) / sampleRate;
        samples[i] = static_cast<sf::Int16>(32767 * std::sin(twoPiF * t));
    }

    sf::SoundBuffer buffer;
    if (!buffer.loadFromSamples(samples.data(), sampleCount, 1, sampleRate))
        std::cerr << "Failed to load samples into buffer!" << std::endl;

    return buffer;
}