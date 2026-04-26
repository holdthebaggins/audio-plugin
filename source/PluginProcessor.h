#pragma once

#include <juce_audio_basics/juce_audio_basics.h>
#include <juce_audio_processors/juce_audio_processors.h>

class AudioPluginAudioProcessor  : public juce::AudioProcessor
{
public:
    AudioPluginAudioProcessor();

    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    const juce::String getName() const override;

    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

private:
    // Your audio processing here:
    // Delay lines, oscillators, filters, reverb, distortion — it's all yours.
    // We start with a dry pass-through (silence) and build up.

    JUCE_NON_COPYABLE_WITH_THE_DELETE_MESSAGE(AudioPluginAudioProcessor)

    juce::AudioProcessorValueTreeState apvtState{ *this };
    using Param = juce::AudioProcessorValueTreeState::Parameter;

    std::unique_ptr<Param> paramName1;
};
