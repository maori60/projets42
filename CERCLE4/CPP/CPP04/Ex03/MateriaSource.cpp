#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++) _storage[i] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    for (int i = 0; i < 4; i++)
        _storage[i] = other._storage[i] ? other._storage[i]->clone() : nullptr;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this != &other) {
        for (int i = 0; i < 4; i++) {
            delete _storage[i];
            _storage[i] = other._storage[i] ? other._storage[i]->clone() : nullptr;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++)
        delete _storage[i];
}

void MateriaSource::learnMateria(AMateria* m) {
    for (int i = 0; i < 4; i++) {
        if (!_storage[i]) {
            _storage[i] = m;
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++) {
        if (_storage[i] && _storage[i]->getType() == type)
            return _storage[i]->clone();
    }
    return nullptr;
}
