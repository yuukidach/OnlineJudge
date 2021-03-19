class ParkingSystem {
private:
    int big, medium, small;
public:
    ParkingSystem(int big, int medium, int small) {
        this->big = big;
        this->medium = medium;
        this->small = small;
    }
    
    bool addCar(int carType) {
        bool hasPos = false;
        if (carType == 3) {
            hasPos = small;
            small = max(0, small-1);
        } else if (carType == 2) {
            hasPos = medium;
            medium = max(0, medium-1);
        } else {
            hasPos = big;
            big = max(0, big-1);
        }
        return hasPos;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */