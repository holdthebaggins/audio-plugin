#pragma once

#include <juce_audio_processors/juce_audio_processors.h>
#include "PluginProcessor.h"

class AudioPluginEditor  : public juce::AudioProcessorEditor
{
public:
    explicit AudioPluginEditor (AudioPluginAudioProcessor& p);
    ~AudioPluginEditor() override = default;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    AudioPluginAudioProcessor& processorState;
    juce::Label placeholderLabel{ "label", "Your Plugin" };

    JUCE_DECLARE_NON_COPYABLE_WITH_THE_DELETE_MESSAGE (AudioPluginEditor)
};
