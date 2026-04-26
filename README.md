# AudioPlugin

A JUCE-based audio plugin project.

## Getting Started

### 1. Get the JUCE framework

```bash
cd ~/Documents/audio-plugin
git submodule add https://github.com/juce-framework/JUCE.git JUCE
```

### 2. Build the plugin

```bash
cd ~/Documents/audio-plugin
cmake -B build -G "Unix Makefiles" ..
cmake --build build --config Release
```

### 3. Install to your DAW

#### VST3 (Ableton, Reaper, etc.)
```bash
cp -r build/Release/AudioPlugin.vst3 ~/Music/AudioPlugins/
```

#### AU (Logic Pro)
```bash
cp -r build/Release/AudioPlugin.component ~/Music/AudioMusicAssets/
```

#### CLAP (Bitwig, Carla)
```bash
cp build/Release/AudioPlugin.clap ~/Library/Application\ Support/com.bitwig.Studio/Clap/
```

## Editing the Plugin

- **`source/PluginProcessor.h`** — Audio processing logic (effect behavior, filters, oscillators, etc.)
- **`source/PluginProcessor.cpp`** — Main processing loop & parameter handling
- **`source/PluginEditor.h`** — Visual editor layout in code
- **`source/PluginEditor.cpp`** — UI styling & control placement

We build the plugin together, one effect at a time. Tell me what kind of effect you want to start with (reverb, delay, distortion, filter, etc.) and we'll code it up.
