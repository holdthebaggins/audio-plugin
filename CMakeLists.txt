cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 20)

project(AudioPlugin VERSION 0.1.0 LANGUAGES CXX)

# JUCE must be added at ROOT level, NOT JUCE/modules
add_subdirectory(JUCE)

juce_add_plugin(AudioPlugin
    VERSION "0.1.0"
    IS_SYNTH false
    NEEDS_MIDI_INPUT false
    NEEDS_MIDI_OUTPUT false
    NEEDS_WEB_BROWSER false
    PLUGIN_MANUFACTURER_CODE Earth
    PLUGIN_CODE Aud0
    PRODUCT_NAME "AudioPlugin"
    FORMATS VST3 AU AUv3 CLAP
)

juce_generate_juce_header(AudioPlugin)

target_sources(AudioPlugin
    PRIVATE
        source/PluginEntryPoint.cpp
        source/PluginProcessor.h
        source/PluginProcessor.cpp
        source/PluginEditor.h
        source/PluginEditor.cpp
)

target_compile_definitions(AudioPlugin
    PUBLIC
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
        JUCE_VST3_CAN_REPLACE_VST2=0
        JUCE_DISPLAY_SPLASH_SCREEN=0
)

target_link_libraries(AudioPlugin
    PRIVATE
        juce::juce_audio_utils
        juce::juce_dsp
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags
)
