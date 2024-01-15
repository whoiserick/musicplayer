#include "music_utils.h"
#include <boost/filesystem.hpp>
#include <taglib/fileref.h>
#include <taglib/tag.h>

namespace fs = boost::filesystem;

namespace MusicUtils {
    std::vector<std::string> listAudioFiles(const std::string& folderPath) {
        std::vector<std::string> audioFiles;

        fs::path folder(folderPath);

        if (!fs::exists(folder) || !fs::is_directory(folder)) {
            std::cerr << "A pasta não existe ou não é um diretório válido." << std::endl;
            return audioFiles;
        }

        for (const auto& entry : fs::directory_iterator(folder)) {
            if (entry.path().extension() == ".mp3" || entry.path().extension() == ".flac" || entry.path().extension() == ".wav") {
                audioFiles.push_back(entry.path().string());
            }
        }

        return audioFiles;
    }
}
