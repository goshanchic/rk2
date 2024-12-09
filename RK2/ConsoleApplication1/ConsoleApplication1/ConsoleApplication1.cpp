#include <iostream>
#include <string>
#include <list>
#include <memory> 

using namespace std;


class Vehicle {
protected:
    string make;  
    string model;  

public:
    Vehicle(const string& make, const string& model)
        : make(make), model(model) {
    }

    virtual ~Vehicle() = default; 

    virtual void display() const {
        cout << "Vehicle: " << make << " " << model << endl;
    }
};

class Car : public Vehicle {
private:
    int doors; 

public:
    Car(const string& make, const string& model, int doors)
        : Vehicle(make, model), doors(doors) {
    }

    void display() const  {                            
        cout << "Car: " << make << " " << model
            << ", Doors: " << doors << endl;
    }
};

class Motorcycle : public Vehicle {
private:
    string type; 

public:
    Motorcycle(const string& make, const string& model, const string& type)
        : Vehicle(make, model), type(type) {
    }

    void display() const override {
        cout << "Motorcycle: " << make << " " << model
            << ", Type: " << type << endl;
    }
};

// Функция для изменения хар транспортного средства ( в данном случае просто вывод)
void modifyVehicle(Vehicle* vehicle) {
    cout << "Modifying vehicle: ";
    vehicle->display();
}

int main() {
    setlocale(LC_ALL, "Russian");
        // Контейнер для хранения указателей на объекты Vehicle
    list<shared_ptr<Vehicle>> vehicles;

    // Добав объекты
    vehicles.push_back(make_shared<Car>("Mercedes", "S-class", 4));
    vehicles.push_back(make_shared<Car>("BMW", "M5 F90 CS", 4));
    vehicles.push_back(make_shared<Motorcycle>("Yamaha", "R1", "Sport"));
    vehicles.push_back(make_shared<Motorcycle>("Harley-Davidson", "Cruiser", "Cruiser"));

    // Вывод инфо о транспорте
    cout << "Vehicles in the list:" << endl;
    for (const auto& vehicle : vehicles) {
        vehicle->display();
    }

    // Измен хар каждого транспорте
    cout << "\nModifying vehicles:" << endl;
    for (const auto& vehicle : vehicles) {
        modifyVehicle(vehicle.get());
    }

    return 0;
}
