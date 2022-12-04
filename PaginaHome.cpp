//
// Created by simon on 04/12/2022.
//

#include "PaginaHome.h"

void PaginaHome::addCollezione(CollezioneNote *collezioneNote) {
        this->collezioneNote.insert(make_pair((*collezioneNote).getNomeLista(), collezioneNote));
}
