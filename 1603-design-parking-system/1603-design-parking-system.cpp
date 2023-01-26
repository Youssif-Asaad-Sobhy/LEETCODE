class ParkingSystem {
public:
    int bg,md,sm;
    ParkingSystem(int big, int medium, int small) {
        bg=big,md=medium,sm=small;
    }
    
    bool addCar(int carType) {
        if(carType==1)return bg-->0?1:0;
        if(carType==2)return md-->0?1:0;
        if(carType==3)return sm-->0?1:0;
        return 0;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */