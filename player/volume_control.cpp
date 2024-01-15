#include "volume_control.h"
#include <iostream>
#include <Windows.h>

void VolumeControl::setVolume(double volumeLevel) {
    std::cout << "Volume ajustado para: " << volumeLevel << std::endl;

    // limitando o intervalo do volume entre 0.0 e 1.0
    volumeLevel = std::max(0.0, std::min(1.0, volumeLevel));

    // obtendo o mixer de áudio padrão
    HMIXER mixer;
    if (mixerOpen(&mixer, 0, 0, 0, 0) != MMSYSERR_NOERROR) {
        std::cerr << "Erro ao abrir o mixer de áudio." << std::endl;
        // lógica para lidar com erros, se necessário
        return;
    }

    // configurando o volume no mixer
    MIXERCONTROLDETAILS mixerControlDetails;
    mixerControlDetails.cbStruct = sizeof(MIXERCONTROLDETAILS);
    mixerControlDetails.dwControlID = 0; // ID do controle de volume mestre
    mixerControlDetails.cChannels = 1;
    mixerControlDetails.cMultipleItems = 0;
    mixerControlDetails.cbDetails = sizeof(DWORD);
    mixerControlDetails.paDetails = &volumeLevel;

    MIXERCONTROLDETAILS_UNSIGNED volumeValue;
    volumeValue.dwValue = static_cast<DWORD>(volumeLevel * 0xFFFF);
    mixerControlDetails.paDetails = &volumeValue;

    MIXERLINECONTROLS mixerLineControls;
    mixerLineControls.cbStruct = sizeof(MIXERLINECONTROLS);
    mixerLineControls.dwControlType = MIXERCONTROL_CONTROLTYPE_VOLUME;
    mixerLineControls.cControls = 1;
    mixerLineControls.pamxctrl = nullptr;

    if (mixerGetLineControls(reinterpret_cast<HMIXEROBJ>(mixer), &mixerLineControls, MIXER_GETLINECONTROLSF_ONEBYTYPE) != MMSYSERR_NOERROR) {
        std::cerr << "Erro ao obter os controles do mixer de áudio." << std::endl;
        // lógica para lidar com erros, se necessário
        mixerClose(mixer);
        return;
    }

    if (mixerSetControlDetails(reinterpret_cast<HMIXEROBJ>(mixer), &mixerControlDetails, MIXER_SETCONTROLDETAILSF_VALUE) != MMSYSERR_NOERROR) {
        std::cerr << "Erro ao configurar o volume no mixer de áudio." << std::endl;
        // lógica para lidar com erros, se necessário
    }

    // fechando o mixer
    mixerClose(mixer);
}
