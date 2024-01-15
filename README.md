# Console Music Player

A simple console-based music player project in C++.

## Overview

This project is a console-based music player that allows you to play audio files in a specified folder. It utilizes C++ for the backend logic, and the example uses the SFML library for audio playback.

## Features

- **Audio Playback**: Play audio files in a specified folder.
- **Tag Information**: Display title and artist information using TagLib.
- **Basic Media Controls**: Skip track, repeat track, shuffle playlist.

## Dependencies

- C++ compiler
- SFML library (for audio playback)
- Boost library (for filesystem operations)
- TagLib library (for reading audio file metadata)

## Getting Started

1. **Clone the Repository:**

    ```bash
    git clone https://github.com/whoiserick/musicplayer.git
    cd musicplayer
    ```

2. **Build the Project:**

    ```bash
    mkdir build
    cd build
    cmake ..
    make
    ```

3. **Run the Program:**

    ```bash
    ./musicplayer
    ```

## Usage

1. Specify your music folder path in the `main.cpp` file.
2. Build and run the program.
3. Follow the console instructions to control the music player.
