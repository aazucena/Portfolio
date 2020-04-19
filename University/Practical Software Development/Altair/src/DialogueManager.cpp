#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "DialogueManager.h"

std::vector<KeyLines*> DialogueManager::getLines() {
    return lines;
}

void DialogueManager::addLine(KeyLines* kl) {
//Removes duplicates in vector, then adds to vector
    std::sort(lines.begin(), lines.end());
    lines.erase(unique(lines.begin(), lines.end()), lines.end());
    getLines().push_back(kl);
}

bool DialogueManager::searchLine(KeyLines* kl) {
    for (int i = 0; i < getLines().size(); i++) {
        if (std::find(getLines().begin(), getLines().end(), kl)
            != getLines().end()) {
            getLines().erase(getLines().begin()+i);
            return true;
            break;
        } else {
            return false;
        }
    }
}

void DialogueManager::delLine(KeyLines* kl) {
    for (int i = 0; i < getLines().size(); i++) {
        if (find(getLines().begin(), getLines().end(), kl)
            != getLines().end()) {
            getLines().erase(getLines().begin()+i);
            break;
        }
    }
}


