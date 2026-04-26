#include "PluginProcessor.h"
#include "PluginEditor.h"

AudioPluginAudioProcessor::AudioPluginAudioProcessor()
    : apvtState(*this, nullptr, juce::Identifier("params"),
                 {})  // start without knobs — we'll add them as needed
{
    // Parameter list goes here. Example:
    // paramName1 = std::make_unique<Param> (
    //     apvtState.parameters,
    //     "freq_hz",     // internal parameter name
    //     "Frequency",   // how it appears in a DAW
    //     0.0,           // default value
    //     20.0,          // min
    //     20000.0,       // max
    //     1000.0         // initial value
    // );
}

AudioPluginAudioProcessor::~AudioPluginAudioProcessor() = default;

void AudioPluginAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Called once when the DAW opens the plugin.
    // Use this to init internal structures, reset oscillators, etc.
    juce::Logger::writeToLog ("AudioPlugin: prepared to play");
}

void AudioPluginAudioProcessor::releaseResources()
{
    // Called when the DAW closes the plugin.
}

bool AudioPluginAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
    // This plugin is stereo — two input buses and two output buses
    return layouts.getMainOutputChannelSet() == juce::AudioChannelSet::stereo()
        && layouts.getMainInputChannelSet()  == juce::AudioChannelSet::stereo();
}

void AudioPluginAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer,
                                              juce::MidiBuffer&)
{
    // This is the main processing loop — called thousands of times per second.
    // Every block of audio samples passes through here.
    //
    // Right now it's a straight pass-through (the audio enters and leaves untouched).
    // That's the safest starting point while we verify the whole build works.
    //
    // When you want to add processing:
    //   auto* bufferPtr  = buffer.getWritePointer(channelIndex);
    //   for (int i = 0; i < buffer.getNumSamples(); ++i)
    //       bufferPtr[i] *= someValue;  // example manipulation
    //
    // We'll fill this in together with whatever effect you want to build.

    for (int channel = 0; channel < buffer.getNumChannels(); ++channel)
    {
        auto *channelData = buffer.getWritePointer(channel);

        // Pass-through: leave the audio unchanged
        // when you're ready to add processing, modify channelData[i] in place
    }
}

juce::AudioProcessorEditor* AudioPluginAudioProcessor::createEditor()
{
    return new AudioPluginEditor (*this);
}

bool AudioPluginAudioProcessor::hasEditor() const
{
    return true;  // We have a visual editor
}

const juce::String AudioPluginAudioProcessor::getName() const
{
    return JUCE_APPLICATION_NAME_STRING;
}

void AudioPluginAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // Save plugin settings so they survive reopening the plugin.
    // Right now nothing to save (no parameters yet).
    destData = juce::MemoryBlock();
}

void AudioPluginAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // Restore plugin settings.
    // Nothing to restore yet.
}
