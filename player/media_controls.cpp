#include "audio_player.h"
#include <iostream>
#include <Windows.h>

void AudioPlayer::playAudio(const std::string& filename) {
    std::wcout << L"Reproduzindo: " << filename << std::endl;

    // convertendo a string para wide string
    std::wstring wideFilename(filename.begin(), filename.end());

    // abrindo o arquivo de �udio com o player padr�o do windows
    HINSTANCE result = ShellExecuteW(NULL, L"open", wideFilename.c_str(), NULL, NULL, SW_SHOWNORMAL);

    // verificando se a execu��o foi bem-sucedida
    if ((intptr_t)result <= 32) {
        DWORD error = GetLastError();
        LPVOID errorMsg;
        FormatMessageW(
            FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
            NULL,
            error,
            0, // default language
            (LPWSTR)&errorMsg,
            0,
            NULL
        );

        std::wcerr << L"Erro ao reproduzir o arquivo de �udio: " << errorMsg << std::endl;

        // liberando o buffer de mensagem de erro
        LocalFree(errorMsg);

        // l�gica para lidar com erros conforme necess�rio
    }
}
