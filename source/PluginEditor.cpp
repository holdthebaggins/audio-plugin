#include "PluginEditor.h"

AudioPluginEditor::AudioPluginEditor (AudioPluginAudioProcessor& p)
    : AudioProcessorEditor (&p),
      processorState (p)
{
    // This is just a dark canvas for now — we'll style it up together.
    // Think of this like your plugin's UI canvas.
    //
    // When you want controls:
    //   slider.setBounds(50, 50, 200, 30);  // add a knob-like slider
    //   slider.setTextBoxStyle(juce::Slider::TextBoxLeft, false, 80, 20);
    //   addAndMakeVisible(slider);
    //
    // TouchOSC-compatible control layouts:
    //   - Faders (vertical sliders) for levels/parameters
    //   - Rotary knobs for filters/oscillators
    //   - Toggle switches for on/off states
    // We can design these to match your Eurorack workflow later.

    addAndMakeVisible(placeholderLabel);
    placeholderLabel.setFont (juce::Font (20.0f));
    placeholderLabel.setText ("AudioPlugin", juce::dontSendNotification);
    placeholderLabel.setJustificationType (juce::Justification::centred);

    setSize (400, 300);
}

void AudioPluginEditor::paint (juce::Graphics& g)
{
    // Dark background — fits the vibe
    g.fillAll (juce::Colour (0x222228));

    g.setColour (juce::Colour (0xFF4488CC));
    g.drawRect (0, 0, getWidth(), getHeight(), 2);
}

void AudioPluginEditor::resized()
{
    placeholderLabel.setBounds (100, 130, 200, 40);
}
