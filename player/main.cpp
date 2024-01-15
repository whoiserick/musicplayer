#include "audio_player.h"
#include "music_utils.h"
#include <iostream>
#include <SFML/Audio.hpp>
#include <chrono>
#include <thread>

int main() {
    AudioPlayer audioPlayer;

    // especificando o caminho da pasta de m�sicas
    std::string musicFolder = "musicas";

    // listando arquivos de �udio na pasta
    std::vector<std::string> audioFiles = MusicUtils::listAudioFiles(musicFolder);

    if (audioFiles.empty()) {
        std::cerr << "Nenhum arquivo de �udio encontrado na pasta." << std::endl;
        return 1;
    }

    // rproduzindo cada arquivo de �udio na lista
    for (const auto& audioFile : audioFiles) {
        // exibindo informa��es do arquivo
        std::cout << "Reproduzindo: " << audioFile << std::endl;

        // criando um objeto de m�sica com SFML
        sf::Music music;
        if (!music.openFromFile(audioFile)) {
            std::cerr << "Falha ao carregar o arquivo de �udio: " << audioFile << std::endl;
            continue;
        }

        // extraindo informa��es do arquivo usando taglib
        TagLib::FileRef file(audioFile.c_str());
        if (!file.isNull() && file.tag()) {
            std::string title = file.tag()->title().toCString(true);
            std::string artist = file.tag()->artist().toCString(true);

            std::cout << "T�tulo: " << title << ", Artista: " << artist << std::endl;
        }
        else {
            std::cerr << "Falha ao obter informa��es do arquivo: " << audioFile << std::endl;
        }

        // reproduzindo o arquivo de �udio
        music.play();

        // aguardando at� o final da m�sica
        while (music.getStatus() == sf::Music::Playing) {
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }

    return 0;
}
