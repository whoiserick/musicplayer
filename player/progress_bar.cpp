#include "progress_bar.h"
#include <iostream>
#include <Windows.h>

void ProgressBar::updateProgressBar(double progress) {
    const int barWidth = 50;

    // garantindo que o progresso esteja no intervalo [0, 1]
    progress = std::max(0.0, std::min(1.0, progress));

    int barProgress = static_cast<int>(barWidth * progress);

    std::cout << "[";
    for (int i = 0; i < barWidth; ++i) {
        if (i < barProgress) {
            std::cout << "=";
        }
        else {
            std::cout << " ";
        }
    }

    std::cout << "] " << static_cast<int>(progress * 100) << "%" << std::endl;

    // lógica real de atualização da barra de progresso aqui

    // simulação de uma operação demorada 
    for (int i = 0; i < 10; ++i) {
        // lógica da operação demorada
        Sleep(100);  // simulação de uma etapa da operação que leva 100ms

        // atualiza a barra de progresso após cada etapa
        progress += 0.1;
        barProgress = static_cast<int>(barWidth * progress);
        std::cout << "\r[";  // \r move o cursor para o início da linha
        for (int i = 0; i < barWidth; ++i) {
            if (i < barProgress) {
                std::cout << "=";
            }
            else {
                std::cout << " ";
            }
        }
        std::cout << "] " << static_cast<int>(progress * 100) << "%" << std::flush;
    }

    std::cout << std::endl;
}
