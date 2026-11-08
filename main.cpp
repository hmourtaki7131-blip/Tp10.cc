#include <iostream>
#include <string>
using namespace std;

class Contact {
private:
    string nom;
    string telephone;
    string email;

public:
    Contact(string n, string t, string e) {
        nom = n;
        telephone = t;
        email = e;
    }

    string getNom() {
        return nom;
    }

    void afficher() {
        cout << "Nom : " << nom << endl;
        cout << "Telephone : " << telephone << endl;
        cout << "Email : " << email << endl;
    }
};

// Ajouter un contact
void ajouterContact(Contact** carnet, int& taille) {
    string nom, telephone, email;

    cout << "Nom : ";
    getline(cin, nom);

    cout << "Telephone : ";
    getline(cin, telephone);

    cout << "Email : ";
    getline(cin, email);

    carnet[taille] = new Contact(nom, telephone, email);

    taille++;

    cout << "Contact ajoute avec succes !" << endl;
}

// Afficher les contacts
void afficherContacts(Contact** carnet, int taille) {
    if (taille == 0) {
        cout << "Aucun contact !" << endl;
        return;
    }

    for (int i = 0; i < taille; i++) {
        cout << "\nContact " << i + 1 << endl;
        carnet[i]->afficher();
    }
}

// Supprimer un contact
void supprimerContact(Contact** carnet, int& taille, string nom) {
    for (int i = 0; i < taille; i++) {

        if (carnet[i]->getNom() == nom) {

            delete carnet[i];

            for (int j = i; j < taille - 1; j++) {
                carnet[j] = carnet[j + 1];
            }

            taille--;

            cout << "Contact supprime !" << endl;
            return;
        }
    }

    cout << "Contact introuvable !" << endl;
}

int main() {
    int capacite = 100;
    int taille = 0;
    int choix;
    string nom;

    // Tableau dynamique de pointeurs
    Contact** carnet = new Contact*[capacite];

    do {
        cout << "\n===== CARNET D'ADRESSES =====" << endl;
        cout << "1. Ajouter un contact" << endl;
        cout << "2. Afficher les contacts" << endl;
        cout << "3. Supprimer un contact" << endl;
        cout << "0. Quitter" << endl;
        cout << "Votre choix : ";

        cin >> choix;
        cin.ignore();

        switch (choix) {

        case 1:
            if (taille < capacite) {
                ajouterContact(carnet, taille);
            } else {
                cout << "Carnet plein !" << endl;
            }
            break;

        case 2:
            afficherContacts(carnet, taille);
            break;

        case 3:
            cout << "Donner le nom a supprimer : ";
            getline(cin, nom);
            supprimerContact(carnet, taille, nom);
            break;

        case 0:
            cout << "Fin du programme." << endl;
            break;

        default:
            cout << "Choix invalide !" << endl;
        }

    } while (choix != 0);

    // Liberation de toute la memoire
    for (int i = 0; i < taille; i++) {
        delete carnet[i];
    }

    delete[] carnet;

    return 0;
}