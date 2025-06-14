// colocviu 2024
#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

// generator de id uri unice
class IDGenerator {
public:
    static int GetNextID() {
        static int currentID = 0;
        return currentID++;
    }
};

// clasa de baza pentru fiecare obiect indiferent de tipul sau
class Element {
protected:
    const int id;
public:
    Element() : id(IDGenerator::GetNextID()) {}
    virtual ~Element() = default;

    // getter
    int GetID() const {
        return this->id;
    }

    virtual std::string GetElementType() const = 0;
    virtual int GetCostUpgrade() const = 0;
    virtual void DisplayElement() const {
        std::cout << "ID: " << this->id << " | Type: " << this->GetElementType() << std::endl;
    }
};

class Zid : public Element {
private:
    float inaltime;
    float lungime;
    float grosime;
public:
    // constructor
    Zid(float inaltime, float lungime, float grosime) : inaltime(inaltime), lungime(lungime), grosime(grosime) {}

    // constructor de copiere
    Zid(const Zid& zid) {
        this->inaltime = zid.inaltime;
        this->lungime = zid.lungime;
        this->grosime = zid.grosime;
    }

    // operatorul de atribuire
    Zid& operator=(const Zid& zid) {
        if (this != &zid) {
            this->inaltime = zid.inaltime;
            this->lungime = zid.lungime;
            this->grosime = zid.grosime;
        }
        return *this;
    }

    // supraincarcarea operatorului de afisare
    friend std::ostream& operator<<(std::ostream& out, const Zid& zid) {
        out << "Inaltimea zidului: " << zid.inaltime << std::endl;
        out << "Lungimea zidului: " << zid.lungime << std::endl;
        out << "Grosimea zidului: " << zid.grosime << std::endl;
        return out;
    }

    // supraincarcarea operatorului de citire
    friend std::istream& operator>>(std::istream& in, Zid& zid) {
        std::cout << "Inaltimea zidului: " << std::endl;
        in >> zid.inaltime;
        std::cout << "Lungimea zidului: " << std::endl;
        in >> zid.lungime;
        std::cout << "Grosimea zidului: " << std::endl;
        in >> zid.grosime;
        return in;
    }

    // metoda de citire
    void ReadZid() {
        std::cin >> *this;
    }

    // metoda de afisare
    void DisplayZid() const {
        std::cout << *this;
    }

    // getteri
    const float GetInaltimeZid() const {
        return this->inaltime;
    }
    const float GetLungimeZid() const {
        return this->lungime;
    }
    const float GetGrosimeZid() const {
        return this->grosime;
    }

    // setteri
    void SetInaltimeZid(float inaltime) {
        this->inaltime = inaltime;
    }
    void SetLungimeZid(float lungime) {
        this->lungime = lungime;
    }
    void SetGrosimeZid(float grosime) {
        this->grosime = grosime;
    }

    // override
    std::string GetElementType() const override {
        return "ZID";
    }

    int GetCostUpgrade() const override {
        return 100 * this->inaltime * this->lungime + this->grosime;
    }

    // destructor
    ~Zid() override = default;
};

class Turn : public Element {
private:
    int putere;
public:
    // constructor
    Turn(int putere) : putere(putere) {}

    // constructor de copiere
    Turn(const Turn& turn) {
        this->putere = turn.putere;
    }

    // operator de atribuire
    Turn& operator=(const Turn& turn) {
        if (this != &turn) {
            this->putere = turn.putere;
        }
        return *this;
    }

    // supraincarcare operatori
    friend std::ostream& operator<<(std::ostream& out, const Turn& turn) {
        out << "Putere turn: " << turn.putere << std::endl;
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Turn& turn) {
        std::cout << "Putere turn: " << std::endl;
        in >> turn.putere;
        return in;
    }

    // metode de citire si afisare
    void ReadTurn() {
        std::cin >> *this;
    }
    void DisplayTurn() const {
        std::cout << *this;
    }

    // getteri
    const int GetPutereTurn() const {
        return this->putere;
    }

    //setteri
    void SetPutereTurn(int putere) {
        this->putere = putere;
    }

    // override
    std::string GetElementType() const override {
        return "TURN";
    }

    int GetCostUpgrade() const override {
        return 500 * this->putere;
    }

    // destructor
    ~Turn() override = default;
};

// creez o clasa abstracta robot cu derivatele robot aerian si robot terestru

class Robot : public Element {
protected:
    int damage;
    int nivel;
    int viata;
public:
    Robot(int damage, int nivel, int viata) : damage(damage), nivel(nivel), viata(viata) {}

    Robot(const Robot& robot) {
        this->damage = robot.damage;
        this->nivel = robot.nivel;
        this->viata = robot.viata;
    }

    Robot& operator=(const Robot& robot) {
        if (this != &robot) {
            this->damage = robot.damage;
            this->nivel = robot.nivel;
            this->viata = robot.viata;
        }
        return *this;
    }

    // citirea datelor pur virtuala
    virtual void ReadRobot(std::istream& in) = 0;

    // afisarea datelor pur virtuala
    virtual void DisplayRobot(std::ostream& out) const = 0;

    // supraincarcarea
    friend std::ostream& operator<<(std::ostream& out, const Robot& robot) {
        robot.DisplayRobot(out);
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Robot& robot) {
        robot.ReadRobot(in);
        return in;
    }

    // getteri
    const int GetRobotDamage() const {
        return this->damage;
    }
    const int GetRobotNivel() const {
        return this->nivel;
    }
    const int GetRobotViata() const {
        return this->viata;
    }

    // setteri
    void SetRobotDamage(int damage) {
        this->damage = damage;
    }
    void SetRobotNivel(int nivel) {
        this->nivel = nivel;
    }
    void SetRobotViata(int viata) {
        this->viata = viata;
    }

    // override
    std::string GetElementType() const override {
        return "ROBOT";
    }

    // destructor virtual
    virtual ~Robot() = default;
};

// clasa RobotAerian este derivata

class RobotAerian : virtual public Robot {
private:
    int autonomie;

public:
    RobotAerian(int damage, int nivel, int viata, int autonomie) : Robot(damage, nivel, viata) ,autonomie(autonomie) {}

    // copiere
    RobotAerian(const RobotAerian& robot_aerian) : Robot(robot_aerian) {
        this->autonomie = robot_aerian.autonomie;
    }

    // atribuire
    RobotAerian& operator=(const RobotAerian& robot_aerian) {
        if (this != &robot_aerian) {
            this->damage = robot_aerian.damage;
            this->nivel = robot_aerian.nivel;
            this->viata = robot_aerian.viata;
            this->autonomie = robot_aerian.autonomie;
        }
        return *this;
    }

    //supraincarcarea
    void ReadRobot(std::istream& in) override {
        std::cout << " RA Damage: ";
        in >> this->damage;
        std::cout << " RA Nivel: ";
        in >> this->nivel;
        std::cout << " RA Viata: ";
        in >> this->viata;
        std::cout << " RA Autonomie: ";
        in >> this->autonomie;
    }

    void DisplayRobot(std::ostream& out) const override {
        out << "ROBOT AERIAN: " << std::endl;
        out << "Damage: " << this->damage << std::endl;
        out << "Nivel: " << this->nivel << std::endl;
        out << "Viata: " << this->viata << std::endl;
        out << "Autonomie: " << this->autonomie << std::endl;
    }

    // getteri
    const int GetRobotAerianDamage() const {
        return this->damage;
    }
    const int GetRobotAerianNivel() const {
        return this->nivel;
    }
    const int GetRobotAerianViata() const {
        return this->viata;
    }
    const int GetRobotAerianAutonomie() const {
        return this->autonomie;
    }

    // setteri
    void SetRobotAerianDamage(int damage) {
        this->damage = damage;
    }
    void SetRobotAerianNivel(int nivel) {
        this->nivel = nivel;
    }
    void SetRobotAerianViata(int viata) {
        this->viata = viata;
    }
    void SetRobotAerianAutonomie(int autonomie) {
        this->autonomie = autonomie;
    }

    // override
    std::string GetElementType() const override {
        return "Robot Aerian";
    }

    int GetCostUpgrade() const override {
        return 50 * this->autonomie;
    }

    // destructor
    ~RobotAerian() override = default;
};

class RobotTerestru : virtual public Robot {
private:
    int nr_gloante;
    bool scut;

public:
    RobotTerestru(int damage, int nivel, int viata, int nr_gloante, bool scut = false)
        : Robot(damage, nivel, viata), nr_gloante(nr_gloante), scut(scut) {}

    // copiere
    RobotTerestru(const RobotTerestru& robot_terestru) : Robot(robot_terestru) {
        this->nr_gloante = robot_terestru.nr_gloante;
    }

    // atribuire
    RobotTerestru& operator=(const RobotTerestru& robot_terestru) {
        if (this != &robot_terestru) {
            this->damage = robot_terestru.damage;
            this->nivel = robot_terestru.nivel;
            this->viata = robot_terestru.viata;
            this->nr_gloante = robot_terestru.nr_gloante;
            this->scut = robot_terestru.scut;
        }
        return *this;
    }

    //supraincarcarea
    void ReadRobot(std::istream& in) override {
        std::cout << " RT Damage: ";
        in >> this->damage;
        std::cout << " RT Nivel: ";
        in >> this->nivel;
        std::cout << " RT Viata: ";
        in >> this->viata;
        std::cout << " RT Nr gloante: ";
        in >> this->nr_gloante;
        std::cout << " RT Scut? (0/1)";
        in >> this->scut;
    }

    void DisplayRobot(std::ostream& out) const override {
        out << "ROBOT TERESTRU: " << std::endl;
        out << "Damage: " << this->damage << std::endl;
        out << "Nivel: " << this->nivel << std::endl;
        out << "Viata: " << this->viata << std::endl;
        out << "Nr gloante: " << this->nr_gloante << std::endl;
        out << "Scut: " << (this->scut ? "Yes" : "No") << std::endl;
    }

    // getteri
    const int GetRobotTerestuDamage() const {
        return this->damage;
    }
    const int GetRobotTerestuNivel() const {
        return this->nivel;
    }
    const int GetRobotTerestuViata() const {
        return this->viata;
    }
    const int GetRobotTerestuGloante() const {
        return this->nr_gloante;
    }

    // setteri
    void SetRobotTerestruDamage(int damage) {
        this->damage = damage;
    }
    void SetRobotTerestuNivel(int nivel) {
        this->nivel = nivel;
    }
    void SetRobotTerestruViata(int viata) {
        this->viata = viata;
    }
    void SetRobotTerestuGloante(int nr_gloante) {
        this->nr_gloante = nr_gloante;
    }
    void SetRobotTerestruScut(bool scut) {
        this->scut = scut;
    }

    // override
    std::string GetElementType() const override {
        return "Robot Terestru";
    }

    int GetCostUpgrade() const override {
        return 50 * this->nr_gloante;
    }

    // destructor
    ~RobotTerestru() override = default;
};

class Inventar {
private:
    std::vector<std::unique_ptr<Element>> obiecte;
public:
    const std::vector<std::unique_ptr<Element>>& GetObiecte() const {return obiecte;}

    void Adauga(std::unique_ptr<Element> obiect) {
        obiecte.push_back(std::move(obiect));
    }

    void DisplayInventar() const {
        for (const auto& obiect : obiecte) {
            obiect->DisplayElement();

            if (auto zid = dynamic_cast<Zid*>(obiect.get())) {
                zid->DisplayZid();
                std::cout << std::endl;
            }
            else if (auto turn = dynamic_cast<Turn*>(obiect.get())) {
                turn->DisplayTurn();
                std::cout << std::endl;
            }
            else if (auto robot_aerian = dynamic_cast<RobotAerian*>(obiect.get())) {
                robot_aerian->DisplayRobot(std::cout);
                std::cout << std::endl;
            }
            else if (auto robot_terestru = dynamic_cast<RobotTerestru*>(obiect.get())) {
                robot_terestru->DisplayRobot(std::cout);
                std::cout << std::endl;
            }
        }
    }

    bool StergeElementID(int id) {
        for (size_t i = 0; i < obiecte.size(); i++) {
            if (obiecte[i]->GetID() == id) {
                obiecte.erase(obiecte.begin() + i);
                return true;
            }
        }
        return false;
    }
};

class Game {
private:
    int score;
    Inventar inventory;
public:
    Game() : score(50000) {}

    void Meniu() {
        int option;
        do {
            std::cout << std::endl;
            std::cout << "=============== MENIU ===============" << std::endl;
            std::cout << "1. Adauga elemente" << std::endl;
            std::cout << "2. Upgrade element" << std::endl;
            std::cout << "3. Afisare elemente ordonate" << std::endl;
            std::cout << "4. Afisare elementelor de tip robot" << std::endl;
            std::cout << "5. Vinde elemente" << std::endl;
            std::cout << "Optiunea ta? ";
            std::cin >> option;

            switch (option) {
                case 1:
                    AdaugareElemente();
                break;
                case 2: {
                    UpgradeElemente();
                    std::cout << std::endl;
                    std::cout << "Inventarul tau dupa upgrade: " << std::endl;
                    inventory.DisplayInventar();
                }
                break;
                case 3:
                    AfisareElementeOrdonate();
                break;
                case 4:
                    AfisareElementeRobot();
                break;
                case 5:
                    VindeElemente();
                break;
                default:
                    std::cout << "Optiune invalida!" << std::endl;
            }
        }
        while (option != 6);
    }

    void AdaugareElemente() {
        std::cout << "Puncte actuale: " << this->score << std::endl;

        std::cout << "Ce doresti sa adaugi?" << std::endl;
        std::cout << "1. Zid (cost 300 puncte)" << std::endl;
        std::cout << "2. Turn (cost 500 puncte)" << std::endl;
        std::cout << "3. Robot Aerian (cost 100 puncte)" << std::endl;
        std::cout << "4. Robot Terestru (const 50 puncte)" << std::endl;
        std::cout << "Optiunea ta: ";
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                if (this->score >= 300) {
                    auto zid = std::make_unique<Zid>(2, 2, 0.5);
                    std::cout << "Obiectul " << zid->GetElementType() << " (" << zid->GetInaltimeZid() << "m inaltime | "
                    << zid->GetLungimeZid() << "m lungime | " << zid->GetGrosimeZid() << "m grosime)"
                    << " a fost adaugat cu succes!" << std::endl;
                    inventory.Adauga(std::move(zid));
                    this->score -= 300;
                    std::cout << "Punctaj actual: " << this->score << std::endl;
                }
                else {
                    std::cout << "Nu s-a putut adauga obiectul ales!" << std::endl;
                }
            break;
            case 2:
                if (this->score >= 500) {
                    auto turn = std::make_unique<Turn>(1000);
                    std::cout << "Obiectul " << turn->GetElementType() << " (" << turn->GetPutereTurn() << "kw) a fost adaugat cu succes!" << std::endl;
                    inventory.Adauga(std::move(turn));
                    this->score -= 500;
                    std::cout << "Punctaj actual: " << this->score << std::endl;
                }
                else {
                    std::cout << "Nu s-a putut obiectul ales!" << std::endl;
                }
            break;
            case 3:
                if (this->score >= 100) {
                    auto robot_aerian = std::make_unique<RobotAerian>(100, 1, 100, 10);
                    std::cout << "Obiectul " << robot_aerian->GetElementType() << " a fost adaugat cu succes!!" << std::endl;
                    inventory.Adauga(std::move(robot_aerian));
                    this->score -= 100;
                    std::cout << "Punctaj actual: " << this->score << std::endl;
                }
                else {
                    std::cout << "Nu s-a putut obiectul ales!" << std::endl;
                }
            break;
            case 4:
                if (this->score >= 50) {
                    auto robot_terestru = std::make_unique<RobotTerestru>(100, 1, 100, 500);
                    std::cout << "Obiectul " << robot_terestru->GetElementType() << " a fost adaugat cu succes!!" << std::endl;
                    inventory.Adauga(std::move(robot_terestru));
                    this->score -= 50;
                    std::cout << "Punctaj actual: " << this->score << std::endl;
                }
                else {
                    std::cout << "Nu s-a putut obiectul ales!" << std::endl;
                }
            break;
            default:
                std::cout << "Optiune invalida!" << std::endl;
        }
        std::cout << "Inventarul tau actual: " << std::endl;
        inventory.DisplayInventar();
    }

    void UpgradeElemente() {
        std::cout << std::endl;
        std::cout << "Punctaj actual: " << this->score << std::endl;

        std::cout << "Inventarul tau actual: " << std::endl;
        inventory.DisplayInventar();

        int id_cautat;
        std::cout << "Introdu ID-ul elementului pe care vrei sa l upgradezi: ";
        std::cin >> id_cautat;

        bool found = false;

        for (auto& obiect : inventory.GetObiecte()) {
            if (obiect->GetID() == id_cautat) {
                found = true;

                if (auto zid = dynamic_cast<Zid*>(obiect.get())) {
                    int cost = 100 * zid->GetLungimeZid() * zid->GetInaltimeZid() * zid->GetGrosimeZid();
                    if (this->score >= cost) {
                        zid->SetInaltimeZid(zid->GetInaltimeZid() + 1);
                        zid->SetLungimeZid(zid->GetLungimeZid() + 1);
                        zid->SetGrosimeZid(zid->GetGrosimeZid() + 1);
                        this->score -= cost;
                        std::cout << "Upgrade reusit!" << std::endl;
                        std::cout << "Punctaj actual: " << this->score << std::endl;
                    } else std::cout << "Punctaj insuficient pentru upgrade!" << std::endl;
                }
                else if (auto turn = dynamic_cast<Turn*>(obiect.get())) {
                    int cost = 500 * turn->GetPutereTurn();
                    if (this->score >= cost) {
                        turn->SetPutereTurn(turn->GetPutereTurn() + 500);
                        this->score -= cost;
                        std::cout << "Upgrade reusit!" << std::endl;
                        std::cout << "Punctaj actual: " << this->score << std::endl;
                    } else std::cout << "Punctaj insuficient pentru upgrade!" << std::endl;
                }
                else if (auto robot = dynamic_cast<RobotAerian*>(obiect.get())) {
                    int cost = 50 * robot->GetRobotAerianAutonomie();
                    if (this->score >= cost) {
                        robot->SetRobotAerianAutonomie(robot->GetRobotAerianAutonomie() + 1);
                        robot->SetRobotAerianNivel(robot->GetRobotAerianNivel() + 1);
                        robot->SetRobotAerianDamage(robot->GetRobotAerianDamage() + 25);
                        this->score -= cost;
                        std::cout << "Upgrade reusit!" << std::endl;
                        std::cout << "Punctaj actual: " << this->score << std::endl;
                    } else std::cout << "Punctaj insuficient pentru upgrade!" << std::endl;
                }
                else if (auto robot1 = dynamic_cast<RobotTerestru*>(obiect.get())) {
                    int cost = 10 * robot1->GetRobotTerestuGloante();
                    if (this->score >= cost) {
                        robot1->SetRobotTerestuGloante(robot1->GetRobotTerestuGloante() + 100);
                        robot1->SetRobotTerestuNivel(robot1->GetRobotTerestuNivel()+ 1);
                        robot1->SetRobotTerestruDamage(robot1->GetRobotTerestuDamage() + 50);
                        if (robot1->GetRobotTerestuNivel() == 5) {
                            robot1->SetRobotTerestruScut(true);
                            robot1->SetRobotTerestruViata(robot1->GetRobotTerestuViata() + 50);
                        }
                        this->score -= cost;
                        std::cout << "Upgrade reusit!" << std::endl;
                        std::cout << "Punctaj actual: " << this->score << std::endl;
                    } else std::cout << "Punctaj insuficient pentru upgrade!" << std::endl;
                }
                break;
            }
        }
        if (!found) {
            std::cout << "Nu s-a putut gasi obiectul ales!" << std::endl;
        }
    }

    void AfisareElementeOrdonate() {
        std::vector<Element*> elemente;

        // Copiem pointerii brut din unique_ptr pentru sortare și afișare
        for (const auto& obiect : inventory.GetObiecte()) {
            elemente.push_back(obiect.get());
        }

        std::sort(elemente.begin(), elemente.end(), [](Element* a, Element* b) {
            return a->GetCostUpgrade() < b->GetCostUpgrade();
        });

        std::cout << "\nElementele ordonate crescator dupa costul de upgrade:\n";
        for (const auto& elem : elemente) {
            elem->DisplayElement();
            std::cout << "Cost Upgrade: " << elem->GetCostUpgrade() << std::endl;
            std::cout << "-----------------------------\n";
        }
    }

    void AfisareElementeRobot() {
        std::cout << "==== ELEMENTE DE TIP ROBOT =====" << std::endl;

        const auto& obiecte = inventory.GetObiecte();

        for (const auto& obiect : obiecte) {
            // daca obiectul este de tip robot
            if (dynamic_cast<const Robot*>(obiect.get())) {
                obiect->DisplayElement();

                if (auto robot_aer = dynamic_cast<RobotAerian*>(obiect.get())) {
                    robot_aer->DisplayRobot(std::cout);
                }
                else if (auto robot = dynamic_cast<RobotTerestru*>(obiect.get())) {
                    robot->DisplayRobot(std::cout);
                }

                std::cout << std::endl;
            }
        }
    }

    void VindeElemente() {
        std::cout << std::endl;
        std::cout << "Punctaj actual: " << this->score << std::endl;

        std::cout << "Inventarul tau actual: " << std::endl;
        inventory.DisplayInventar();

        int id_cautat;
        std::cout << "Introdu ID-ul elementului pe care vrei sa l vinzi: ";
        std::cin >> id_cautat;

        if (inventory.StergeElementID(id_cautat)) {

            std::cout << "Elementul cu ID-ul " << id_cautat << " a fost vandut cu succes." << std::endl;
            this->score += 500;
            std::cout << "Punctaj actual: " << this->score << std::endl;

        } else {
            std::cout << "Elementul cu ID-ul " << id_cautat << " nu a fost gasit." << std::endl;
        }
    }
};

int main() {
    Game game;
    game.Meniu();
    return 0;
}