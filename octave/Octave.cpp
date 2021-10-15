#include "Octave.h"

vector<shared_ptr<Element>> Octave::get_elements() const {
    return elements;
}

void Octave::add_element(const shared_ptr<Element>& element) {
    elements.push_back(element);
}

shared_ptr<Element> Octave::getLast() {
    return elements.back();
}

