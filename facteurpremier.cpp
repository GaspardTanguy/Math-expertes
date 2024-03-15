#include <iostream>
#include <vector>
#include <cmath>

// Vérifier si un nombre est premier
bool estPremier(long long n) {
    if (n <= 1) return false;
    for (long long i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Trouver les facteurs premiers d'un nombre
std::vector<long long> trouverFacteursPremiers(long long n) {
    std::vector<long long> facteurs;
    // Traiter les cas de 2 séparément pour permettre des incréments de 2 plus tard
    while (n % 2 == 0) {
        facteurs.push_back(2);
        n /= 2;
    }
    // n est maintenant impair, vérifier les facteurs en commençant par 3
    for (long long i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            facteurs.push_back(i);
            n /= i;
        }
    }
    // Si n est un nombre premier plus grand que 2
    if (n > 2) {
        facteurs.push_back(n);
    }
    return facteurs;
}

int main() {
    long long nombre;
    std::cout << "Entrez un nombre: ";
    std::cin >> nombre;

    if (estPremier(nombre)) {
        std::cout << nombre << " est un nombre premier." << std::endl;
    } else {
        std::cout << nombre << " n'est pas un nombre premier." << std::endl;
        std::cout << "Ses facteurs premiers sont: ";
        std::vector<long long> facteurs = trouverFacteursPremiers(nombre);
        for (long long facteur : facteurs) {
            std::cout << facteur << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
